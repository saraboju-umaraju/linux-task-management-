#include	<stdio.h>

#include	<_val.h>

#include	<pthread.h>

int var = 10;

int i = 1;

pthread_mutex_t mutex;

void
pro()
{

    while (1) {

        while (i == 1 && var) {

            printf(R "thread1 %d\n" Z, var--);

            sleep(1);

            i = 2;

        }

    }

}

void
con()
{
    while (1) {

        while (i == 2 && var) {

            printf(B "thread2 %d\n" Z, var--);

            sleep(1);

            i = 1;

        }

    }

}

int
main(void)
{

    pthread_t one;

    pthread_t two;

    if (pthread_create(&one, NULL, (void *)&pro, NULL)) {

        puts("internal error");

        exit(EXIT_FAILURE);

    }

    if (pthread_create(&two, NULL, (void *)&con, NULL)) {

        puts("internal error");

        exit(EXIT_FAILURE);

    }
    pthread_join(one, NULL);

    pthread_join(two, NULL);

    return 199;

}
