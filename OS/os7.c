// First Fit
#include<stdio.h>
#include<conio.h>

void main(){
    int pr[10],size[10], i,j,n,m, hole[10], or_size[10];
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter the memory space for process %d ", i+1);
        scanf("%d", &pr[i]);
    }

    printf("Enter the number of partitions:\n");
    scanf("%d", &m);
    for(i=0;i<m;i++){
        printf("Enter the memory space for partition %d ", i+1);
        scanf("%d", &size[i]);
    }
    for(i=0;i<m;i++){
        or_size[i] = size[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(size[j]>=pr[i]){
                size[j] = size[j]-pr[i];
                hole[i] = j+1;
                break;
            }
            else
                hole[i]= -1;
        }
    }
    printf("Process\t\tMemory Space\t\tHole Space\n");
    for(i=0; i<n; i++)
    {
        if(hole[i]==-1)
            printf("P%d\t\t%d\t\t\tNot Allocated\n",i+1, pr[i]);
        else
            printf("P%d\t\t%d\t\t\tH%d\n",i+1, pr[i],hole[i]);
    }
    printf("Process\t\tOriginal Memory Space\t\tRemaining Memory Space\n");    
    for(i=0; i<n; i++){
        printf("H%d\t\t%d\t\t\t\t\t%d\n",i+1, or_size[i],size[i]);
    }
}