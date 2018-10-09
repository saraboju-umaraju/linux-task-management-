#include    <uma.h>
#include	<time.h>
int main (void) {
		time_t t;
		
		time_t t2 ;

		time(&t);
		
		t2 = t + 9 ;

		int usable = 5 ;

		while ( t!=t2 ) {
		
				time(&t);

				if ( t = (t2 - usable ) ) {

						sleep(1);

						if (usable) 

						printf  ( "ready for %d seconds\n", usable--) ;

				}
				
//				printf("%u \n",t);
				
//				printf("%u \n",t2);
				
				//printf("%s\n",ctime(&t));
				
//				sleep(1);
				
				//system("clear");

		}
				printf ( "wake up you lazy pi\g ....!\n" );
}
