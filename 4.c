/*
Name: 4.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 14th Aug 2024
*/

// Description:
// Write a program to open an existing file with read write mode. Try O_EXCL flag also.
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
// O_EXCL is use to check if file does not exist it will throw error
extern int errno;
int main(){

	int fd=open("4.txt",O_RDWR | O_EXCL);

	printf("fd= %d\n",fd);

	if(fd==-1){
		printf("%d\n",errno);
		perror("Program");

	}
	return 0;
}

// output 
// ./a.out 
// fd= 3