#include    <uma.h>
int main (void) {
	while( 1 && fork())
	{
		if(1)
			printf("HAPPY HANGING\n		%d\n" ,getpid());

	}
}
