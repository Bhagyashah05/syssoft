/*
Name: 26a.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// Write a program to execute an executable program.
// a. use some executable program

#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    execv(argv[1], &argv[1]);
    return 0;
}

// output 
// ./a.out 26ademo.out
// hello