// Bhagya Shah 
// MT2024135 

// Write a program to find out total number of directories on the pwd.
// execute ls -l | grep ^d | wc ? Use only dup2.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_ls_grep[2];
    int pipe_grep_wc[2];
    pid_t pid1, pid2;

    if (pipe(pipe_ls_grep) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipe_grep_wc) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();

    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        close(pipe_ls_grep[0]);  
        dup2(pipe_ls_grep[1], STDOUT_FILENO);
        close(pipe_ls_grep[1]);  

        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed for ls");
        exit(EXIT_FAILURE);
    } else {
        pid2 = fork();

        if (pid2 < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) {
            close(pipe_ls_grep[1]);
            dup2(pipe_ls_grep[0], STDIN_FILENO); 
            close(pipe_ls_grep[0]);  

            close(pipe_grep_wc[0]); 
            dup2(pipe_grep_wc[1], STDOUT_FILENO); // Redirect stdout to write end of second pipe
            close(pipe_grep_wc[1]);  // Close original write end of second pipe

            execlp("grep", "grep", "^d", NULL);
            perror("execlp failed for grep");
            exit(EXIT_FAILURE);
        } else {
            close(pipe_ls_grep[0]);  // Close unused pipe ends
            close(pipe_ls_grep[1]);

            close(pipe_grep_wc[1]);  // Close write end of second pipe
            dup2(pipe_grep_wc[0], STDIN_FILENO);  // Redirect stdin to read end of second pipe
            close(pipe_grep_wc[0]);  // Close original read end of second pipe

            execlp("wc", "wc", "-l", NULL);
            perror("execlp failed for wc");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

// output 
// /a.out 
// 0

