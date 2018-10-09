#include    <uma.h>
#include    <stdlib.h>
#include    <signal.h>
#include    <linux/sched.h>

int fun ( void ) {

	printf ("success\n" ) ;

}

int main (void) {

	int *p ;

	if (! (p = malloc ( 4096 ) ) ) {

		printf ( "low on memory\n" ) ;

		exit ( EXIT_FAILURE ) ;
	}

	pid_t pid =/*fork(); */clone ( &main , p+4096 ,  11 | CLONE_VM , 0 ) ; //clone(&func, child_stack+STACK_SIZE, CLONE_SIGHAND|CLONE_FS|CLONE_VM|CLONE_FILES, NULL);


	perror("clone call");


	if ( pid ) {

		printf("%d %d PARENT\n",pid , getpid () );

		getchar();

	}
	if ( ! pid ) { 

		printf("CHILD\n");

	}

}


