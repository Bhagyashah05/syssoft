// Write a program to find the type of a file.
// a. Input should be taken from command line.
// b. program should be able to identify any type of a file.
#include <sys/stat.h>
#include <stdio.h>

int main(int argv,char *argc[]){
    struct stat file;
    if(lstat(argc[1],&file)==-1){
        perror("Error");
        return 1;
    }

    if(S_ISDIR(file.st_mode)){
        printf("Directory");
    }
    else if(S_ISLNK(file.st_mode)){
        printf("Link");

    }
    else if(S_ISREG(file.st_mode)){
        printf("Regular file");
    }
    else if(S_ISCHR(file.st_mode)){
        printf("character file");

    }
    else if(S_ISBLK(file.st_mode)){
        printf("block file");

    }
    else if(S_ISFIFO(file.st_mode)){
        printf("fifo file");
        
    }
    else if(S_ISSOCK(file.st_mode)){
        printf("Not known");
        
    }
    else{
        printf("Not known");
    }
    return 0;
}

// we can use stat instead of lstat but it doesnt handle sym link effectively