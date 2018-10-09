#include    <uma.h>

int main (void) {

		int r;
		int *s;

		r=fork();

		if(r == 0)
		{

				printf("child %d   PPID %d\n",getpid(), getppid());
								while(1);
				exit(2);

		}
		else{

				
				printf("parent %d pid %d\n",getpid(),getppid());
//				wait(s);
//				printf("%d\n",*s);
	//			while(1);
			}
}
