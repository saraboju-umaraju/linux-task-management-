#include    <uma.h>
#include    <signal.h>
int _h (  ) ;

int main (void) {

		printf("hello\n");

		signal ( SIGSEGV , _h ) ;

		printf("%s\n",1);

}
int _h ( ) 
{
		long long static int i = 8;

		int a[4] ;

		signal ( SIGSEGV , SIG_IGN ) ;
		
		while ( i != 0 ) {

				a [ i ] = i + 2 ;

				printf("%d \n", a [ i++ ] );

		}

}

