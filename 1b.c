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
