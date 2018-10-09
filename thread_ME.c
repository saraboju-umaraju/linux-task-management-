/*

 *   program to implement mutual exclusion with the help of a complex expression

 */




#include	<pthread.h>
#include	<uma.h>
#include	<stdlib.h>
short int i = 0 ;
//char k = 0;
unsigned char kill = 0;
void* function (  ) {

		//	k += 12 - 12 + 12 + 12 * 12 * 12 / 12 - 12;
		
		while ( 1 ) {


				while ( !i  ) ;

				printf ("control is with me iam second thread %d \n",kill++);
		
				sleep ( 1 ) ;

				i = 0 ;

		}

}

int main( void ) {


		pthread_t *thread ;

		pthread_attr_t *inst ;

		inst = malloc (sizeof ( pthread_attr_t ) ) ;

		if (  pthread_create ( thread ,inst , function , NULL ) ) {

				printf ( "thread creation failed\n" ) ;

				exit ( EXIT_FAILURE ) ;

		}

		while ( 1 ) {

				while ( i ) ;

				printf ( "control is with me iam main thread %d \n", kill++) ;

				sleep(1);

				i = 1 ;

		}

}
