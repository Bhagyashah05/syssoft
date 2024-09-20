// Bhagya Shah 
// MT2024135

// Write a program to send and receive data from parent to child vice versa. Use two way
// communication.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MSG_SIZE 100

int main() {
    int pipe_parent_to_child[2], pipe_child_to_parent[2];
    pid_t pid;
    char parent_message[MSG_SIZE] = "Hello from parent";
    char child_message[MSG_SIZE] = "Hello from child";
    char buffer[MSG_SIZE];

    if (pipe(pipe_parent_to_child) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipe_child_to_parent) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(pipe_parent_to_child[0]);
        close(pipe_child_to_parent[1]);

        write(pipe_parent_to_child[1], parent_message, strlen(parent_message) + 1);
        printf("Parent: Sent message to child: %s\n", parent_message);

        read(pipe_child_to_parent[0], buffer, MSG_SIZE);
        printf("Parent: Received message from child: %s\n", buffer);

        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);
    } else {
        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);

        read(pipe_parent_to_child[0], buffer, MSG_SIZE);
        printf("Child: Received message from parent: %s\n", buffer);

        write(pipe_child_to_parent[1], child_message, strlen(child_message) + 1);
        printf("Child: Sent message to parent: %s\n", child_message);

        close(pipe_parent_to_child[0]);
        close(pipe_child_to_parent[1]);
    }

    return 0;
}

// output 
// ./a.out 
// Parent: Sent message to child: Hello from parent
// Child: Received message from parent: Hello from parent
// Child: Sent message to parent: Hello from child
// Parent: Received message from child: Hello from child