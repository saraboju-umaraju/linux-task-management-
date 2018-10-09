#include    <uma.h>
int i;
int main (void) {

		if((fork())==0)

		printf("child %d\n",getpid());

		else
		printf("parent %d\n",getpid());
				
	//	sleep(1);	
		
//		fork();
	
//		printf("!ST TIME\n %d \n" , i++);

//		printf("ABBA NI DABB\n %d \n",i++);
}
