#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <string.h>

typedef struct
{
		int       i;
		pid_t     pid;   // linux pid
		pid_t     tid;   // linux thread id
		pthread_t ptid;  // pthreads tid    
} data;

void *foo(void *args)
{
		data *p = (data *) args;

		p->pid  = getpid();
		p->tid  = syscall(SYS_gettid);
		p->ptid = pthread_self();

		return(p);
}

void spawnThreads(unsigned int numThreads)
{
		int ret;
		pthread_t *tids = malloc(sizeof(pthread_t) * numThreads);

		int i;

		//printf("SIZE id %zu \n",sizeof(pthread_t));

		for (i = 0; i < numThreads; i++)
		{
				data *dp = malloc(sizeof(data) * numThreads);
				memset(dp, '\0', sizeof(*dp));

				dp->i = i;

				ret = pthread_create(&tids[i], NULL, foo, (void *) dp);

				if ( ret != 0)
						perror("pthread create error");
		}

		for (int i = 0; i < numThreads; ++i)
		{
				data *status;

				printf("%u\n",tids[i]);

				ret = pthread_join(tids[i], (void *) &status);

				if ( ret != 0)
						perror("pthread join error");
				else
				{
						printf("thread num %d joined and reports pthreadId of %lu "
										"process pid of %d and linux tid of %d\n",
										status->i, status->ptid, status->pid, status->tid);

						free(status);
				}
		}

		free(tids);
}

int main(int argc, char *argv[])
{
		printf("main thread reports pthreadId of............ %lu "
						"process pid of %d and linux tid of %ld\n",
						pthread_self(), getpid(), syscall(SYS_gettid));

		spawnThreads(1);

		return (0);
}
