//#include    <uma.h>
#include    <unistd.h>

int s ; 
int time = 9;
int main (void) {

		pid_t pid ;

		pid = fork ( ) ;
 
		if( pid > 0 ) {
				
		printf("this is parent %d\n",getpid());

		wait(&s);

		printf("child status  is %d\n",s>>8);

		getchar();

		printf("parent is also died \n");

		}

		else if ( pid == 0)  {

				printf("this is baby prcess %d\n",getpid());

				printf("child is in emegency, about to die\n");

				sleep(5);

			kill:	printf("child will die in %d seconds \n\r",time--);

					sleep(1);

					if( time ) goto kill;

				return 2; 
		}

}

