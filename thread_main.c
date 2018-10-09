#include	<uma.h>
#include	<stdlib.h>
#include	<pthread.h>
void thread1_main();

void thread2_main();

int main( void) {

		pthread_attr_t attr;

		int status ;

		pthread_t thread1;

		pthread_t thread2;

		pthread_attr_init ( &attr ) ;
		
		pthread_attr_setstacksize( &attr , 1024*1024 );

		printf("creating athread\n");

		if ( (  pthread_create ( &thread1 , &attr , thread1_main , NULL ) ) ) {

				puts("thread creation failed\n");

				exit(EXIT_FAILURE);

		}

		printf("creating thread 2\n");

		if ( ( pthread_create ( &thread2 , &attr , thread2_main , NULL ) ) ) {

				puts("thread creation failed\n");

				exit(EXIT_FAILURE);

		}
	
		pthread_join(thread1 , NULL);
		
		pthread_join(thread2 , NULL);

		return 0 ; 

}

void  thread1_main( void ) {

		unsigned int run_cnt ;
		
		unsigned int exec_period_usecs ;

		struct timeval ts ;

		exec_period_usecs = 1000000 ;

		printf("thread1 started , execution period = %d Usec \n" , exec_period_usecs);

		run_cnt = 0 ;

		while( 199 ) {
		
				usleep(exec_period_usecs);
		
				gettimeofday(&ts , NULL );

				printf("%06lu , %06lu : -- thread1 run count = %d --\n" , (unsigned int)ts.tv_sec,(unsigned int)ts.tv_usec, run_cnt);

				run_cnt+=1 ;

		}

}
		

void  thread2_main( void ) {

        unsigned int run_cnt ;

        unsigned int exec_period_usecs ;

        struct timeval ts ;

        exec_period_usecs = 5000000 ;

        printf("thread2 started , execution period = %d Usec \n" , exec_period_usecs);

        run_cnt = 0 ;

        while( 199 ) {

                usleep(exec_period_usecs);

                gettimeofday(&ts , NULL );

                printf("%06lu , %06lu : -- thread2 run count = %d --\n" , (unsigned int)ts.tv_sec,(unsigned int)ts.tv_usec, run_cnt);

                run_cnt+=1 ;

        }

}

