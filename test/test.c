#include <pthread.h>
#include <stdio.h>

int shared = 0;

void *thread_func(void *arg) {
    shared++;
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Shared = %d\n", shared);
    return 0;
}

