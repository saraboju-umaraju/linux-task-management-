#include    <uma.h>
# include	<signal.h>
void _isr(int n) {

		printf("in old bus stop\n");
	
		signal(2,SIG_DFL);
}
int main (void) {

		void (*p) ();

				p=_isr;

		signal(2,p);

		printf("in main \n");
		
		getchar();

}

