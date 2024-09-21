// Bhagya Shah
//  MT2024135

// Write a program to print the system limitation of
// a. maximum length of the arguments to the exec family of functions.
// b. maximum number of simultaneous process per user id.
// c. number of clock ticks (jiffy) per second.
// d. maximum number of open files
// e. size of a page
// f. total number of pages in the physical memory
// g. number of currently available pages in the physical memory.


#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/sysinfo.h>

int main() {
    long max_arg_length = sysconf(_SC_ARG_MAX);
    printf("a. Maximum length of arguments to the exec family of functions: %ld\n", max_arg_length);

    long max_procs_per_user = sysconf(_SC_CHILD_MAX);
    printf("b. Maximum number of simultaneous processes per user ID: %ld\n", max_procs_per_user);

    long clock_ticks_per_sec = sysconf(_SC_CLK_TCK);
    printf("c. Number of clock ticks (jiffy) per second: %ld\n", clock_ticks_per_sec);

    long max_open_files = sysconf(_SC_OPEN_MAX);
    printf("d. Maximum number of open files: %ld\n", max_open_files);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("e. Size of a page: %ld bytes\n", page_size);

    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("f. Total number of pages in the physical memory: %ld\n", total_pages);

    long available_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("g. Number of currently available pages in the physical memory: %ld\n", available_pages);

    return 0;
}

// Output 
// ./a.out 
// a. Maximum length of arguments to the exec family of functions: 2097152
// b. Maximum number of simultaneous processes per user ID: 30924
// c. Number of clock ticks (jiffy) per second: 100
// d. Maximum number of open files: 1048576
// e. Size of a page: 4096 bytes
// f. Total number of pages in the physical memory: 1997933
// g. Number of currently available pages in the physical memory: 374273




