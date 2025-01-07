#include<stdio.h>
#define max 10
int main(){
    int n,sq=0,t,bt[max],rem_bt[max],qt,tat[max],wt[max],c;
    float awt=0,atat=0;
    printf("Enter number of processes: ");
    scanf("%d" ,&n);
    printf("enter burst times: ");
    for(int i=0;i<n;i++){
        scanf("%d" ,&bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter quantum time: ");
    scanf("%d" ,&qt);

        c=0;
    while (1){
        t= qt;
        for(int i=0;i<n;i++){
            if(rem_bt[i] == 0){
                c++;
                continue;
            }
            if(rem_bt[i] > qt)
                rem_bt[i] -= qt;
            else{
                t = rem_bt[i];
                rem_bt[i] =0;
            }
            sq += t;
            tat[i] = sq;
        }
        if(c==n) break;
    }
    printf("\nProcess\tBurst Time\tTAT\tWT");
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i]; 
        atat += tat[i];
        awt += wt[i];
        printf("\n%d\t%d\t\t%d\t%d", i + 1, bt[i], tat[i], wt[i]);
    }

    
    atat /= n;
    awt /= n;
    printf("\n\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);
    
}