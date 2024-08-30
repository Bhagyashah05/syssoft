// write a program to execute ls -Rl by the following system calls
// d. execvp


#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "ls";
    char *argv[] = {path, "-Rl", NULL};
    execvp(path, argv);
    return 0;
}