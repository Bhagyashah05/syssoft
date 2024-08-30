// Write a program, call fork and print the parent and child process id.

#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("parent pid = %d\n", getpid());
    int fid = fork();
    if(fid) printf("child pid = %d\n", fid);
    return 0;
}