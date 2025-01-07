#include<stdio.h>
#define max 100

int main() {
    int size, os, part;
    int block_size;
    int pi[max], ps[max];

    printf("Enter the size of mem: ");
    scanf("%d", &size);
    printf("Enter the size of os: ");
    scanf("%d", &os);

    size -= os;
    printf("Enter no. of partitions: ");
    scanf("%d", &part);
    block_size = size / part;

    for (int i = 0; i < part; i++) {
        printf("Enter process id and size: ");
        scanf("%d %d", &pi[i], &ps[i]);
        if (ps[i] <= block_size) {
            printf("\nProcess %d is allocated\n", pi[i]);
        } else {
            printf("\nProcess %d cannot be allocated\n", pi[i]);
        }
    }
}
