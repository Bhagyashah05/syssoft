// Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
// verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include<stdio.h>
#include<sys/select.h>
#include<unistd.h>
#include<time.h>

int main(){
    struct timeval t;
    fd_set fd;
    FD_SET(0,&fd);
    t.tv_sec=10;
    t.tv_usec=0;
    int ret=select(1,&fd,NULL,NULL,&t);
    if(ret==-1){
        printf("error");
    }
    else if(ret==0){
        printf("time limit reached");
    }
    else{
        printf("entered");
    }
    return 0;
}

// timeval is used to represent time with seconds and microseconds
// fd_set is set of file discriptior
