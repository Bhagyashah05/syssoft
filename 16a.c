// Write a program to perform madatory locking
// a. implement write lock

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argv,char *argc[]){
    int fd=open(argc[1],O_WRONLY);
    if(fd==-1){
        perror("error");
    }
    struct flock lock={F_WRLCK,0,0,0,0};
    fcntl(fd,F_SETLK,&lock);
    printf("press enter to unlock the file");
    getchar();
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    return 0;
}
