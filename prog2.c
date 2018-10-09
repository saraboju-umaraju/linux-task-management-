#include    <uma.h>

int var = 0 ;

int main (void) 
		
		{

		pid_t pid ;

		pid = fork() ;

		if( pid > 0 ) {

				printf("parent %d \n",getpid());

				printf("variable address %p\n",&var);
				
				printf("code address %p\n",&main);

				printf("%p\n",__builtin_return_address(0));

				wait();

		}

		if ( pid == 0 ) {

				printf("baby %d \n",getpid());
				
				printf("variable address %p\n",&var);
				
				printf("code address %p\n",&main);
				
				printf("%p\n",__builtin_return_address(0));

				return 121;

		}

		printf("so verified that baby and parent shares same data area\n");


		}
