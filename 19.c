// Write a program to find out time taken to execute getpid system call. Use time stamp counter.

#include<stdio.h>
#include<unistd.h>
unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc": "=A"(dst));
    return dst;
}
int main(){
    long long int start=rdtsc();
    printf("process id: %d\n",getpid());

    long long int end=rdtsc();
    printf("time taken : %llu\n",end-start);
    return 0;
}