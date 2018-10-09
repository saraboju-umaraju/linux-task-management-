#include	<stdlib.h>

int main ( void )
{
	char *p = malloc (120);

	strcpy ( p , "killerwhale");

	printf("%zu\n",strlen (p));

	printf("%zu\n",sizeof (*p));

}
