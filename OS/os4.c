//  SJF CPU Scheduling 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct process{
    int pid;
    int exec;
    int wt;
    int tt;
}p[10],temp;

void main(){
    int n,i,j,sum;
    printf("Enter ther number of processes: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter the execution time for process %d:  ", i+1);
        scanf("%d", &p[i].exec);
        p[i].pid = i+1;
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if((p[i].exec > p[j].exec )|| (p[i].exec == p[j].exec && p[i].pid > p[j].pid)){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    p[0].wt=0;
    sum=0;
    for(i=1;i<n;i++){
        sum= sum+ p[i-1].exec;
        p[i].wt=sum-p[0].wt;
    }

    sum=0;
    
    for(i=0; i<n; i++){
        sum= sum+ p[i].exec;
        p[i].tt=sum;
    }
    
    printf("Process\t\tExecution Time\t\tWaiting time\t\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].pid, p[i].exec, p[i].wt, p[i].tt);
    }

    printf("Gantt Chart:\n|");
    for(i=0; i<n; i++){
        printf("Process %d [%d]", p[i].pid, p[i].exec);
        for(j=0;j<p[i].exec; j++){ 
            printf("*");
        }
        printf("|");
    }

    printf("\n");
    sum=0;
    for(i=0; i<n; i++){
        sum=sum+p[i].wt;
    }

    printf("Average waiting time: %d \n ",(sum/n));
    sum=0;
    for(i=0; i<n; i++){
        sum=sum+p[i].tt;
    }
    printf("Average turnaround time: %d \n",(sum/n));
}
