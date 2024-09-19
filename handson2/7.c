// Bhagya Shah 
// MT2024135

// Write a simple program to print the created thread ids.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d has ID: %lu\n", thread_id, pthread_self());
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
// Thread 1 has ID: 140583047788224
// Thread 2 has ID: 140583039395520
// Thread 3 has ID: 140583031002816
// All threads have finished execution.