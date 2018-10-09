#include    <stdio.h>
struct gehdr
{
        unsigned char src_port ;

        unsigned char dest_port ;

        unsigned short len ;

        unsigned char *data ;
} ;

int main ( void )
{
    printf("size %zu\n", sizeof ( struct gehdr));

}

