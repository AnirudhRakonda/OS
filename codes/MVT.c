#include<stdio.h>
int main(){
    int size,part,os,part_size[100];
    printf("enter mem size: ");
    scanf("%d" ,&size);
    printf("enter os size: ");
    scanf("%d" ,&os);
    size-=os;
    printf("enter number of partitions: ");
    scanf("%d" ,&part);
    for(int i=0;i<part;i++){
        printf("enter size of process %d" ,i+1);
        scanf("%d" ,&part_size[i]);
    }
    for(int i=0;i<part;i++){
        if(size>=part_size[i]){
            printf("Mem allocated for process%d\n" ,i+1);
            size -= part_size[i];
        }
        else{
            printf("Mem cant allocat for process%d\n" ,i+1);
        }
    }
    
}