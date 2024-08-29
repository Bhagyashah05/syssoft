// Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
// bytes (use lseek) and write again 10 bytes.
// a. check the return value of lseek
// b. open the file with od and check the empty spaces in between the data.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argv, char *argc[])
{
	int fd = open(argc[1], O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		perror("cant open file");
		close(fd);
		return 0;
	}
	char s[10] = "bhagyashah";
	write(fd, s, 10);
	int i = lseek(fd, 10, SEEK_CUR);
	printf("%d\n", i);
	write(fd, s, 10);
	i = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", i);
	return 0;
}