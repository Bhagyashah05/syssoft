/*
Name: 23.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
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

// output 
// ./a.out 
// inside child pid= 5120
// parent id= 5119


// inside parent pid= 5119
// child pid= 5120