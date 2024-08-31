/*
Name: 24.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// Write a program to create an orphan process.

#include<stdio.h>
#include<unistd.h>

int main(){
    int pid=fork();
    if(pid==0){
        sleep(20);
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid());
    }else{
        sleep(10);
        printf("inside parent pid= %d\n", getpid());
        printf("child pid= %d\n", pid);
    }
    return 0;
}

// output 
// ./a.out 
// inside parent pid= 5250
// child pid= 5251
// bhagyashah05@Bhagya-Shah:~/syssoft$ inside child pid= 5251
// parent id= 1485
