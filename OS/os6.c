// Round Robin CPU Scheduling 
#include <string.h>
#include <stdio.h>

void main() {
    int exec[10],rt[10],wt[10], tt[10];
    int n,i,qt,t=0,done;
    printf("Enter the numberr of processes: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        printf("Enter the execution time for Process %d: ", i+1);
        scanf("%d",&exec[i]);
    }
    printf("Enter the quantum time : ");
    scanf("%d",&qt);

    for(i = 0; i < n; i++){
        rt[i] = exec[i];
    }

    while (1)
    {
        done = 1;
        for (int i = 0 ; i < n; i++)
        {
            if (rt[i] > 0)
            {
                done = 0; 
                if (rt[i] > qt)
                {
                    t += qt;
                    rt[i] -= qt;
                }
                else
                {
                    t = t + rt[i];
                    wt[i] = t - exec[i];
                    rt[i] = 0;
                }
            }
        }
        if (done == 1)
          break;
    }

    for(i = 0; i < n; i++){
        tt[i] = exec[i]+ wt[i];
    }

    printf("Process\t\tExecution Time\t\tWaiting time\t\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1, exec[i],wt[i],tt[i]);
    }

printf("Gantt Chart:\n|");
    for(i=0; i<n; i++){
        printf("[%d] Process %d [%d]",wt[i], i+1, tt[i]);
        for(int j=0;j<6; j++){ 
            printf("*");
        }
        printf("|");
    }

}
