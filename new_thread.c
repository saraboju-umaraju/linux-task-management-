#include	<unistd.h>

#include	<pthread.h>

#include	<sys/syscall.h>

#include	<stdlib.h>

#include	<stdio.h>

int a = 10;

void *func( ) 
{
	puts("in thread");

	printf("thread pid %d %d\n",getpid(),syscall(SYS_gettid));

	pthread_exit ( &a ) ;
}

int main ( void ) 
{
	pthread_t id ;
	
	int *b ;

	if ( pthread_create ( &id , NULL , func , NULL ) ) {
	
			puts("creation failed");

			exit ( 1 ) ;

		}

		fgets(stdout , 12 , stdin);
	
		pthread_join ( id , &b ) ;

		puts("ststus received");

		printf ("val %d\n", *(int*)b);

}
