#include<stdio.h>
#define max 30
int main(){
    int n,p[max],bt[max],wt[max],tat[max],temp;
    float awt=0,atat=0;
    printf("Enter number of processes: ");
    scanf("%d" ,&n);
    printf("Enter process names: ");
    for(int i=0;i<n;i++) scanf("%d" ,&p[i]);
    printf("Enter burst times: ");
    for(int i=0;i<n;i++) scanf("%d" ,&bt[i]);

     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;


                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
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
    printf("\nProcess\tBurst Time\tWaiting\tTurnaround\n\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t\n" ,p[i],bt[i],wt[i],tat[i]);
    }
    
    printf("Avg waiting time: %.2f\n",(awt/n));
    printf("Avg Turn around time: %.2f",(atat/n));
}