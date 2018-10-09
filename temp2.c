#include	<stdio.h>

#include	<stdlib.h>

#include	<_val.h>

#include	<pthread.h>

#define NOT_FULL _index != 5

#define NOT_EMPTY _index != -1

short int a[5] ;

volatile int i = 4 ;

int _index = 0 ;

pthread_mutex_t mutex ;

void pro ( ) {

		while ( 1 ) {

		while ( i % 2 ) ;
	
		pthread_mutex_lock ( & mutex ) ;

		puts(UND"iam producer in charge"Z);

		while ( NOT_FULL ) {

		a [_index] = _val() ; 

		printf(R"i produced %d\n"Z, a[_index++] );

		}

		_index--;

		i++;

		sleep (1);

		pthread_mutex_unlock ( &mutex )  ;

		}

}
void con ( ) {

		while (1) {

		while ( ! ( i % 2 )  ) ; 

		pthread_mutex_lock ( & mutex ) ;
		
		puts(UND"iam consumer in charge"Z);

		while( NOT_EMPTY ) {

		printf(R"i have consumed %d\n"Z , a[_index--]);

		sleep (1);

		}
	
		_index++;

		i++;

		sleep(1);

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

