/*
Name: 16b.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 24th Aug 2024
*/

// Description:
// Write a program to perform mandatory locking.
// b. Implement read lock

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argv,char *argc[]){
    int fd=open(argc[1],O_RDONLY);
    if(fd==-1){
        perror("error");
    }
    struct flock lock={F_RDLCK,0,0,0,0};
    fcntl(fd,F_SETLK,&lock);
    printf("press enter to unlock the file");
    getchar();
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    return 0;
}
// output 
// ./a.out linkfile.txt 
// press enter to unlock the file
