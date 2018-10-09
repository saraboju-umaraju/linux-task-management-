#include	<stdio.h>
#include	<stdlib.h>
#include	<pthread.h>
#include	<semaphore.h>

int money = 4000 ;

int val = 0 ;

pthread_mutex_t lock ;

void *atm ( ) 
{
	pthread_mutex_lock ( &lock ) ;
	printf("money withdrawn and current balance is %d through atm 1\n",money);
	money-=1000;
	val++;
	pthread_mutex_unlock ( &lock ) ;
}
void *shop ( ) 
{
	while ( val != 1 );
	pthread_mutex_lock ( &lock ) ;
	printf("money withdrawn and current balance is %d through shop 2\n",money);
	money-=1000;
	val ++;
	pthread_mutex_unlock ( &lock ) ;
}
void *movie ( ) 
{
	while ( val != 2 ); 
	pthread_mutex_lock ( &lock ) ;
	printf("money withdrawn and current balance is %d through movie 3\n",money);
	money-=1000;
	val++;
	pthread_mutex_unlock ( &lock ) ;
}
void *net ( ) 
{
	while ( val != 3 ) ;
	printf("money withdrawn and current balance is %d through net 4\n",money);
}
int main ( void ) 
{
	pthread_t one ;
	pthread_t two ;
	pthread_t three ;
	pthread_t four ;

	pthread_mutex_init(&lock , NULL);

	if ( ( pthread_create ( &one , NULL , &atm , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}
	if ( ( pthread_create ( &two , NULL , &shop , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}
	if ( ( pthread_create ( &three , NULL , &movie , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}
	if ( ( pthread_create ( &four , NULL , &net , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}

		pthread_join ( one , NULL ) ;
		pthread_join ( two , NULL ) ;
		pthread_join ( three , NULL ) ;
		pthread_join ( four , NULL ) ;

		return 0 ;
}
