/*
Name: 18b.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 29th Aug 2024
*/

// Description:
// continue from 18a 

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd = open("18record.txt", O_RDONLY);
    struct flock rdlock = {F_RDLCK, SEEK_SET, 0, 34, getpid()};
    int id;
    printf("Enter record id:");
    scanf("%d", &id);
    switch (id)
    {
    case 1:
        rdlock.l_start = 0;
        break;
    case 2:
        rdlock.l_start = 17;
        break;
    case 3:
        rdlock.l_start = 34;
        break;
    default:
        perror("invalid choise of record!!!");
        return 0;
    }
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record %d id locked Enter to unlock it\n", id);
    getchar();
    getchar();
    rdlock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record is unlocked\n");
    return 0;
}

// output 
// ./a.out 
// Enter record id:1
// record 1 id locked Enter to unlock it

// record is unlocked