// Write a program to create three child processes. The parent should wait for a particular child (use
// waitpid system call.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int i = 0, cid[3];
    while (i < 3)
    {
        cid[i] = fork();
        if (cid[i] == 0)
        {
            sleep(10);
            printf("Child %d with pid %d is exiting\n", i + 1, getpid());
            return 0;
        }
        else
        {
            printf("for parent %d child %d's pid is %d \n", getpid(), i + 1, cid[i]);
            i++;
        }
    }

    int id, status;
    printf("select the child for which you want parent to wait from 1to 3: ");
    scanf("%d", &id);
    waitpid(cid[id - 1], &status, 0);
    printf("child %d is exited\n",cid[id-1]);
    return 0;
}
