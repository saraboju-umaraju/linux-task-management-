#include	<uma.h>

int main (int c , char *v[]) {

		printf("MY PID IS %d\n",getpid());

		for ( int i = 0; i < c ; i++ ) 

				printf("%s\n",v[i]);

		return 0 ; 

}



