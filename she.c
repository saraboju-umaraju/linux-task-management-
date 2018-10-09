#include    <uma.h>

int main (void) {

		char *args[2];

		args[0] = "/usr/bin/clear";
		
		args[2]=NULL;

		execve(args[2],args,NULL);

		printf("EXEC FAILED\n");

		exit(0);

}


