#include    <uma.h>
int main (int c, char* v[]) {

		char *s[] = {"app","uma","raj",NULL};

		execvp("./app",s);

		printf("FAIL\n");

		return 0; 

}
