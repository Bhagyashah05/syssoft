/*
Name: 27c.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// write a program to execute ls -Rl by the following system calls
// c. execle


#include <stdio.h>
#include <unistd.h>
int main(int argc,char *argv[],char *env[])
{
    char *path = "/bin/ls";
    execle(path, path, "-Rl" ,"27cdemo",NULL, env);
    return 0;
}

// output 
// ./a.out 
// -rw-rw-r-- 1 bhagyashah05 bhagyashah05 0 Aug 30 14:33 27cdemo