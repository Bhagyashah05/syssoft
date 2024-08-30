// write a program to execute ls -Rl by the following system calls
// b. execlp


#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "ls";
    execlp(path, path, "-Rl", NULL);
    return 0;
}