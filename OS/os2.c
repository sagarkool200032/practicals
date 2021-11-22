// fork() System Call by distinguishing parent from the child
#include <stdio.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h>

#define MAX_COUNT 10 
void ChildProcess(void); 
void ParentProcess(void); 
void main(void)
{
    pid_t pid; 
    pid = fork(); 
    
    if (pid == 0)
        ChildProcess(); 
    else
        ParentProcess();
}

void ChildProcess(void)
{ 
    int i;

    for(i=1;i<=MAX_COUNT;i++)
        printf("This line is from child (%d), value=%d\n", getpid(), i); 
    
    printf("***child process is done***");
}

void ParentProcess(void)
{
    int i;

    for (i=1; i<=MAX_COUNT; i++)
        printf("This line is from parent(%d) value = %d\n",getpid(), i); 
    
    printf("***Parent process is done***");
}
