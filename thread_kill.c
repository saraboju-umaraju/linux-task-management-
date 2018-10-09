#include	<stdio.h>

#include	<signal.h>

#include	<pthread.h>

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

#include <unistd.h>   /* For SYS_xxx definitions */

//int syscall(int number, ...);

//int tgkill(int tgid, int tid, int sig);

pid_t global  ;

int _hand () {

	puts("hello");
	
	return 0 ;

}

void *thread ( void *xx) 
{
	int x = *(int*)xx ;

	signal ( SIGHUP , _hand ) ;

	while ( 1 )  {

		printf("iam thread %d ttid is %d \n" , x , syscall (SYS_gettid ) );

		sleep(1);

	}
}

void *thread_kill ( ) 
{
	
	printf("in thread %d\n" , pthread_self());

	printf("res id %d\n" , pthread_equal (  pthread_self() , getpid() ) );
	
	syscall ( SYS_tgkill ,getpid() , global , SIGKILL ) ;

	perror("syscall");

}

int main ( void ) 
{
	pthread_t id;

	int count = 0 ;

	printf("in main %d\n" , getpid());

	global = syscall (SYS_gettid ) ;

	while ( count < 10 ) {

		pthread_create ( &id , NULL , thread , &count ) ;

		count ++ ;

	}

	pthread_create ( &id , NULL , thread_kill , NULL ) ;

	pthread_exit  ( NULL ) ;

}
