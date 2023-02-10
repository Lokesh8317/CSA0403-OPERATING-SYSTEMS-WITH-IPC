#include <stdio.h>
#include <pthread.h>

void* print_message(void* arg) {
    char* message = (char*) arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t new_thread;
    char* message = "Hello from the new thread!";
    pthread_create(&new_thread, NULL, print_message, (void*) message);
    printf("Main thread is running\n");
    pthread_join(new_thread, NULL);
    printf("Main thread is done\n");
    return 0;
}
#include <stdio.h>
#include <pthread.h>

void* print_numbers(void* arg) {
    for (int i = 0; i < 10; i++); {
        printf("%d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t new_thread;
    pthread_create(&new_thread, NULL, print_numbers, NULL);
    pthread_join(new_thread, NULL);
    printf("Thread has finished\n");
    return 0;
}
