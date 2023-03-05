#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    pid_t pid_R, pid_T, pid_W, pid_V, pid_S, pid_L, pid_P;
    pid_R = getpid();  
    
    printf("Proceso R: pid=%d, parent=%d\n", pid_R, getppid());
    if ((pid_T = fork()) == 0) 
    {
        printf("Proceso T: pid=%d, parent=%d\n", getpid(), getppid());
        if ((pid_V = fork()) == 0) 
        {
            printf("Proceso V: pid=%d, parent=%d\n", getpid(), getppid());
            exit(0);
        }
        exit(0);
    }

    if ((pid_W = fork()) == 0) 
    {
        printf("Proceso W: pid=%d, parent=%d\n", getpid(), getppid());
        if ((pid_S = fork()) == 0) 
        {
            printf("Proceso S: pid=%d, parent=%d\n", getpid(), getppid());
            exit(0);
        }
        if ((pid_L = fork()) == 0) 
        {
            printf("Proceso L: pid=%d, parent=%d\n", getpid(), getppid());
            if ((pid_P = fork()) == 0) 
            {
                printf("Proceso P: pid=%d, parent=%d\n", getpid(), getppid());
                exit(0);
            }
            exit(0);
        }
        exit(0);
    }
    return 0;
}
