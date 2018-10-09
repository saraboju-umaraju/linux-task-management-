#include	<uma.h>
#include	<pthread.h>

int array [5] ;

int function ( void  ) {

		int usable = 2 ;

		while ( usable-- ) {

		printf ("iam in execution little thread\n") ;

		sleep (1) ;

		}

}

typedef struct dabba {

		pthread_t mutex ;

//		int data ;

}_st;

_st inst ;

int fun ( void ) {


		int usable = 0 ;

		pthread_t id2; 

		if ( pthread_mutex_lock ( &inst.mutex  ) ){

				printf("filed\n");

				exit( EXIT_FAILURE ) ;

		}


		printf ( "in thread\n" ) ;

		while ( usable != 2 ) {

				printf (" elements of array [%d] %d \n",array[usable],usable) ;

				usable++;

		}
		if ( pthread_create ( &id2 , NULL , function , NULL ) ) {

				printf ( "internal error\n" );

				exit ( EXIT_FAILURE ) ;

		}

		printf ("waiting for grand little thread to join\n") ;

		pthread_join ( id2 ,NULL ) ;
		
		printf ("grand little thread attached\n") ;

		if ( pthread_mutex_unlock ( &inst.mutex  ) ){

				printf("filed\n");

				exit( EXIT_FAILURE ) ;

		}


		return 0 ;

}


int main ( void ) {

		pthread_t id ;


		int usable = 4 ;

		if ( pthread_mutex_init ( &inst.mutex , NULL ) ){

				printf("filed\n");

				exit( EXIT_FAILURE ) ;

		}

		if ( pthread_mutex_lock ( &inst.mutex  ) ){

				printf("filed\n");

				exit( EXIT_FAILURE ) ;

		}


		if (pthread_create ( &id , NULL , fun , NULL )) {

				printf ("thread creation failed sorry...!\n") ;

				exit ( EXIT_FAILURE ) ;

		}



		while ( usable ) {

				printf ("enter a element into array[%d]\n",usable) ;

				scanf ( "%d" ,&array[usable]) ;

				usable--;

		}

		if ( pthread_mutex_unlock ( &inst.mutex  ) ){

				printf("filed\n");

				exit( EXIT_FAILURE ) ;

		}

		printf ( "waiting for other thread to join \n" ) ;

		pthread_join ( id ,  NULL ) ;
		
		printf ( "other thread joined \n" ) ;

		if ( pthread_mutex_destroy ( &inst.mutex  ) ){

				printf("filed\n");

				exit( EXIT_FAILURE ) ;

		}

		return 0;


}
