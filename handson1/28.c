/*
Name: 28.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 30 Aug 2024
*/

// Description:
// Write a program to get maximum and minimum real time priority.


#include <stdio.h>
#include <sched.h>
int main()
{
    printf("Maxi priority and Mini priority of SCHED_FIFO scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));
    printf("Maxi priority and Mini priority of SCHED_RR scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
    printf("Maxi priority and Mini priority of SCHED_OTHER scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_OTHER), sched_get_priority_min(SCHED_OTHER));
    return 0;
}

// output 
// ./a.out 
// Maxi priority and Mini priority of SCHED_FIFO scheduling is 99 and 1 respectively
// Maxi priority and Mini priority of SCHED_RR scheduling is 99 and 1 respectively
// Maxi priority and Mini priority of SCHED_OTHER scheduling is 0 and 0 respectively