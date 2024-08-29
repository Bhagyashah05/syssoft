// Write a program to display the environmental variable of the user (use environ).

#include<stdio.h>
extern char **environ;
void main(){
    printf("%s\n",*environ);
}

// environ is a pointer to a NULL-terminated array of 
// pointers to null-terminated character strings.  Each string has the 
// form "name=value" to indicate the name of an environment variable and its current value.  