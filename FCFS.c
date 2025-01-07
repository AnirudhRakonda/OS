#include<stdio.h>
#define max 30
int main(){
    int n,bt[max],at[max],wt[max],tat[max],temp[max];
    float awt,atat;

    printf("Enter number of processes: ");
    scanf("%d" ,&n);
    printf("Enter arrival times : ");
    for(int i=0;i<n;i++){
        scanf("%d" ,&at[i]);
    }
    printf("Enter burst times : ");
    for(int i=0;i<n;i++){
        scanf("%d" ,&bt[i]);
    }
    temp[0] = 0;
    printf("\nS.no.\tWaiting\tTurnaround\t\n\n");
    for(int i=0;i<n;i++){
        
        temp[i+1] = (temp[i]>at[i]) ? (temp[i]+bt[i]) : (at[i]+bt[i]);
        wt[i] = (temp[i]>at[i]) ? (temp[i]-at[i]) : 0;
        tat[i] = wt[i]+bt[i];

        awt+=wt[i];
        atat+=at[i];
        printf("%d\t %d\t %d\n" ,i+1,wt[i],tat[i]);
    }
    printf("Avg waiting time: %f\n",(awt/n));
    printf("Avg Turn around time: %f",(atat/n));
}