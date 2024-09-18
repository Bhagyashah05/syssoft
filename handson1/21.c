/*
Name: 21.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// Write a program, call fork and print the parent and child process id.

#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("parent pid = %d\n", getpid());
    int fid = fork();
    if(fid) printf("child pid = %d\n", fid);
    return 0;
}

// output 
//  ./a.out 
// parent pid = 4588
// child pid = 4589