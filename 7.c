/*
Name: 7.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 18th Aug 2024
*/

// Description:
// Write a program to copy file1 into file2 ($cp file1 file2).

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    FILE *fo,*fw;

    fo=fopen("myfile","r");
    if(fo==NULL){
        return 1;
    }

    fw=fopen("myFile","w");

    if(fw==NULL){
        return 1;
    }
    int c;
    while((c=fgetc(fo))!=EOF){
        fputc(c,fw);
    }

    printf("donee");

    fclose(fo);
    fclose(fw);
    return 0;

}

// output 
// ./a.out 
// donee