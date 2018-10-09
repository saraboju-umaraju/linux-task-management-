#include    <uma.h>
#include    <malloc.h>
int main (void) {

		{

				int *p = malloc  ( 11 );

				printf("stabbed to hell %p\n",sbrk ( 0 ));

				malloc_stats();

		}
}

