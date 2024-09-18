/*

Name : Bhagya Shah
Roll No. : MT2024135

*/

// description:
//  Write a program to create five new files with infinite loop. Execute the program in the background
// and check the file descriptor table at /proc/pid/fd.



#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int f[5];
    char file[20];

    for (int i = 0; i < 5; i++) {
        sprintf(file, "%d.txt", i+1);
        f[i] = open(file, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        
        if (f[i] == -1) {
            perror("Error");
            return 1;
        } else {
            printf("File descriptor for '%s': %d\n", file, f[i]);
        }
    }

    while (1) {
        sleep(1);  
    }

    for (int i = 0; i < 5; i++) {
        close(f[i]);
    }

    return 0;
}

/*

./a.out
File descriptor for '1.txt': 3
File descriptor for '2.txt': 4
File descriptor for '3.txt': 5
File descriptor for '4.txt': 6
File descriptor for '5.txt': 7

*/