// Bhagya Shah 
// MT2024135

// Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
// signal - Use signal system call.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void reset_sigint(int signum) {
    printf("SIGINT ignored, now resetting to default.\n");
    signal(SIGINT, SIG_DFL);  
}

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT signal is being ignored. Press Ctrl+C (no effect for 5 seconds).\n");

    sleep(5);

    signal(SIGINT, reset_sigint);
    printf("SIGINT handler is now set to reset the default behavior. Press Ctrl+C again to restore default behavior.\n");

    while (1) {
        printf("Waiting for SIGINT...\n");
        sleep(2);  
    }

    return 0;
}

// output 
// ./a.out 
// SIGINT signal is being ignored. Press Ctrl+C (no effect for 5 seconds).
// ^C^C^CSIGINT handler is now set to reset the default behavior. Press Ctrl+C again to restore default behavior.
// Waiting for SIGINT...
// ^CSIGINT ignored, now resetting to default.
// Waiting for SIGINT...
// ^C