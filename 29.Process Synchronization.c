#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int fill = 0;
int use = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    while (1) {
        int item = rand() % 100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[fill] = item;
        fill = (fill + 1) % BUFFER_SIZE;
        printf("Produced item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[use];
        use = (use + 1) % BUFFER_SIZE;
        printf("Consumed item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main() {
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_t producer_thread;
    pthread_t consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
}
