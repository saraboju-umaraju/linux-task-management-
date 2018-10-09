#include    <uma.h>
int
main(void)
{
    int i = 9;
    while (i--)
        printf("%d+1\n", srand(100) % 10);
}
