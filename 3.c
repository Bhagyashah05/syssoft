/*
Name: 3.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 14th Aug 2024
*/

// Description:
// Write a program to create a file and print the file descriptor value. Use creat ( ) system call
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>

int main(){
    const char *filepath="blankfile";
    int fd=creat(filepath, S_IRUSR | S_IWUSR);
    if(fd==-1){
        perror("failed");
        return 1;
    }
    else{
        printf("doneeeeeeeee");
    }
    return 0;
}

// output 
// ./a.out 
// doneeeeeeeee