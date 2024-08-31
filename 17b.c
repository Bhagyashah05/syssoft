/*
Name: 17b.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 29th Aug 2024
*/

// Description:
// continue from 17a part
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int fd=open("tickets.txt",O_RDWR);
    struct flock l={F_WRLCK,SEEK_SET,0,0,0};
    fcntl(fd,F_SETLK,&l);
    printf("locked applied");
    char buff[10];
    int tick=read(fd,&buff,10);

    int count=atoi(buff);
    count+=1;
    printf(buff,"%d",count);

    lseek(fd,0,SEEK_SET);
    write(fd,&buff,strlen(buff));
    printf("%d\n",count);

    getchar();
    l.l_type=F_UNLCK;
    fcntl(fd,F_SETLKW,&l);
    printf("file unlocked");
    return 0;
}

// output 
// ./a.out 
// locked applied1
// 2

// file unlocked