#include	<stdio.h>
#include	<pthread.h>
#include	<stdlib.h>

#define NUM_THRDS 3
#define TCNT 10
#define CNTLT 12

int cnt = 0;
int thrd_id[3] = {0,1,2};

pthread_mutex_t cnt_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cnt_cnd_mutex  = PTHREAD_COND_INITIALIZER;

void * fun(void *t)
{
	int my_id = (int )t;
	printf("start count :fun thread %d \n",my_id);
	
	pthread_mutex_lock(&cnt_mutex);
//	while(cnt < CNTLT) {
		printf(" in condition wait \n");
		pthread_cond_wait(&cnt_cnd_mutex,&cnt_mutex);

		printf("  condition wait sucess \n");
		printf("fun thread id %d cond signal recevied \n ",my_id);
		cnt += 125;
		printf("fun thread id %d count noe = %d \n \n ",my_id,cnt);

//	}
	pthread_mutex_unlock(&cnt_mutex);
	pthread_exit(NULL);
	
}
void * fun1(void *t)
{
	int i;
	int my_id = (int )t;
	for(i = 0; i < TCNT; i++) {
		pthread_mutex_lock(&cnt_mutex);
		cnt++;

	if(cnt == CNTLT) {
	pthread_cond_signal(&cnt_cnd_mutex);
		printf("fun1 thread id %d count is %d\n ",my_id,cnt);
	}
		printf("fun1 thread id %d count no = %d unlocking mutex i = %d\n ",my_id,cnt,i);
	pthread_mutex_unlock(&cnt_mutex);
	}
	pthread_exit(NULL);
	
}
int main()
{
	int i;
	int rc;
	int t1 = 1;
	int t2 = 2;
	int t3 = 3;
	
	pthread_t t[3];

//	pthread_mutex_init(&cnt_mutex,NULL);
//	pthread_cond_init(&cnt_cnd_mutex,NULL);

	pthread_create(&t[0],NULL,fun,(void *)t1);
	pthread_create(&t[1],NULL,fun1,(void *)t2);
	pthread_create(&t[2],NULL,fun1,(void *)t3);

	//Wait for all threads to complete
	for(i= 0; i <NUM_THRDS; i++ ) {
		pthread_join(t[i],NULL);
	}
	
	printf("Main(): Waited on %d threads.Done \n",NUM_THRDS);
	
	pthread_mutex_destroy(&cnt_mutex);
	pthread_cond_destroy(&cnt_cnd_mutex);
	pthread_exit(NULL);

}
