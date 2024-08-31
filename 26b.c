/*
Name: 26b.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// pass some input to an executable program. (for example execute an executable of $./a.out name)

#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    char *path=argv[1];
    argv++;
    execv(path, argv);
    return 0;
}

// output 
//  ./a.out 26a.out 26ademo.out
// hello