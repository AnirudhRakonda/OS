#include<stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], avail[10], need[10][10], work[10];
    int finish[10] = {0};
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
        printf("System is in a safe state.\nSafe sequence: ");
        for (i = 0; i < n; i++) {
            printf("%d ", safeSeq[i]);
        }
    } else {
        printf("System is not in a safe state.");
    }

    return 0;
}
