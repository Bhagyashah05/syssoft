// Bhagya Shah 
// MT2024135

// Write a program to execute ls -l | wc.
// a. use dup
// b. use dup2
// c. use fcntl


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void main()
{
    int pipefd[2];
    pid_t cid;

    if (pipe(pipefd) == -1)
    {
        printf("ERROR");
    }
    else
    {
        cid = fork();
        if (cid == 0)
        {
            close(0);
            fcntl(pipefd[0], F_DUPFD, 0);
            close(pipefd[1]); // closing unused pipe writing end
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            close(1); // closing stdout
            fcntl(pipefd[1], F_DUPFD, 1);
            close(pipefd[0]); // closing unused reading end

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}

// output 
//  ./a.out 
//      34     299    2104