#include	<uma.h>
#include	<errno.h>

#include	<stdlib.h>

#include	<pthread.h>

int var = 0;

pthread_mutex_t lock ;

void *tone () 
{
/*	sleep (1);

	pthread_mutex_lock ( &lock ) ;

	puts("Iam critical section");

	while ( var == 0 ) ;

	pthread_mutex_unlock ( &lock ) ;*/

}

void *ttwo ()
{
	printf("%d\n",lock);

	errno = pthread_mutex_unlock ( &lock ) ;

	printf("%d\n",lock);
	
	perror("state");
	
    pthread_mutex_lock ( &lock ) ;

	printf("%d\n",lock);

    puts("Iam critical section2");

    usleep(2);

	var = 12 ;

    pthread_mutex_unlock ( &lock ) ;
	
	printf("%d\n",lock);

}

int main ( int c , char *v[] ) 
{

	pthread_t thid , thid2 ;

	pthread_mutex_init ( &lock , NULL ) ;

	pthread_create( &thid , NULL , tone , NULL ) ;	
	
	pthread_create( &thid2 , NULL , ttwo , NULL ) ;	

	pthread_join ( thid , NULL ) ;
	
	pthread_join ( thid2 , NULL ) ;

	if ( v[1] )

	SELF_EXEC ;
	
	pthread_exit ( NULL ) ;

	return 123 ;

}
