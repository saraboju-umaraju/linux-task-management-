#include	"head.h"

time_t t ;

node *head = NULL ;

int variable = 0;
int variable2 = 0;
int var  ;

function ( void  )  {

		//		while ( 1 ) {

		variable = 1 ;

		node *temp = head ;

		while ( head == NULL ) ;

		sleep ( ( head -> data ) - var ) ;

		printf ( "wake up you lazy pig...!\n" ) ;

		var = head -> data ;

		head = head -> ptr ;

		free ( temp ) ;

		//	temp = NULL;

		variable = 0;

		//		}

}

int main(void)
{
		int seconds;

		char line[128];

		char message[64];

		pthread_t id ;

		time ( &t ) ;

		printf("PID = %d\n", getpid());


		while(1) {

				printf("alarm> ");

				if( fgets ( line, sizeof(line), stdin) == NULL)
						if (  (pthread_create ( &id , NULL , function ,NULL ) ) ) {

								printf ( "creation failed" ) ;


								exit(0);

						}

				if(strlen(line) <= 1)

						continue;

				if(sscanf(line, "%d", &seconds) < 1)

						fprintf(stderr, "Bad command\n");


				else {

						while ( variable ) ;

						head = insert ( seconds , head ) ;

						if (  (pthread_create ( &id , NULL , function ,NULL ) ) ) {

								printf ( "creation failed" ) ;

								exit ( EXIT_FAILURE );

						} 
				}
		}

}
