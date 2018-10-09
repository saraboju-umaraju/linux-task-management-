#include    <uma.h>
static int i = 0 ;
int main (void) {
		fork();
		fork();
		fork();
		fork();
		printf("HI %d \n",i++);
}
