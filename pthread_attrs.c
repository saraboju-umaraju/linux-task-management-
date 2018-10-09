#include	<stdio.h>

#include	<errno.h>

#include	<pthread.h>

void *thread_function ( )
{	
	pthread_attr_t attrs ;

	pthread_attr_init ( &attrs ) ;

	struct sched_param param ;
	
	param . sched_priority = 88 ;

	int policy = SCHED_FIFO ;

	errno = pthread_setschedparam( pthread_self(), policy , &param ) ;

	perror("");

	getchar();
	
}

int main  ( void ) 
{
	pthread_t thread_id ;

	pthread_attr_t attrs ;

	struct sched_param param ;

	param . sched_priority = 88 ;

	errno = pthread_attr_init ( &attrs ) ;

	perror("");

	errno = pthread_attr_setschedpolicy (&attrs, SCHED_FIFO);

	perror("");
	
	errno = pthread_attr_setschedparam (&attrs, &param );

	perror("");

	errno = pthread_attr_setinheritsched ( &attrs , PTHREAD_EXPLICIT_SCHED ) ; 

	perror("");

	errno = pthread_create ( &thread_id , &attrs , thread_function , NULL) ;

	perror("");

	pthread_join ( thread_id , NULL ) ;

	return 0 ;

}
