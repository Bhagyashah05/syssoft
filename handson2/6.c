// Bhagya Shah 
// MT2024135

// Write a simple program to create three thread.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d is running\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];    
    int thread_ids[3];       

    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution.\n");
    return 0;
}

// output 
// ./a.out 
// Thread 3 is running
// Thread 2 is running
// Thread 1 is running
// All threads have finished execution.
