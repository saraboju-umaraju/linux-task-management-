#include    <stdio.h>
#include    <pthread.h>
#include    <sys/syscall.h>
#include    <sys/types.h>
void *create_thread(void *p)
{
    pid_t tgid;
    int x = (int)p;
//    getchar();
    printf("the actual TGID  of thread: %d\n",getpid());
    tgid = syscall(SYS_gettid);
    printf("the actual pid  of thread: %d\n",tgid);
    printf("In sub thread x = %d\n",x);
    return NULL;
}
int main(void)
{
    pid_t t_gid;
    pthread_t th_id;
    int status = 0;

    int p = 10;

    status = pthread_create(&th_id, NULL, &create_thread, (void *)p);

//	printf("%d \n",(int)status);
    printf("TGID of main: %d\n",getpid());

    printf("Main thrad\n");
    t_gid = syscall(SYS_gettid);
    printf("PID of thread: %d\n",t_gid);

    if(status != 0){
        printf("pthread_create failed\n");
        return 0;
    }

    pthread_exit(NULL);
    return 0;
}



