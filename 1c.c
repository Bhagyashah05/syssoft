#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int fifofd;
    int mkret;

    mkret=mknod("myNode", S_ISFIFO | 0666,0);

    if((mkret==-1)){
        perror("failed");
        return 1;
    }
    printf("doneeeeeee");

    fifofd=open("myNode",O_RDWR);

    if (fifofd==-1)
    {
        perror("faileddd");
        return 1;
    }

    printf("doneee");

    write(fifofd,"Hello",sizeof("Hello"));

    close(fifofd);


    return 0;
    
    

}