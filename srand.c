#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
		int i;
		unsigned int n;
		time_t t;

		n = 6;

		srand(getpid());

		for( i = 0 ; i < n ; i++ ) 
		{
				printf("%d\n", rand() % 50);
		}

		return(0);
}
