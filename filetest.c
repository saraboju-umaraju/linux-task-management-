#include	<stdio.h>

int main ( void )
{

	char buffer[12]="";
	
	FILE *fp = fopen ("kill", "r") ;

	fread ( buffer , 10 , 1 , fp ) ;
	puts(buffer);
	fread ( buffer , 10 , 1 , fp ) ;
	puts(buffer);
	fread ( buffer , 10 , 1 , fp ) ;
	puts(buffer);
	fread ( buffer , 10 , 1 , fp ) ;
	puts(buffer);

}
	
	
