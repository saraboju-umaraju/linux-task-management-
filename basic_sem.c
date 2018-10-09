#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

/* sem_wait will wait till the value of variable becomes greater than 0 
 * and decreses it by 1 and proceeds
 * if variable value is already it aquires lock and proceeds by
 * decreasing it by 1
 */

/*
 * sem post will increses variable value by 1
 * no matter what the previous value of variable
 */

sem_t sem ;

sem_t sem1;

int var = 0 ; 

void func( void ) 
{

		while(1) {

				sem_wait ( &sem1 ) ;

				printf("hii iam thread1  val is %d \n",sem);
				
				sleep(1);

				sem_post (&sem);

		}
}
void fun( void )
{
		while(1) {

				sem_wait( &sem ) ;

				printf("hii iam thread2  val is %d \n",sem);
				
				sleep(1);

				sem_post(&sem1);

		}
}

int main ( void ) {

		pthread_t t ;

		pthread_t t2 ;

		sem_init (&sem ,0 , 0 );
	
		sem_init (&sem1 , 0 ,1) ;

		pthread_create(&t , NULL , func , NULL ) ;

		pthread_create(&t2 , NULL , fun , NULL ) ;

		pthread_join(t , NULL);

		pthread_join(t2 , NULL);

		return 199 ;

}
