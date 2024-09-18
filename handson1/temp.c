#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

extern int errno;

int main(void){
	int fd=open("11.txt",O_WRONLY,S_IRWXU);
	if(fd==-1){
		perror("error");
	}
	if (write(fd, "hello", strlen("hello")) == -1) {
        perror("Error writing to file");
        close(fd);  
        return 1;
    }
	return 0;
}

