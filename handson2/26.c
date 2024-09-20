// Bhagya Shah 
// MT2024135

// Write a program to send messages to the message queue. Check $ipcs -q

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

// Structure for message queue
struct message_buffer {
    long message_type;
    char message_text[100];
};

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct message_buffer message;
    message.message_type = 1;  
    printf("Enter a message: ");
    fgets(message.message_text, sizeof(message.message_text), stdin);

    if (msgsnd(msgid, &message, sizeof(message.message_text), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent: %s\n", message.message_text);

    return 0;
}

//  ./a.out 
// Enter a message: bhagya shah   
// Message sent: bhagya shah 

// 0xffffffff 1          bhagyashah 666        100          1       