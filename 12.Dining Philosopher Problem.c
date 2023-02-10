#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
sem_t mutex;
sem_t s[N];

void test(int i) {
  if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
    state[i] = EATING;
    sem_post(&s[i]);
  }
}

void take_forks(int i) {
  sem_wait(&mutex);
  state[i] = HUNGRY;
  test(i);
  sem_post(&mutex);
  sem_wait(&s[i]);
}

void put_forks(int i) {
  sem_wait(&mutex);
  state[i] = THINKING;
  test(LEFT);
  test(RIGHT);
  sem_post(&mutex);
}

void *philosopher(void *num) {
  int i = *(int*)num;
  while (1) {
    printf("Philosopher %d is thinking\n", i + 1);
    sleep(1);
    take_forks(i);
    printf("Philosopher %d is eating\n", i + 1);
    sleep(1);
    put_forks(i);
  }
}

int main() {
  int i;
  pthread_t thread_id[N];
  int num[N];

  sem_init(&mutex, 0, 1);
  for (i = 0; i < N; i++) {
    sem_init(&s[i], 0, 0);
  }
  for (i = 0; i < N; i++) {
    num[i] = i;
    pthread_create(&thread_id[i], NULL, philosopher, &num[i]);
  }
  for (i = 0; i < N; i++) {
    pthread_join(thread_id[i], NULL);
  }
}

