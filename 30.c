/*
Name: 30.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// Write a program to run a script at a specific time using a Daemon process.

// Pipariya Darshitkumar
// MT2022035

/*
    Write a program to run a script at a specific time using a Daemon process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char *argv[])
{
    time_t curr, dead;
    struct tm *limit;

    time(&curr); 
    limit = localtime(&curr);

    limit->tm_hour = atoi(argv[1]);
    limit->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
    limit->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

    dead = mktime(limit); 

    int cid = fork();
    if (cid == 0)
    {
        setsid();
        do
        {
            time(&curr); 
        } while (difftime(dead, curr) > 0);
        system("echo Current user=$USER");
    }
    else
    {
        exit(0);
    }
}

// output:
// ./a.out 0 0 10
// Current user=bhagyashah05