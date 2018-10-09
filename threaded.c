#include    <uma.h>
#include    <pthread.h>

void * thread_func()
{

}
int main (void) {

		int status ;

		pthread_t thid;

		int *retval ; 

		retval = malloc ( sizeof ( int ) ) ;

		status = pthread_create( &thid , NULL , thread_func , NULL );

		if ( status ) {

				printf("FAILED OPERATON\n");
		}

		status = pthread_join ( thid , ( void **)&retval );

		if ( status ) {

				printf("JOIN FAILED\n");

		}

		printf("VALUE OF RETVAL %d \n",*retval);

		pthread_exit ( NULL ) ;

		return 0; 

}

