// Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
    char *buf[10];
    printf("Enter ticket number:\n");
    int fd=open("tickets.txt",O_RDWR,S_IRWXU);
    if(fd==-1){
        perror("Error");
        return 1;
    }
    int tick=read(0,buf,10);
    write(fd,buf,tick);
    printf("ticket number store\n");


    return 0;
}