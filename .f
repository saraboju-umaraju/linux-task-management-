#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>

mqd_t md ;

struct mq_attr attr ;

int main ( void ) {

		struct stat inst ;

		char buffer[1024] = "";

		int index = 0 ;

		char ch ;

		int fd  = open( "./basic_file.txt" , O_RDWR) ;
		
		FILE *fp  = fopen( "./basic_file.txt" , "r") ;

		attr . mq_maxmsg = 4 ;
		
		attr . mq_msgsize = 1024 ;

		if ( ( md = mq_open ( "/mq" , O_CREAT | O_WRONLY , 0777 , &attr ) ) == -1 ) {

			perror("opening message queue");

			exit ( EXIT_FAILURE ) ;

		}

		fstat  ( fd , &inst ) ;

		fread ( buffer , inst . st_size / 4 , 1 , fp ) ;

		if ( mq_send ( md , buffer , strlen( buffer ) , 1 ) == -1 ) {
	
			puts("hi");

		}

		fread ( buffer , inst . st_size / 4 , 1 , fp ) ;
		
		mq_send ( md , buffer , strlen( buffer ) , 1 ) ;

		fread ( buffer , inst . st_size / 4 , 1 , fp ) ;
		
		mq_send ( md , buffer , strlen( buffer ) , 1 ) ;
		
		while ( ( ch = fgetc ( fp ) ) != EOF ) 

				buffer [ index++ ] = ch ;
				
				buffer [ index++ ] = '\0' ;

		mq_send ( md , buffer , strlen( buffer ) , 1 ) ;

}
