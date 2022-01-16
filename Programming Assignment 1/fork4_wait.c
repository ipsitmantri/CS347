#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(int argc, void *argv) {
    for(int i=0; i<4; i++) {
        int ret = fork();
        if(ret == 0) {
            int pid = getpid();
            int ppid = getppid();
            printf("child: i = %d, PID = %d, PPID = %d\n", i, pid, ppid);
        }
        else {
            int res = wait(NULL);
            printf("reaped: PID = %d\n", res);
        }

  }
}
