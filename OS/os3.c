// FCFS CPU Scheduling 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
    int wt[10], exec[10],tt[10],n,i,sum=0,j; 
    printf("enter the number of proccesses:\n");
    scanf("%d", &n);
    printf("enter the execution time for each process:\n");
    for(i=0; i<n; i++){
        printf("Execution time for P%d: ", i+1);
        scanf("%d", &exec[i]);
    }
    wt[0]=0;

    for(i=1;i<n;i++){
        sum= sum+ exec[i-1];
        wt[i]=sum-wt[0];
    }
    sum=0;
    for(i=0; i<n; i++){
        sum= sum+ exec[i];
        tt[i]=sum;
    }
    
    printf("Process\t\tExecution Time\t\tWaiting time\t\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1, exec[i],wt[i],tt[i]);
    }

    printf("Gantt Chart:\n|");
    for(i=0; i<n; i++){
        printf("Process %d [%d]", i+1, exec[i]);
        for(j=0;j<exec[i]; j++){ 
            printf("*");
        }
        printf("|");
    }

    printf("\n");
    sum=0;
    for(i=0; i<n; i++){
        sum=sum+wt[i];
    }

    printf("Average waiting time: %d \n ",(sum/n));
    sum=0;
    for(i=0; i<n; i++){
        sum=sum+tt[i];
    }    printf("Average turnaround time: %d \n",(sum/n));
}

