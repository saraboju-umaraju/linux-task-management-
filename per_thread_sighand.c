#include <pthread.h>
#include <signal.h>
#include <errno.h>

static pthread_key_t  thread_SIG_handler_key;

static void process_SIG_handler(int signum, siginfo_t *info, void *context)
{
    void (*func)(int, siginfo_t *, void *);

    *((void **)&func) = pthread_getspecific(thread_SIG_handler_key);
    if (func)
        func(signum, info, context);
}

static int set_thread_SIG_handler(void (*func)(int, siginfo_t *, void *))
{
    sigset_t block, old;
    int result;

    sigemptyset(&block);
    sigaddset(&block, SIG); /* Use signal number instead of SIG! */
    result = pthread_sigmask(SIG_BLOCK, &block, &old);
    if (result)
        return errno = result;

    result = pthread_setspecific(thread_SIG_handler_key, (void *)func);
    if (result) {
        pthread_sigmask(SIG_SETMASK, &old, NULL);
        return errno = result;
    }

    result = pthread_sigmask(SIG_SETMASK, &old, NULL);
    if (result)
        return errno = result;

    return 0;
}

int install_SIG_handlers(const int signum)
{
    struct sigaction act;
    int result;

    result = pthread_key_create(&thread_SIG_handler_key, NULL);
    if (result)
        return errno = result;

    sigemptyset(&act.sa_mask);
    act.sa_sigaction = process_SIG_handler;
    act.sa_flags = SA_SIGACTION;
    if (sigaction(signum, &act, NULL))
        return errno;

    return 0;
}
