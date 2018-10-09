#include    <uma.h>
int main (void) {
		pid_t id;

		id = fork () ;

		printf("pid is %d \n",id);

		if(id > 0 ) {
				printf("daddy process \n");
		}
		else if( id == 000 )  {
				printf("baby process \n");
		}
		else 
				printf("FORK HAS FAILED\n");
}
