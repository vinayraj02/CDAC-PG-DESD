#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define BUFFER_SIZE 128

// Structure to pass data to the thread
struct ThreadData {
    char *buffer;
    size_t size;
};

// Thread function to count occurrences of 'A' and 'S'
void* countOccurrences(void* data) {
    struct ThreadData* threadData = (struct ThreadData*)data;

    // Initialize counts
    int countA = 0;
    int countS = 0;

    // Count occurrences
    for (size_t i = 0; i < threadData->size; ++i) {
        if (threadData->buffer[i] == 'A') {
            countA++;
        } else if (threadData->buffer[i] == 'S') {
            countS++;
        }
    }

    // Print counts
    printf("Thread: Count of 'A': %d, Count of 'S': %d\n", countA, countS);

    // Clean up and exit the thread
    free(threadData->buffer);
    free(threadData);
    pthread_exit(NULL);
}

int main() {
    // Create a FIFO for communication
    int fifo_fd = open("/tmp/myfifo", O_RDONLY);

    // Read data from the FIFO
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = read(fifo_fd, buffer, sizeof(buffer));

    // Close the FIFO
    close(fifo_fd);

    // Create thread data structure
    struct ThreadData* threadData = (struct ThreadData*)malloc(sizeof(struct ThreadData));
    threadData->buffer = malloc(bytesRead);
    threadData->size = bytesRead;

    // Copy data for thread
    memcpy(threadData->buffer, buffer, bytesRead);

    // Create two threads for counting occurrences
    pthread_t threadA, threadS;
    pthread_create(&threadA, NULL, countOccurrences, (void*)threadData);
    pthread_create(&threadS, NULL, countOccurrences, (void*)threadData);

    // Wait for threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadS, NULL);

    return 0;
}
