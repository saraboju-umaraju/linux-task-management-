#include	<stdio.h>
#include	<stdlib.h>
#include	<pthread.h>
#include	<semaphore.h>

int money = 4000 ;
int val = 0 ;

pthread_mutex_t lock ;
pthread_cond_t cond ;
void *atm ( ) 
{
	pthread_mutex_lock ( &lock ) ;
	printf("money withdrawn and current balance is %d through atm 1\n",money);
	money-=1000;
	val++;
	pthread_mutex_unlock ( &lock ) ;
	pthread_cond_signal ( &cond ) ;
}
void *shop ( ) 
{
	pthread_mutex_lock ( &lock ) ;
	if ( val != 1 )
			pthread_cond_wait ( &cond , &lock ) ;
	printf("money withdrawn and current balance is %d through shop 2\n",money);
	money-=1000;
	val ++;
	pthread_mutex_unlock ( &lock ) ;
	pthread_cond_signal ( &cond ) ;
}
void *movie ( ) 
{
	pthread_mutex_lock ( &lock ) ;
	if ( val != 2 ) 
			pthread_cond_wait ( &cond , &lock ) ;
	printf("money withdrawn and current balance is %d through movie 3\n",money);
	money-=1000;
	val++;
	pthread_mutex_unlock ( &lock ) ;
	pthread_cond_signal ( &cond ) ;
}
void *net ( ) 
{
	if ( val != 3 ) 
			pthread_cond_wait ( &cond , &lock ) ;
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
