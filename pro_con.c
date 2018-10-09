#include	<stdio.h>

#include	<stdlib.h>

#include	<_val.h>

#include	<pthread.h>

char a[5] ;

static int i = 0 ;

pthread_mutex_t mutex ;

void pro ( ) {

		int usable = 0 ;

		while(1) { 

		while ( i != 5 ) {

		pthread_mutex_lock ( &mutex ) ;
		
		usable = _val(NULL) ;

		a[i++] = usable ;

		printf ( "I produced %d \n" , usable  ) ;

		pthread_mutex_unlock ( & mutex ) ;

	}
		
		if ( i == 5 )
		
		pthread_mutex_unlock ( & mutex ) ;

		}

}

void con ( ) {

		while (1) {

		pthread_mutex_lock ( & mutex ) ;
		
		while ( i != 0 ) {
		
		printf ("I consumed %d\n" , a[i--]) ; 

		sleep ( 1 ) ;

			}

		if ( i == 0 )
		
		pthread_mutex_unlock ( &mutex ) ;

		}
}
		
int main(void) {

		pthread_t one ;
		
		pthread_t two ;

	   	if ( pthread_mutex_init ( &mutex , NULL ) ) {

			puts("internal error");

			exit ( EXIT_FAILURE ) ;

			}

		if( pthread_create ( &one , NULL , (void*)&pro , NULL ) ) {

				puts("internal error");

				exit(EXIT_FAILURE);

		}

		        if( pthread_create ( &two , NULL ,(void*) &con , NULL ) ) {

                puts("internal error");

                exit(EXIT_FAILURE);

        }
		pthread_join( one , NULL ) ;
		
		pthread_join( two , NULL ) ;

		return 199 ;

}

