#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], avail[10], need[10][10];
    int work[10], finish[10] = {0};
    int request[10], p_id;
    int safeSeq[10], index = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Enter process ID for resource request (0-%d): ", n - 1);
    scanf("%d", &p_id);

    printf("Enter the request for resources by process %d:\n", p_id);
    for (j = 0; j < m; j++) {
        scanf("%d", &request[j]);
    }

    for (j = 0; j < m; j++) {
        if (request[j] > need[p_id][j]) {
            printf("Error: Request exceeds maximum claim.\n");
            return 1;
        }
        if (request[j] > avail[j]) {
            printf("Resources are not available. Process must wait.\n");
            return 1;
        }
    }

    for (j = 0; j < m; j++) {
        avail[j] -= request[j];
        alloc[p_id][j] += request[j];
        need[p_id][j] -= request[j];
    }

    for (j = 0; j < m; j++) {
        work[j] = avail[j];
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate) {
                    for (j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }
                    safeSeq[index++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    int safe = 1;
    for (i = 0; i < n; i++) {
        if (!finish[i]) {
            safe = 0;
            break;
        }
    }

    if (safe) {
        printf("Request granted. System is in a safe state.\nSafe sequence: ");
        for (i = 0; i < n; i++) {
            printf("%d ", safeSeq[i]);
        }
    } else {
        printf("Request denied. System would enter an unsafe state.\n");
        for (j = 0; j < m; j++) {
            avail[j] += request[j];
            alloc[p_id][j] -= request[j];
            need[p_id][j] += request[j];
        }
    }

    return 0;
}
