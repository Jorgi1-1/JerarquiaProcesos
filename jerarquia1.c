#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd, fd2, n, num1, num2, res;
    pid_t pidn, pidm;
    
    pidn = fork();
    if(pidn == 0)
    {
        int arr[]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        fd = creat("N.dat", 777);
        n = write(fd, arr, sizeof(arr));
        close(fd);
    }

    pidm = fork();
    if(pidm == 0)
        {
            int arr2[]={2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
            fd2 = creat("M.dat", 777);
            n = write(fd2, arr2, sizeof(arr2));
            close(fd2);
        }

    if(pidm && pidn > 0)
        {   
            fd=open("N.dat", O_RDONLY, 777);
            fd2=open("M.dat", O_RDONLY, 777);
            read(fd, &num1, sizeof(num1));
            do
            {
                printf("%d + ", num1);
                read(fd2, &num2, sizeof(num2));
                printf("%d =",num2);
                res = num1 + num2;
                printf(" %d\n",res);
            }
            while(read(fd, &num1, sizeof(int)) != 0);
        }

    close(fd);
    close(fd2);
    return(0);  
}
