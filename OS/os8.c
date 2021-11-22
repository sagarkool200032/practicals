// Best Fit 
#include<stdio.h>
 
void main()
{
 	int fragment[20],b[20],p[20],i,j,nb,np,temp,low=9999;
	static int barray[20],parray[20];
 	printf("Enter the number of processes:");
	scanf("%d",&np);
 	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);

 	printf("\nEnter the size of the blocks:-\n");
	for(i=1;i<=nb;i++)
    {
	    printf("Block no.%d:",i);
        scanf("%d",&b[i]);
    }
 	printf("\nEnter the size of the processes :-\n");
	for(i=1;i<=np;i++)
    {
        printf("Process no.%d:",i);
        scanf("%d",&p[i]);
    }
	for(i=1;i<=np;i++)
	{
		for(j=1;j<=nb;j++)
		{

			if(barray[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
					if(low>temp)
					{
						parray[i]=j;
						low=temp;
					}
			}
		}
		fragment[i]=low;
		barray[parray[i]]=1;
		low=10000;
	}
printf("\nProcess \tProcess Size\tHole Space");
	for(i=1;i<=np && parray[i]!=0;i++)
		printf("\n%d\t\t%d\t\t%d\t",i,p[i],parray[i]);

printf("\nHole \t\tHole Size\tRemaining");
	for(i=1;i<=nb;i++)
		printf("\n%d\t\t%d\t\t%d",i,b[parray[i]],fragment[i]);
}