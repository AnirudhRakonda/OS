#include<stdio.h>
#define max 30
int main(){
    int n,temp,bt[max],pr[max],tat[max],wt[max],pos;
    float awt=0,atat=0;
    printf("Enter number of processes: ");
    scanf("%d" ,&n);
    printf("Enter burst times: ");
    for(int i=0;i<n;i++){
        scanf("%d" ,&bt[i]);
    }
    printf("Enter priorities: ");
    for(int i=0;i<n;i++){
        scanf("%d" ,&pr[i]);
    }
    for(int i=0;i<n;i++){
        pos = i;
        for(int j=i+1;j<n;j++){
            if(pr[j] < pr[pos]){
                pos = j;
            }
            temp = pr[i];
            pr[i] = pr[pos];
            pr[pos] = temp;


            temp = bt[i];
            bt[i] = bt[pos];
            bt[pos] = temp;

        }
    }
    wt[0] = 0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1]+bt[i-1];
    }
    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    printf("\nProcess\tpriority\tburst\tWaiting\tTurnaround\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t%d\t%d\t\n" ,i+1,pr[i],bt[i],wt[i],tat[i]);
    }
    
    printf("Avg waiting time: %.2f\n",(awt/n));
    printf("Avg Turn around time: %.2f",(atat/n));

}