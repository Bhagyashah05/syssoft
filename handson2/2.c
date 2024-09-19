// Bhagya Shah
// MT2024135
// Write a program to print the system resource limits. Use getrlimit system call.

#include <stdio.h>
#include <sys/resource.h>

void print_limit(int resource, const char *resource_name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%s Limits:\n", resource_name);
        printf("Soft limit: ");
        if (limit.rlim_cur == RLIM_INFINITY) {
            printf("Unlimited\n");
        } else {
            printf("%ld\n", limit.rlim_cur);
        }

        printf("Hard limit: ");
        if (limit.rlim_max == RLIM_INFINITY) {
            printf("Unlimited\n");
        } else {
            printf("%ld\n", limit.rlim_max);
        }
        printf("\n");
    } else {
        perror("getrlimit");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU Time");
    print_limit(RLIMIT_FSIZE, "File Size");
    print_limit(RLIMIT_DATA, "Data Segment Size");
    print_limit(RLIMIT_STACK, "Stack Size");
    print_limit(RLIMIT_CORE, "Core File Size");
    print_limit(RLIMIT_RSS, "Resident Set Size");
    print_limit(RLIMIT_NOFILE, "Number of Open Files");
    print_limit(RLIMIT_AS, "Address Space");
    print_limit(RLIMIT_NPROC, "Number of Processes");
    print_limit(RLIMIT_MEMLOCK, "Locked Memory");
    print_limit(RLIMIT_LOCKS, "File Locks");

    return 0;
}

// Output 

// ./a.out 
// CPU Time Limits:
// Soft limit: Unlimited
// Hard limit: Unlimited

// File Size Limits:
// Soft limit: Unlimited
// Hard limit: Unlimited

// Data Segment Size Limits:
// Soft limit: Unlimited
// Hard limit: Unlimited

// Stack Size Limits:
// Soft limit: 8388608
// Hard limit: Unlimited

// Core File Size Limits:
// Soft limit: 0
// Hard limit: Unlimited

// Resident Set Size Limits:
// Soft limit: Unlimited
// Hard limit: Unlimited

// Number of Open Files Limits:
// Soft limit: 1048576
// Hard limit: 1048576

// Address Space Limits:
// Soft limit: Unlimited
// Hard limit: Unlimited

// Number of Processes Limits:
// Soft limit: 30924
// Hard limit: 30924

// Locked Memory Limits:
// Soft limit: 1022939136
// Hard limit: 1022939136

// File Locks Limits:
// Soft limit: Unlimited
// Hard limit: Unlimited