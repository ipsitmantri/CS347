#include <pthread.h>

typedef struct zemaphore
{
    pthread_cond_t cv;
    pthread_mutex_t lock;
    int counter;
} zem_t;

void zem_init(zem_t *, int);
void zem_up(zem_t *);
void zem_down(zem_t *);
