#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define READERS 5
#define WRITERS 2

sem_t readCountAccess;
sem_t databaseAccess;
int readCount = 0;

void *ReaderFunction(void *arg)
{
    int readerNum = *((int *)arg);

    while (1) {
        sem_wait(&readCountAccess);
        readCount++;
        if (readCount == 1) {
            sem_wait(&databaseAccess);
        }
        sem_post(&readCountAccess);

        printf("Reader %d is reading the database\n", readerNum);
        sleep(1);

        sem_wait(&readCountAccess);
        readCount--;
        if (readCount == 0) {
            sem_post(&databaseAccess);
        }
        sem_post(&readCountAccess);

        sleep(1);
    }

    pthread_exit(NULL);
}

void *WriterFunction(void *arg)
{
    int writerNum = *((int *)arg);

    while (1) {
        sem_wait(&databaseAccess);

        printf("Writer %d is writing to the database\n", writerNum);
        sleep(1);

        sem_post(&databaseAccess);

        sleep(1);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t readerThread[READERS];
    pthread_t writerThread[WRITERS];
    int readerNum[READERS];
    int writerNum[WRITERS];

    sem_init(&readCountAccess, 0, 1);
    sem_init(&databaseAccess, 0, 1);

    for (int i = 0; i < READERS; i++) {
        readerNum[i] = i;
        pthread_create(&readerThread[i], NULL, ReaderFunction, &readerNum[i]);
    }

    for (int i = 0; i < WRITERS; i++) {
        writerNum[i] = i;
        pthread_create(&writerThread[i], NULL, WriterFunction, &writerNum[i]);
    }

    for (int i = 0; i < READERS; i++) {
        pthread_join(readerThread[i], NULL);
    }

    for (int i = 0; i < WRITERS; i++) {
        pthread_join(writerThread[i], NULL);
    }

    sem_destroy(&readCountAccess);
    sem_destroy(&databaseAccess);

    return 0;
}

