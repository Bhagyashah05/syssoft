#include <stdio.h>
#include <unistd.h>

int main(){
	const char *target="myFile.txt";

	const char *linkpath="linkfile.txt";

	if(symlink(target,linkpath)==0){
		printf("symbolic link created ");
	}
	else{
	perror("symlink");
	return 1;
	}

	return 0;
}
