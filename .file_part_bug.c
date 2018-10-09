#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>

int val = 0 ;
char buffer[1024];
int prio = 0 ;
pthread_mutex_t lock ;
pthread_cond_t cond ;
struct mq_attr attr; 
mqd_t md ;
FILE *new_file ;

void *one_thread ( )
{

		pthread_mutex_lock ( &lock ) ;
		if (( md = mq_open ( "/mq" , O_RDONLY  , 0777 , NULL ) ) == -1 ) {
				perror("ERROR");
				exit ( EXIT_FAILURE ) ;
		}
		if( mq_getattr ( md , &attr ) ) {
				perror("ERROR");
				exit ( EXIT_FAILURE ) ;
		}
		if (  (mq_receive ( md , buffer, attr . mq_msgsize + 0 , &prio ) ) == -1 ) {
				perror("ERROR");
				exit (EXIT_FAILURE) ;
		}
		//fprintf (new_file , "%s",buffer);
		printf("%d\n",strlen(buffer));
		printf( "one %d\n" ,fwrite(buffer , 1 , strlen(buffer) , new_file ) ) ;
		val++;
		pthread_cond_broadcast ( &cond ) ;
		pthread_mutex_unlock ( &lock ) ;
}
void *two_thread ( )
{

		pthread_mutex_lock ( &lock ) ;
		if ( val != 1 )
				pthread_cond_wait ( &cond , &lock ) ;
		if (  (mq_receive ( md , buffer, attr . mq_msgsize + 0 , &prio ) ) == -1 ) {
				perror("ERROR");
				exit (EXIT_FAILURE) ;
		}
		//fprintf (new_file , "%s",buffer);
		fwrite(buffer , strlen(buffer) , 1 , new_file );
		printf( "two %d\n" ,fwrite(buffer , 1 , strlen(buffer)  , new_file ) ) ;
		val ++;
		pthread_cond_broadcast ( &cond ) ;
		pthread_mutex_unlock ( &lock ) ;
}
void *three_thread ( )
{
		pthread_mutex_lock ( &lock ) ;
		if ( val != 2 )
				pthread_cond_wait ( &cond , &lock ) ;
		if (  (mq_receive ( md , buffer, attr . mq_msgsize + 0 , &prio ) ) == -1 ) {
				perror("ERROR");
				exit (EXIT_FAILURE) ;
		}
		//fprintf (new_file , "%s",buffer);
		fwrite(buffer , strlen(buffer) , 1 , new_file );
		printf( "three %d\n" ,fwrite(buffer , 1 , strlen(buffer)  , new_file ) ) ;
		val++;
		pthread_cond_broadcast ( &cond ) ;
		pthread_mutex_unlock ( &lock ) ;
}
void *four_thread() 
{
		pthread_mutex_lock ( &lock ) ;
		if ( val != 3 )
				pthread_cond_wait ( &cond , &lock ) ;
		if (  (mq_receive ( md , buffer, attr . mq_msgsize + 0 , &prio ) ) == -1 ) {
				perror("ERROR");
				exit (EXIT_FAILURE) ;
		}
		//	fprintf (new_file , "%s",buffer);

		printf( "four %d\n" ,fwrite(buffer , 1 , strlen(buffer) , new_file ) ) ;
		mq_unlink("/mq");
		pthread_mutex_unlock ( &lock ) ;

}
int main ( int argc , char **argv ) {

		pthread_t one ;
		pthread_t two ;
		pthread_t three ;
		pthread_t four ;

		pthread_mutex_init(&lock , NULL);
		pthread_cond_init(&cond , NULL);

		struct stat inst ;
		int index = 0 ;
		char ch ;
		if (argc < 2) {
				printf ("File Missing\n");
				return;
		}
		mq_unlink("/mq");
		int fd  = open( argv[1] , O_RDWR) ;
		FILE *fp  = fopen( argv[1] , "r") ;
		new_file  = fopen( "./new_file.txt" , "w") ;

		attr . mq_maxmsg = 10 ;
		attr . mq_msgsize = 1024 ;

		if ( ( md = mq_open ( "/mq" , O_CREAT | O_WRONLY , 0777 , &attr ) ) == -1 ) {
				perror("opening message queue");
				exit ( EXIT_FAILURE ) ;
		}
		fstat  ( fd , &inst ) ;
		printf("size is %d\n",inst . st_size) ;
		printf ("partition is %d\n",inst . st_size / 4) ;
		if ( (printf ("fread returned %d\n",fread ( buffer , 1 , inst . st_size / 4 , fp )) ) == 0 ) {
				perror("reading data");
				exit ( EXIT_FAILURE ) ;
		}
		puts(buffer);	
		printf("size of 1st is %d\n",inst . st_size / 4);
		if ( mq_send ( md , buffer , inst . st_size / 4 , 1 ) == -1 ) {
				perror("sending message");
				exit( EXIT_FAILURE );
		}

		if ( fread ( buffer , inst . st_size / 4  , 1 , fp ) == 0) {
				perror("sending message");
				exit ( EXIT_FAILURE ) ;
		}

		puts(buffer);	
		if ( ( mq_send ( md , buffer , inst . st_size / 4 , 1 ) ) == -1 ) {
				perror("sending message");
				exit ( EXIT_FAILURE ) ;
		}

		if ( fread ( buffer , inst . st_size / 4 , 1 , fp ) == 0 ) {
				perror("sending message");
				exit ( EXIT_FAILURE ) ;
		}

		puts(buffer);	
		if ( mq_send ( md , buffer , (inst . st_size / 4 )   , 1 ) == -1) {
				perror("sending message");
				exit ( EXIT_FAILURE ) ;
		}

		if ( fread ( buffer , (inst . st_size / 4 + inst . st_size % 4 ), 1 , fp ) == 0 ) {
				perror("sending message");
				exit ( EXIT_FAILURE ) ;
		}

		puts(buffer);	
		if ( mq_send ( md , buffer , (inst . st_size / 4 + inst . st_size % 4 )  , 1 )  == -1 ) {
				perror("sending message");
				exit ( EXIT_FAILURE ) ;
		}

		if ( ( pthread_create ( &one , NULL , &one_thread , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}
		if ( ( pthread_create ( &two , NULL , &two_thread , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}
		if ( ( pthread_create ( &three , NULL , &three_thread , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}
		if ( ( pthread_create ( &four , NULL , &four_thread , NULL ) ) ) {
				perror("thread creation");
				exit ( EXIT_FAILURE ) ;
		}
		pthread_join ( one , NULL ) ;
		pthread_join ( two , NULL ) ;
		pthread_join ( three , NULL ) ;
		pthread_join ( four , NULL ) ;


}
