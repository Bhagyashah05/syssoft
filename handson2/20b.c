// Bhagya Shah 
// MT2024135

// Write two programs so that both can communicate by FIFO -Use one way communication.

// receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char buffer[100];

    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Receiver: Read message from FIFO: %s\n", buffer);

    close(fd);
    
    return 0;
}
// ./a.out 
// Receiver: Read message from FIFO: Hello fr

