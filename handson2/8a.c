// Bhagya Shah 
// MT2024135
// Write a separate program using signal system call to catch the following signals.
//  a. SIGSEGV
//  b. SIGINT
//  c. SIGFPE
//  d. SIGALRM (use alarm system call)
//  e. SIGALRM (use setitimer system call)
//  f. SIGVTALRM (use setitimer system call)
//  g. SIGPROF (use setitimer system call)

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signal) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler); 

    int *p = NULL;
    *p = 10;

    return 0;
}

// output 
//  ./a.out 
// Caught SIGSEGV: Segmentation Fault
