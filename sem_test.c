#include	<semaphore.h>

sem_t sem ;

int main ( void ) 
{
	sem_init( &sem , 1 , 199 ) ;

	printf("val is %d\n",sem);

}
