#include    <uma.h>

#include    <fcntl.h>

#define SIZE 80

int main (void) {

		while( 1 ) {

				printf("_$");

				char buf[SIZE] = { '\0' };

				int i = 0;

				int j = 0;

				char *argv[SIZE];

				fgets(buf,SIZE,stdin);

				argv[0] = strtok( buf,"\n ");

				while ( argv[j] && j < SIZE ) {

						argv[++j] = strtok ( NULL , "\n ");

				}

				if ( fork() == 0 ) {
			
						execvp ( argv[0] , argv );

						printf("NO COMMAND\n");

						exit(0);

				}
				else {
						wait(NULL);

				}
		}
		return 0;
}
