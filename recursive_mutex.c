
#define _GNU_SOURCE

#include	<uma.h>

#include	<errno.h>

#include	<stdlib.h>

#include	<pthread.h>

int var = 0;

pthread_mutex_t lock ;

void *tone () 
{

	while ( 1 ) {
	
	printf("lock %d %d \n" , lock , pthread_mutex_lock ( &lock ) );

	usleep(1000000);

	}

}

void *ttwo ()
{

}

int main ( int c , char *v[] ) 
{

	pthread_t thid , thid2 ;

	pthread_mutexattr_t attr  ;

	pthread_mutexattr_init(&attr) ;

  	pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_RECURSIVE_NP );

	pthread_mutex_init ( &lock , &attr ) ;

	pthread_create( &thid , NULL , tone , NULL ) ;	
	
	pthread_create( &thid2 , NULL , ttwo , NULL ) ;	

	pthread_join ( thid , NULL ) ;
	
	pthread_join ( thid2 , NULL ) ;

	return 123 ;

}
