#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>

mqd_t md ;

int main ( void ) 
{

	int prio = 1  ;
	
	char buffer[20] = "";

	if ( ( md = mq_open ( "/mq" , O_RDONLY , 0777 , NULL ) ) == -1 ) {

	perror("open");

	exit ( EXIT_FAILURE ) ;

}
	if ( ( mq_receive ( "/mq" , buffer , 8192 + 1 , &prio ) ) == -1 ) {

	}

	mq_unlink("/mq");
	
	puts(buffer);

}
