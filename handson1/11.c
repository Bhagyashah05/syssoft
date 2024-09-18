/*
Name: 11.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 23 Aug 2024
*/

// Description:

// Write a program to open a file, duplicate the file descriptor and append the file with both the
// descriptors and check whether the file is updated properly or not.
// a. use dup
// b. use dup2
// c. use fcntl


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){
    int fd = open("11.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if(fd<0){
        printf("Error opening file");
    }
    int dupli=dup(fd);

    int dupli2=dup2(fd,7);

    int dupfcntl=fcntl(fd,F_DUPFD,7);


    write(fd,"Hello from old fd \n",strlen("Hello from old fd \n"));

    write(dupli,"hello again from dupli \n",strlen("hello again from dupli \n"));

    write(dupli2,"hello again from dupli 2\n",strlen("hello again from dupli 2\n"));

    write(dupfcntl,"hello again from dup fcntl 2\n",strlen("hello again from dup fcntl\n"));


    return 0;
}

// output 
// hello again from dup fcntl ./a.out 
// bhagyashah05@Bhagya-Shah:~/syssoft$ cat 11.txt 
// hello from old fd 
// hello again from dupli 
// Hello from old fd 
// hello again from dupli 
// hello again from dupli 2
// Hello from old fd 
// hello again from dupli 
// hello again from dupli 2
// hello again from dup fcntl 
// Hello from old fd 
// hello again from dupli 
// hello again from dupli 2
// hello again from dup fcntl

// the main difference between dup and dup2 is that dup2 takes specific fd from 
// user while dup assign next smallest used fd 


// The F_DUPFD command value duplicates the file descriptor that is the first argument to the fcntl() function. 
// The new file descriptor is the return value of the function; as with open(), it is the lowest numbered
// descriptor that is not open. However, we can also specify a third numeric argument to fcntl() that defines
// the floor value for assigning to a file descriptor, so that the file descriptor value will be no less than the number specified.