// Bhagya Shah
// MT2024135

// Write a program to set (any one) system resource limit. Use setrlimit system call. 
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Current Limits on Open Files:\n");
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");
        return 1;
    }

    limit.rlim_cur = 2048;  
    limit.rlim_max = 4096;  

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New Limits on Open Files Set Successfully:\n");
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n", (long)limit.rlim_max);
    } else {
        perror("setrlimit");
        return 1;
    }

    return 0;
}

// Output 
// ./a.out 
// Current Limits on Open Files:
//   Soft limit: 1048576
//   Hard limit: 1048576

// New Limits on Open Files Set Successfully:
//   Soft limit: 2048
//   Hard limit: 4096
