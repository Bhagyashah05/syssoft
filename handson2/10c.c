// Bhagya Shah 
// MT2024135

/*
Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE: Floating-point exception (signal %d)\n", signum);
    exit(EXIT_FAILURE);
}

int main() {
    int status;
    struct sigaction act;

    act.sa_handler = handle_sigfpe;
    sigemptyset(&act.sa_mask);  // Initialize signal set to empty
    act.sa_flags = 0;
    status = sigaction(SIGFPE, &act, NULL);
    if (status == -1) {
        perror("Error while assigning SIGFPE handler");
        return EXIT_FAILURE;
    }

    int zero = 0;
    int result = 1 / zero;  // This will cause SIGFPE

    return 0;
}
