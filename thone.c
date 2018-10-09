#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <syscall.h>


pthread_t tid2;

void * thread2()
{

		pthread_attr_t *inst1;

		struct sched_param param;

		inst1 = malloc(sizeof(pthread_attr_t));

		int policy;

		int inherit ;

		pthread_attr_getschedpolicy(inst1, &policy );

		pthread_attr_getschedparam(inst1, &param);

		pthread_attr_getinheritsched ( inst1 , &inherit);

		printf("policy : %d\n", policy);
		
		printf("inherie : %d\n", inherit);

		printf("Priority : %d\n", param.sched_priority);
		
	printf("%d\n",errno = pthread_join(tid2, NULL ) );

	perror("error");
}

int main()
{
		int status;
		
		
		pthread_create(&tid2,NULL,thread2,NULL);

		pthread_exit ( NULL ) ;
		
		return 0;
}
