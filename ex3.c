#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
		fork();
		char *a[]={"./a.out",NULL};
//		execv("./prcs1", &argv[1]); // GIVE ADDRESS OF 2nd element as starting point to skip source.txt
		fork();
		execv("../",a);
		printf("EXECV Failed\n");
}
