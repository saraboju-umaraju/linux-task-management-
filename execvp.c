#include    <stdio.h>
#include    <unistd.h>
int main (void) 
{
	char *p[] = { "ls" ,"-l" , NULL} ;
	execvp(p[0],p);
}
