// Write a program to open a file in read only mode, read line by line and display each line as it is read.
// Close the file when end of file is reached.

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *file;
    char buffer[256]; //this buffer holds each line

    file=fopen("linkfile.txt","r"); //opens file in read mode

    if(file==NULL){
        printf("error opening file");
        return -1;
    }

    while(fgets(buffer,sizeof(buffer),file)!=NULL){
        printf("%s",buffer);
    }

    fclose(file);

    return 0;
}

// The fgets() reads a line from the specified stream and 
// stores it into the string pointed to by str. It stops
//  when either (n-1) characters are read, the newline character
// is read, or the end-of-file is reached, whichever comes first.

// char *fgets (char *str, int n, FILE *stream);
// Parameters
// str: Pointer to an array of chars where the string read is copied.
// n: Maximum number of characters to be copied into str (including the terminating null character).
// *stream: Pointer to a FILE object that identifies an input stream.

// use gets() to take string from stdin