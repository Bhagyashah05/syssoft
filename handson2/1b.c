// Bhagya Shah
// MT2024135
/*
    Write a separate program (for each time domain) to set a interval timer in 10sec and
    10micro second
    a. ITIMER_REAL
    b. ITIMER_VIRTUAL
    c. ITIMER_PROF
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void timer_handler(int x) {
    printf("Timer expired for ITIMER_VIRTUAL\n");
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, timer_handler);

    timer.it_value.tv_sec = 10;  
    timer.it_value.tv_usec = 10; 

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error setting ITIMER_VIRTUAL");
    }

    while (1);  
    return 0;
}

// Output 
// ./a.out 
// Timer expired for ITIMER_VIRTUAL
// Timer expired for ITIMER_VIRTUAL