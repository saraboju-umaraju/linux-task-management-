#include	<uma.h>
#include	<pthread.h>
#define SIZE 64

typedef struct structure {

		int data ;

		struct structure  *ptr;

}exc ;

int main ( ) {

		exc *head ;

		char message [ 64 ] ;

		int time ;

		char buffer[SIZE];

		while ( 1 ) {

				printf ( "alaram-->" ) ;

				if ( ! (fgets ( buffer , SIZE , stdin ) ) ) {

						printf ( "cant go ahead \n" ) ;

						exit ( EXIT_FAILURE ) ;

				}

				if (sscanf ( buffer , "%d %[^\n]s", &time , message ) < 2 ) {

						printf ( "missing arguement \nunsage : seconds message" ) ;

						continue ;

				}


		}


}
