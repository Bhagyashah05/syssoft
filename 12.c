/*
Name: 12.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 23 Aug 2024
*/

// Description:
// Write a program to find out the opening mode of a file. Use fcntl.

#include<stdio.h>
#include<fcntl.h>

int main(){
    int fd=open("11.txt",O_RDONLY|O_WRONLY);
    int mode=fcntl(fd,F_GETFL);
    switch(mode){
    case 32768 : printf("r"); break;
    case 32769 : printf("w"); break;
    case 33792 : printf("a"); break;
    case 32770 : printf("r+ || w+"); break;
    case 32794 : printf("a+"); break;
}
printf("%d",mode);
    return 0;
}
// output 
// ./a.out 
// w32769

// F_GETFL return the mode of file
