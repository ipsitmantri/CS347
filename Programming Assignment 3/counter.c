#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int counter = 0;
pthread_mutex_t mylock;

void *mythread(void *arg)
{
    for (int i = 0; i < 1000; i++)
    {
        pthread_mutex_lock(&mylock);
        counter = counter + 1;
        pthread_mutex_unlock(&mylock);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_mutex_init(&mylock, NULL);
    pthread_t threads[10];
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&threads[i], NULL, mythread, NULL);
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(threads[i], (void **)NULL);
    }
    pthread_mutex_destroy(&mylock);
    printf("The final value of the counter = %d\n", counter);
    return 0;
}