/*
Name: 20.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// Find out the priority of your running program. Modify the priority with nice command.
#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
    int priority;
    long long int pid=getpid();
    priority=getpriority(PRIO_PROCESS,pid);
    printf("priority of process is %d\n",priority);

    if (setpriority(PRIO_PROCESS, pid, 10) == -1) {
        perror("setpriority");
        return 1;
    }
    priority = getpriority(PRIO_PROCESS, pid);
    printf("new priority of process is %d\n",priority);


    return 0;
}

// output 
// ./a.out 
// priority of process is 0
// new priority of process is 10