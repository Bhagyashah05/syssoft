/*
Name: 22.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// Write a program, open a file, call fork, and then write to the file by both the child as well as the
// parent processes. Check output of the file.

#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t q;
    q = fork();
    int fd = open(argv[1], O_WRONLY| O_CREAT, S_IRWXU);
    if(q==0){
    char buf[50];

    sprintf(buf, "written by child %d \n", getpid());
    write(fd, buf, strlen(buf));     
    }
    else if(q>0){
    char buf[50];
    sprintf(buf, "written by parent %d \n", getpid());
    write(fd, buf, strlen(buf));
    wait(NULL);
    }
    close(fd);
    return 0;
}

// output 
// ./a.out 22.txt 
// bhagyashah05@Bhagya-Shah:~/syssoft$ cat 22.txt 
// written by child 5010 


// ritten by child 14315