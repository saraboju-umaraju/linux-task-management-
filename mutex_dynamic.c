#include	<uma.h>
#include	<pthread.h>

typedef struct _struct {
		
		pthread_mutex_t mutex;
		
		int value ;

}_st ;

int main ( void ) {

		
		int status ;

		_st *data ;

		data = malloc ( sizeof ( _st ) ) ;

		if ( data == NULL ) {

				printf("error");

				exit ( EXIT_FAILURE );
		}


		status = pthread_mutex_init ( &data -> mutex , NULL );

		if ( status != 0 ) {

				printf ( "failed to initilize" );

				exit ( EXIT_FAILURE ) ;

		}
		status = pthread_mutex_lock ( &data -> mutex  );

		if ( status != 0 ) {

				printf ( "failed to initilize" );

				exit ( EXIT_FAILURE ) ;

		}

		data -> value = 399 ;

		status = pthread_mutex_unlock ( &data -> mutex );

		if ( status != 0 ) {

				printf ( "failed to initilize" );

				exit ( EXIT_FAILURE ) ;

		}
		status = pthread_mutex_destroy ( &data -> mutex );

		if ( status != 0 ) {

				printf ( "failed to initilize" );

				exit ( EXIT_FAILURE ) ;


		}

		return status ;

}

