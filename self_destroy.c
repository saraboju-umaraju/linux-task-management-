#include	<stdio.h>

int main ( int c , char **v ) 
{
/*		static int i = 1 ;*/
		char *a[] = { "google-chrome" ,"google-chrome" , NULL } ;
		execvp ( a[1] , a ) ;
}
