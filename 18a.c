/*
Name: 18a.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 29th Aug 2024
*/

// Description:

// . Write a program to perform Record locking.
// a. Implement write lock
// b. Implement read lock
// Create three records in a file. Whenever you access a particular record, first lock it then modify/access
// to avoid race condition.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

typedef struct record{
    int id;
    int ticket;
} record;

int main(){
    record r1={1,1};
    record r2={2,2};
    record r3={3,3};

    int fd=open("18record.txt",O_RDWR|O_WRONLY|O_CREAT,S_IRWXU);
    char buff[20];

    sprintf(buff,"id=%dticket_no=%d",r1.id,r1.ticket);
    write(fd,&buff,sizeof(buff));

    sprintf(buff,"id=%dticket_no=%d",r2.id,r2.ticket);
    write(fd,&buff,sizeof(buff));

    sprintf(buff,"id=%dticket_no=%d",r3.id,r3.ticket);
    write(fd,&buff,sizeof(buff));

    return 0;

}

// output 
//  ./a.out 
// bhagyashah05@Bhagya-Shah:~/syssoft$ cat 18record.txt 
// id=1ticket_no=1