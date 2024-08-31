/*
Name: 6.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 18th Aug 2024
*/

// Description:

// Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
    char buffer[1024];
    ssize_t bytes_read,bytes_written;
    while(1){
        bytes_read=read(STDIN_FILENO,buffer,1024);

        if(bytes_read<0){
            perror("failed");
            return 1;
        }
        if(bytes_read==0){
            break;
        }
        bytes_written=write(STDOUT_FILENO,buffer,bytes_read);

        if(bytes_written<0){
            perror("error");
            return 1;
        }


    }
    return 0;
}

// output 
// ./a.out 
// bhagya
// bhagya
