#include	<stdio.h>
#include	<pthread.h>
#include	<stdlib.h>
#include	<string.h>
#include	<time.h>

//int current = 0;

typedef struct _alarm_{
			time_t seconds;
			char message[64];
			struct _alarm_ *link;
}al_time;
	
al_time *head = NULL;
pthread_mutex_t *mutex;
//pthread_cond_t *cond;

void* thread_func (void *p) {
	al_time *my_time = (al_time *) p;
	int status;
	
	while(1){

		if (head) {
			
			if(head->seconds == (int) time(NULL)) {
	
				status = pthread_mutex_lock(mutex);
			
				if(status != 0)
					printf("Lock condition\n");
			
				my_time = head;
			
				head = head->link;
			
				printf("\nAlaram :  %s is compleated\n", my_time->message);
			
				free(my_time);

				status = pthread_mutex_unlock(mutex);
			
				if(status != 0)
					printf("Unlock condition\n");
			}
		}
//	else {
//		sleep(1);
//	}
	}
}


int main(void)
{
	pthread_t th_id;
	int status;
	al_time *my_time = NULL;
	al_time *temp = NULL;
	al_time *temp2 = NULL;
	char line[100];

	time_t mytime;

	printf("%d\n", (int)time(NULL));

	status = pthread_create(&th_id, NULL, thread_func, head);
	
	if(status != 0)
		printf("Thread failed. %s\n", (char *) strerror(status));

	mutex = malloc(sizeof(pthread_mutex_t));
	
	if(mutex == NULL) {
		printf("Malloc for mutex failed\n");
		exit(0);
	}

	status = pthread_mutex_init(mutex, NULL);
	
	if(status != 0)
		printf("Init condition\n");

	while(1){

		printf("Alaram> ");
		
		if(fgets(line, sizeof(line), stdin) == (char *) NULL) exit(0);
		
		if(strlen(line) <= 1) continue;

		my_time = malloc(sizeof(al_time));
		
		if(my_time == NULL) {
			printf("Malloc is failed\n");
			exit(0);
		}

		if(sscanf(line,"%d %64[^\n]",(int *) &(my_time->seconds), my_time->message) < 2) {
			
			fprintf(stderr, "Bad command\n");
			
			free(my_time);
			
			exit(0);
		}
		else
			my_time->seconds = my_time->seconds + (int) time(NULL);

		status = pthread_mutex_lock(mutex);
		
		if(status != 0)
			printf("Lock condition\n");

		if(head == NULL) {
			
			my_time->link = head;
			
			head = my_time;
		}

		else if(head->seconds > my_time->seconds) {
			
			my_time->link = head;
			
			head = my_time;
		}
		else {
			temp = head;

			while(temp){

				if(my_time->seconds > temp->seconds){
					
					temp2 = temp;
					
					temp = temp->link;
				}
				else{
					temp = temp2;
					break;
				}
			}

			if(temp2 != NULL)
				temp = temp2;

			my_time->link = temp->link;
			
			temp->link = my_time;
		}

		status = pthread_mutex_unlock(mutex);
		
		if(status != 0)
			printf("Unlock condition\n");
	}
	return 0;
}
