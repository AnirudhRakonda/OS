#include<stdio.h>
#define max 10

int main() {
    int n, start[max], size[max];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter size of file%d: ", i + 1);
        scanf("%d", &size[i]);
        printf("Enter start of file%d: ", i + 1);
        scanf("%d", &start[i]);
    }

    printf("\nFile No\tStart\tSize\tBlocks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t", i + 1, start[i], size[i]);
        
        for (int j = start[i]; j < size[i] + start[i]; j++) {
            printf("%d ", j); 
        }
        printf("\n"); 
    }

    return 0;
}
