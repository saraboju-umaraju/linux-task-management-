#include	<stdio.h>
#include	<uma.h>
#include	<stdlib.h>
#include	<stdlib.h>
#include	<errno.h>

#define CONSTANT 199

int var = 1 ;

pthread_mutex_t lock ;
pthread_cond_t cond ;

void *f_one ( ) 
{
		while ( CONSTANT ) {

				pthread_mutex_lock ( &lock ) ;

				while ( var != 0 ) 
						pthread_cond_wait ( &cond , &lock) ;
				puts("two");
				var = 1;	
				pthread_cond_signal ( &cond ) ;

				while(var != 0 )
						pthread_cond_wait ( &cond , &lock) ;
				puts("four");
				var = 1 ;
				pthread_cond_signal ( &cond ) ;
				pthread_mutex_unlock ( &lock ) ;
		}

}
void *f_two ( ) 
{
		while ( CONSTANT ) {
				pthread_mutex_lock ( &lock ) ;
				while ( var != 1) 
						pthread_cond_wait ( &cond , &lock ) ;
				puts("one");
				var = 0 ;
				pthread_cond_signal ( &cond ) ;

				while ( var != 1 ) 
						pthread_cond_wait ( &cond , &lock ) ;
				puts("three");
				var = 0;
				pthread_cond_signal ( &cond ) ;
				pthread_mutex_unlock ( &lock ) ;

		}

}


int main ( void ) 
{
		pthread_t one ;

		pthread_t two ;
	
		int status ;

		pthread_mutex_init ( &lock , NULL ) ;

		pthread_cond_init ( &cond , NULL ) ;
		
		errno = pthread_create ( &one , NULL , f_one , NULL ) ;

		pthread_create ( &two , NULL , f_two , NULL ) ;

		pthread_exit ( ) ;

}
