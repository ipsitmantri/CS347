#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, void* argv) {
	printf("Current PID: %d\n", getpid());
	for (int i = 0; i < 4; i++) {
		int ret = fork();
		if (ret == 0) {
			int pid = getpid();
			int ppid = getppid();
			printf("child: i = %d, PID = %d, PPID = %d\n", i, pid, ppid);
		}
	}

}
