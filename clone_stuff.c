#include    <uma.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
       #include <unistd.h>
       #include <sys/syscall.h>   /* For SYS_xxx definitions */


#define _SCHED_H 1
#define __USE_GNU 1
#include <bits/sched.h>
#include <sched.h>

#define STACK_SIZE 4096

int func(void *arg) {
		
		printf("Inside func.\n");
		
//		sleep(5);
		
		printf("Terminating func...%ld %d\n",syscall(SYS_gettid),getpid());

		getchar();

		exit (0);
}

int main() {
		
		printf("This process pid: %u\n", getpid());
		
		char status_file[] = "/proc/self/status";
		
		void *child_stack = malloc(STACK_SIZE);
		
		int thread_pid;

		printf("Creating new thread...%d\n",sizeof(status_file));
		
//		thread_pid = clone(func, child_stack+STACK_SIZE, CLONE_SIGHAND |  CLONE_FS | CLONE_VM | CLONE_FILES | CLONE_THREAD, NULL);
	
//		sleep(2);
	
		//thread_pid = clone(func, child_stack+STACK_SIZE, CLONE_SIGHAND |  CLONE_FS | CLONE_VM | CLONE_FILES , NULL);
		
//		thread_pid = clone(func, child_stack+STACK_SIZE, CLONE_SIGHAND | CLONE_VM , NULL);
		
//		sleep(6);
	
		thread_pid = clone(func, child_stack+STACK_SIZE, CLONE_SIGHAND |  CLONE_FS | CLONE_VM | CLONE_FILES | CLONE_VFORK , NULL);
		
		perror("clone call");

		/* pid and tgid same process */

		/* else thread */
		
		printf("Done! Thread pid: %d\n", thread_pid);

/*		FILE *fp = fopen(status_file, "rb");

		printf("Looking into %s...\n", status_file);

		while(1) {
		
				char ch = fgetc(fp);
				
				if(feof(fp)) break;
				
				printf("%c", ch);
		}

		fclose(fp);*/

//		getchar();

		return 0;
}
