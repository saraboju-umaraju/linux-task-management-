#include <uma.h>
#include <unistd.h>
extern char **environ;


/*static int a;

  void _isr () {

  printf ("%d \n",a++);

  if(a==101) 

  exit(-1);

  }*/
int main (int argc,char *argv[] )


{

		char *a[] = { "ls","-l",NULL};

		//   signal(11,_isr);

		// printf ("%s\n",*(argv + 1));

		// l: for args seperated with commas 

		//v: for vectors i.e for arrays of strings

		//p: for include  normal path i.e check for predefined PATH //KIND OF

		//	execlp("google-chrome","-l","-i",NULL);//file name is more than enough , deal with single commands,can also give path,can use command line args variable list args no limit

		//		execl("/bin/ls","ls","-i",NULL);  //have to give path else fails
		//execl("/bin/ls",argv+1 ,argv+2 ,  NULL);  //have to give path else fails

		//		execv("/bin/ls",argv+1);  //have to give path else fails agrv[1] is path cant participate in exctn , 

		//		execv("/bin/ls",a);  //have to give path else fails agrv[1] is path cant participate in exctn , 

		//execvp(/*argv[1]*/argv[1],argv+1);  //path is your wish either here or through cmd line &  wants base of char** as second arg

		// execvp(/*argv[1]*/a[0],a);  //path is your wish either here or through cmd line &  wants base of char** as second arg

		//execvpe("ls", a, argv+2);
		//execle("/bin/ls", "ls" , "-l", NULL , argv+2);

		printf ("FAILED\n");

