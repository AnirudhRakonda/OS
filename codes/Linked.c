#include<stdio.h>
#define max 30

int main() {
    int n, start[max], index[max][max], size[max];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter file%d start: ", i + 1);
        scanf("%d", &start[i]);

        printf("Enter size of file%d: ", i + 1);
        scanf("%d", &size[i]);

        printf("Enter blocks of file%d: ", i + 1);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &index[i][j]); 
        }
    }

    printf("\nFile\tStart\tSize\tOccupied Blocks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t", i + 1, start[i], size[i]);

        printf("%d , " ,start[i]);
        for (int j = 0; j < size[i]; j++) {
            printf("%d , ", index[i][j]);
        }
        printf("NULL\n"); 
    }

    return 0;
}
