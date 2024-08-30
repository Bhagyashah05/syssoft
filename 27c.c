// write a program to execute ls -Rl by the following system calls
// c. execle


#include <stdio.h>
#include <unistd.h>
int main(int argc,char *argv[],char *env[])
{
    char *path = "/bin/ls";
    execle(path, path, "-Rl" ,"27cdemo",NULL, env);
    return 0;
}