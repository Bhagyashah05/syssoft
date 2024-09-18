
/*
Name: 1b.c
Author: Bhagya Shah
Roll no:MT2024135
Date: 14th Aug 2024
*/

// Description:
// Create the following types of a files using (i) shell command (ii) system call
// b. hard link (link system call)
#include<stdio.h>
#include<unistd.h>

int main(){
	const char *target="myFile";

	const char *linfile="linkfile.txt";

	if(link(target,linfile)==0){
		printf("doneeeeeeeeee");
	}
	else{
		perror("not donee");
		return 1;
	}
	return 0;
}

// output
//  ./a.out 
// doneeeeeeeeee