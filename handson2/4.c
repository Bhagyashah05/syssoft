// Bhagya Shah
// MT2024135
// Write a program to find out time taken to execute getpid system call. Use time stamp counter.

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start_tsc, end_tsc;

    start_tsc = rdtsc();

    getpid();

    end_tsc = rdtsc();

    uint64_t cycles_taken = end_tsc - start_tsc;
    printf("CPU cycles taken by getpid(): %lu\n", cycles_taken);

    return 0;
}

// Output 
// ./a.out 
// CPU cycles taken by getpid(): 59736
