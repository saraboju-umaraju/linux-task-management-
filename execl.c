#include    <uma.h>

int i;

int main (void) 
		{

		pid_t pid ;

		pid = fork() ;

		if( pid > 0 ) {

				printf("PARENT %d \n",getpid());

		}

		if ( pid == 0 ) {

				printf("BABY %d \n",getpid());

				execl("/bin/echo","echo","HELLO UGLY..!",NULL);

				printf("ENTERED\n");

				return 121;

		}

		printf("ACK\n");

		getchar();
		
		printf("%d\n",getpid());

		}


