#include    <uma.h>
#include <stdlib.h>
#include <unistd.h>

#define _SCHED_H 1
#define __USE_GNU 1
#include <bits/sched.h>

#define STACK_SIZE 4096

int func(void *arg) {
		printf("Inside func.\n");
		sleep(1);
		printf("Terminating func...\n");

		return 0;
}

int main() {
		printf("This process pid: %u\n", getpid());
		void *child_stack = malloc(STACK_SIZE);
		printf("malloc provided %d \n",malloc_usable_size(child_stack));
		int thread_pid;

		printf("Creating new thread...\n");
		thread_pid = clone(&func,child_stack+STACK_SIZE, CLONE_SIGHAND|CLONE_FS|CLONE_VM|CLONE_FILES, NULL);
		perror("clone call");
		
		printf("Done! Thread pid: %d\n", thread_pid);
		
		getchar();

		return 0;
}
