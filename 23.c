// Write a program to create a Zombie state of the running program

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int fd;
    fd = fork();
    if (fd == 0)
    {
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid());
    }
    else
    {

        sleep(10);
        printf("inside parent pid= %d\n", getpid());
        printf("child pid= %d\n", fd);
    }
    return 0;
}