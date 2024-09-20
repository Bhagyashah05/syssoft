// Bhagya Shah 
// MT2024135

// Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
// the parent process from the child process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        printf("Parent process PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);

        sleep(2);

        
        printf("Parent process (PID: %d) is about to be killed by the child process.\n", getpid());
        kill(getpid(), SIGKILL); 

    } else {
        printf("Child process (PID: %d) is going to wait before killing the parent.\n", getpid());
        
        sleep(1);

        printf("Child process (PID: %d) is sending SIGKILL to parent (PID: %d).\n", getpid(), getppid());
        kill(getppid(), SIGKILL); 

        printf("Child process (PID: %d) is now an orphan (if it reaches here).\n", getpid());

        while (1) {
            sleep(1); 
        }
    }

    return 0;
}

// output 
// ./a.out 
// \Parent process PID: 4607
// Child process PID: 4608
// Child process (PID: 4608) is going to wait before killing the parent.
// Child process (PID: 4608) is sending SIGKILL to parent (PID: 4607).
// Child process (PID: 4608) is now an orphan (if it reaches here).
// Killed