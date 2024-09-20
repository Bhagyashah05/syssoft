// Bhagya Shah 
// Mt2024135

// Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
// use sigaction system call
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("SIGINT received, but ignored.\n");
}

int main() {
    struct sigaction sa;

    sa.sa_handler = SIG_IGN;  
    sigemptyset(&sa.sa_mask); 
    sa.sa_flags = 0;          

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is now ignored. Press Ctrl+C to test.\n");

    sleep(5);

    sa.sa_handler = SIG_DFL;  
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT action reset to default. You can press Ctrl+C now.\n");

    while (1) {
        pause();  
    }

    return 0;
}

// output 
// ./a.out 
// SIGINT is now ignored. Press Ctrl+C to test.
// ^CSIGINT action reset to default. You can press Ctrl+C now.
// ^C