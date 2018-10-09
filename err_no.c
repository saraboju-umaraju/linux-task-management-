#include <stdio.h>
#include <errno.h>
#include <string.h>

//extern int errno ;

int main () {

   FILE * pf;
   int errnum = 0 ;
   pf = fopen ("unexist.txt", "w");
	

	while ( errnum < 135 ) {

	      printf( "%50s	%d\n", strerror( errnum ) , errnum);
		
			errnum ++ ;
}
   return 0;
}
