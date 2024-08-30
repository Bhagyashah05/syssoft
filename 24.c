// Write a program to create an orphan process.

#include<stdio.h>
#include<unistd.h>

int main(){
    int pid=fork();
    if(pid==0){
        sleep(20);
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid());
    }else{
        sleep(10);
        printf("inside parent pid= %d\n", getpid());
        printf("child pid= %d\n", pid);
    }
    return 0;
}