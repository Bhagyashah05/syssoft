/*
Name: 18c.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 29th Aug 2024
*/

// Description:
// continue from 18b 
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd = open("18record.txt", O_RDWR);
    int id, ticket;
    char name[12];
    struct flock rdlock = {F_WRLCK, SEEK_SET, 0, 34, getpid()};
    int i;
    printf("Enter record id:");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        rdlock.l_start = 0;
        id = 1;
        ticket = 1;
        lseek(fd, 0, SEEK_SET);
        break;
    case 2:
        rdlock.l_start = 17;
        id = 2;
        ticket = 2;
        lseek(fd, 17, SEEK_SET);
        break;
    case 3:
        rdlock.l_start = 34;
        id = 3;
        ticket = 3;
        lseek(fd, 34, SEEK_SET);
        break;
    default:
        perror("invalid choise of record!!!");
        return 0;
    }
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record %d id locked\n", id);
    printf("Enter new ticket no ");
    scanf("%d", &ticket);
    char buf[17];
    sprintf(buf, "id=%dticket_no=%d", id, ticket);
    write(fd, &buf, sizeof(buf));
    getchar();
    rdlock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record is unlocked\n");
    return 0;
}

// output 
//  ./a.out 
// Enter record id:2
// record 2 id locked
// Enter new ticket no 2
// record is unlocked