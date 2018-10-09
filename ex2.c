#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(int argc, char *argv[])
{
		int pid;
		int count = 0;
		char *argv2[argc+1];

		for(count = 0; count < argc-1; count++){
				argv2[count] = argv[count+1];
				printf("Argv2: %s\n", argv2[count]);  //just double checking
				argv2[argc-1] = NULL;
		}

		pid = fork();
		if(pid == 0){
				printf("Child's PID is %d. Parent's PID is %d\n", (int)getpid, (int)getppid());
				execv(".", argv2);       //<---- confused here
		}
		else{
				wait(pid);
				exit(0);
		}
}
