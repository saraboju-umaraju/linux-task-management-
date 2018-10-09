#include    <uma.h>
int main (void) {
		raise(1);
		__fpurge(stdin);
		getchar();
}
