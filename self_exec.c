#include    <uma.h>
int main (int c, char *argv[]) {
		if(c != 2){
				printf("totally crashed!!!\n");
				vfork();
				printf("bye\n");
				return 0;
}
else {
		int n = atoi(argv[1]);
		printf("%d \n",n);
		if(n < 100) {
				char nm[10];
				sprintf(nm,"%d",n+1);
				execl(argv[0],argv[0],nm,NULL);
		}
		return 0 ;
}
}
