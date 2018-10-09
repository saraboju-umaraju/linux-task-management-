#include	<stdio.h>
#include	<stdlib.h>
#include	<pthread.h>
//#include	<semaphore.h>

int money = 4000 ;

int val = 0 ;

pthread_mutex_t lock ;
pthread_cond_t cond ;
pthread_cond_t cond3 ;
pthread_cond_t cond2 ;

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
	while ( val != 1 ) 
			pthread_cond_wait ( &cond , &lock ) ;
	printf("money withdrawn and current balance is %d through shop 2\n",money);
	money-=1000;
	val ++;
	pthread_mutex_unlock ( &lock ) ;
	pthread_cond_signal ( &cond2 ) ;
}
void *movie ( ) 
{
	pthread_mutex_lock ( &lock ) ;
	while ( val != 2 ) 
			pthread_cond_wait ( &cond2 , &lock ) ;
	printf("money withdrawn and current balance is %d through movie 3\n",money);
	money-=1000;
	val++;
	pthread_mutex_unlock ( &lock ) ;
	pthread_cond_signal ( &cond3 ) ;
}
void *net ( ) 
{
	while ( val != 3 ) 
			pthread_cond_wait ( &cond3 , &lock ) ;
	printf("money withdrawn and current balance is %d through net 4\n",money);
}
int main ( void ) 
{
	pthread_t one ;
	pthread_t two ;
	pthread_t three ;
	pthread_t four ;

	pthread_mutex_init(&lock , NULL);
	pthread_cond_init(&cond , NULL);
	pthread_cond_init(&cond2 , NULL);
	pthread_cond_init(&cond3 , NULL);

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
