#include <stdio.h>
#include "zemaphore.h"

zem_t A1Done, B1Done;

void *threadA(void *args)
{
    printf("A1\n");
    zem_down(&B1Done);
    zem_up(&A1Done);
    printf("A2\n");
    return 0;
}

void *threadB(void *args)
{
    printf("B1\n");
    zem_up(&B1Done); // correct
    zem_down(&A1Done);
    // zem_up(&B1Done); // incorrect
    printf("B2\n");
    return 0;
}

int main(int argc, char *argv[])
{
    zem_init(&A1Done, 0);
    zem_init(&B1Done, 0);
    pthread_t A;
    pthread_t B;
    pthread_create(&A, NULL, threadA, NULL);
    pthread_create(&B, NULL, threadB, NULL);

    pthread_join(A, NULL);
    pthread_join(B, NULL);

    return 0;
}
