#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t A1Done, B1Done;
int A1, B1;

void *threadA(void *args)
{
    printf("A1\n");
    pthread_mutex_lock(&lock);
    while (B1 == 0)
    {
        pthread_cond_wait(&B1Done, &lock);
    }
    A1 = 1;
    pthread_cond_signal(&A1Done);
    pthread_mutex_unlock(&lock);
    printf("A2\n");
    return 0;
}

void *threadB(void *args)
{
    printf("B1\n");
    pthread_mutex_lock(&lock);
    B1 = 1;
    pthread_cond_signal(&B1Done);
    while (A1 == 0)
    {
        pthread_cond_wait(&A1Done, &lock);
    }
    // B1 = 1;      // incorrect
    // pthread_cond_signal(&B1Done); // incorrect
    printf("B2\n");
    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t A;
    pthread_t B;
    pthread_create(&A, NULL, threadA, NULL);
    pthread_create(&B, NULL, threadB, NULL);

    pthread_join(A, NULL);
    pthread_join(B, NULL);

    return 0;
}