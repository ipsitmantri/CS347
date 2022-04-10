#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct
{
    int a;
    int b;
} myarg_t;

typedef struct
{
    int x;
    int y;
} myret_t;

void *mythread(void *arg)
{
    myarg_t *args = (myarg_t *)arg;
    printf("Inside thread %d %d\n", args->a, args->b);
    myret_t *rvals = malloc(sizeof(myret_t));
    rvals->x = 1;
    rvals->y = 2;
    return (void *)rvals;
}

int main(int argc, char *argv[])
{
    pthread_t p;
    myarg_t args = {10, 20};
    myret_t *rvals;
    pthread_create(&p, NULL, mythread, &args);
    pthread_join(p, (void **)&rvals);
    printf("returned %d, %d\n", rvals->x, rvals->y);
    free(rvals);
    return 0;
}