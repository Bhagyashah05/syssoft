#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

int main(void){
	printf("fd= %d\n",creat("myfile",0743));
}

