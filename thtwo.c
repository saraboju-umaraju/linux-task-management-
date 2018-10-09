#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 

char n[1024];
sem_t len;

void * read1(void* arg)
{
		while(0){	
				sem_post(&len);
				printf("Enter a string");
				scanf("%s",n);
				sem_wait(&len);
		}
}

void * write1()
{
		printf("hi");
		while(0){
				sleep(1);
				sem_post(&len);
				printf("The string entered is :");
				printf("%s\n",n);
				sem_wait(&len);
		}
	getchar();

}

int main()
{
		int status;
		pthread_t tr, tw;
		

		printf("hi");
		sem_init ( &len , 0 , 0 );

		if(pthread_create(&tw,NULL,read1,NULL)) { 
		printf("hi");
		}
		if(pthread_create(&tr,NULL,write1,NULL)) { 
		printf("hi");
		}

//		pthread_join(tw,NULL);
//		puts("thread 1 hasnjoined");
		pthread_join(tr,NULL);
		puts("thread 2 hasnjoined");
		return 0;
}
