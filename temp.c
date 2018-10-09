#include	<stdio.h>

#include	<_val.h>

#include	<pthread.h>

#include	<stdlib.h>

char a[5] ;

volatile int i = 4 ;

pthread_mutex_t mutex ;

void pro ( ) {
		
		while ( 1 ) {

		while ( i % 2 ) ;
		
		pthread_mutex_lock ( & mutex ) ;

		printf (R"thread1 %d\n"Z, i) ;

		usleep(10000);

		i++;

		pthread_mutex_unlock ( &mutex )  ;

		}

}
void con ( ) {

		while (1) {

		while ( ! ( i % 2 )  ) ; 

		pthread_mutex_lock ( & mutex ) ;

		printf (B"thread2 %d\n"Z, i) ;
		
		usleep(10000);

		i++;

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

