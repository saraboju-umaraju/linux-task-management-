#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
	sem_t *fd = sem_open("/file",O_RDWR);
	int i = 10;

	int value ;
 
	sem_getvalue(fd, &value);
	printf("value is %d\n",value);
	
	sem_wait(fd) ;
	while (i) {	
		printf ("second process\n");
sleep(2);
i--;
	}
	sem_post(fd);
}
