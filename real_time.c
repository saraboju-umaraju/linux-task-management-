#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<linux/sched.h>
#include	<pthread.h>


int x = 10;
void* thread(void* p )

{

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
	int policy;
	pthread_attr_t attr;
	
	if(pthread_attr_init(&attr) != 0){

		printf("Error in init \n");

		exit(1);
	
	}


	struct sched_param param;

	if(pthread_attr_setschedpolicy(&attr, SCHED_RR) != 0){			/* Changing the policy */

		printf("Error in set_policy\n");

		exit(1);

	}

	param.sched_priority = 99;

	if( pthread_attr_setschedparam(&attr, &param) != 0){			/* Changing the priority */

		printf("Error in set_priority\n");	

		exit(1);

	}

	if(pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED) != 0){	/*  changing the properties of thread explicitly  */		

		printf("Error in set_inherit\n");

		exit(1);

	}

	if((pthread_create(&th_id, &attr, thread, NULL)) != 0){		/* creating the thread */

		printf("thread creation failed\n");

		exit(1);

	}

	pthread_join(th_id, (void**)&retval);

	pthread_exit(NULL);

	return 0;

}
