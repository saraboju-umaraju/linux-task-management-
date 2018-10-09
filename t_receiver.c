#include	<mqueue.h>

#include	<uma.h>

#include	<fcntl.h>

mqd_t md ;

struct mq_attr attr ;

int main ( void ) {

		char buffer [20] = "" ;

		unsigned int prio = 1 ;

		int var = 4 ;

		if (( md = mq_open ( "/mq" , O_RDONLY  , 0777 , NULL ) ) == -1 ) {

				perror("ERROR");

				exit ( EXIT_FAILURE ) ;

		}

		if( mq_getattr ( md , &attr ) ) {

				perror("ERROR");

				exit ( EXIT_FAILURE ) ;

		}

	//	printf("%d\n",attr.mq_msgsize);

		while ( var ) {
	
		if (  (mq_receive ( md , buffer, attr . mq_msgsize + 1 , &prio ) ) == -1 ) {

				perror("ERROR");

				exit (EXIT_FAILURE) ;

		}
		
		printf ("the message is %s \n",buffer);

		var--;

		}

		if ( ( mq_unlink( "/mq" ) ) == -1 ) {

				perror ("ERROR") ;

				exit ( EXIT_FAILURE ); 

		}

}
