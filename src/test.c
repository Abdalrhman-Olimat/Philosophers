#include "../includes/test.h"


void *print_message(void *arg)
{
    int x = *((int *)arg);
    printf("Thread: x = %d\n", x);
    return NULL;
}

int main() {
    int x = 2;
    pthread_t thread;

    //Create the new thread that will run 'print_message'
    if (pthread_create(&thread, NULL, print_message, &x))
    {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    printf("tesst  %d\n", x);
    // Wait for the thread to finish
    if (pthread_join(thread, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    // Print from the main thread too
    printf("Main thread: x = %d\n", x);

    return 0;
}
