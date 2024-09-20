// Bhagya shah 
// MT2024135

// Write a simple program to send some data from parent to the child process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    pid_t pid;
    char buffer[100]; 
    const char *message = "Hello from the parent process!";

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(pipefd[0]); 
        write(pipefd[1], message, strlen(message) + 1); 
        close(pipefd[1]);
        printf("Parent sent: %s\n", message);
    } else {
        close(pipefd[1]); 
        read(pipefd[0], buffer, sizeof(buffer)); 
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    }

    return 0;
}

// ./a.out 
// Parent sent: Hello from the parent process!
// Child received: Hello from the parent process!
