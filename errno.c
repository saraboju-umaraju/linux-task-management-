#include	<malloc.h>
#include	<errno.h>

int main ( void )
{
	char *ptr = malloc ( 1 ) ;
	printf("err val is %d\n", errno);
}
	
