#include <stdio.h>
#include <pthread.h>

void *thread_routine(void *data)
{
    pthread_t tid;

    tid = pthread_self();
    printf("sou uma thread e este é meu tid: %d\n", tid);
    return(NULL);
}

int main()
{
    pthread_t tid1;
    pthread_t tid2;

    pthread_create(&tid1, NULL, thread_routine, NULL);
    pthread_create(&tid2, NULL, thread_routine, NULL);
}