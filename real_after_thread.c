#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<linux/sched.h>
#include	<pthread.h>


int x = 10;
void* thread(void* p )

{

	struct sched_param param;

	param . sched_priority = 98;
 
	if(pthread_setschedparam(pthread_self(), SCHED_FIFO, &param) != 0){		/* changing  properties of a thrread  within thread  */

		printf("Error in setschedparam\n");

		exit(1);

	}

	printf("in Thred\n");

	int fd = open("/dev/myChar", O_RDWR);

	if(fd == -1){

		printf("Open failed\n");
		exit(1);
	}	

	ioctl(fd,getpid(), &x );

	return NULL;

}

int main(void)

{

	pthread_t th_id;
	int *retval;

	pthread_attr_t  attr;

	pthread_attr_init(&attr);


	if((pthread_create(&th_id, &attr, thread, NULL) != 0)){		/* creating thread */

		printf("thread creation failed\n");
		
		exit(1);

	}

	pthread_join(th_id, (void**)&retval);

	pthread_exit(NULL);

	return 0;

}
