#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_THREADS 5
volatile unsigned int g_ExitFlag = 0;
sem_t g_Sem;
void *ThreadFunc(void *pContext)
{
		unsigned int tid = ( unsigned int )pContext;
		while (g_ExitFlag == 0)
		{
				sem_wait(&g_Sem);
				printf("Thread %d running.\n", tid);
		}
		printf("Thread %d exiting.\n", tid);
		return NULL;
}

int main(int argc, char *argv[])
{
		unsigned int i = 0;
		pthread_t th;
		(void)argc;
		(void)argv;

		sem_init(&g_Sem, 0, 0);

		for (i = 0; i < NUM_THREADS; ++i)
		{
				pthread_create(&th, NULL, ThreadFunc, (void *)i);
				pthread_detach(th);
		}

		for (i = 0; i < (NUM_THREADS * 4); ++i)
		{
				if (i == 15)
				{
						g_ExitFlag = 1;
				}
				sem_post(&g_Sem);
				sleep(1);
		}
		return 0;
}
