#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main (int argc, void* argv)
{
    printf("%d\n", getpid());
    int ret = fork();
    if (ret == 0)
    {
        printf("I am the child: PID = %d, PPID = %d\n", getpid(), getppid());
    }
    // else if (ret > 0)
    // {
    //     printf("I am the parent: PID = %d, PPID = %d\n", getpid(), getppid());
    // }
}