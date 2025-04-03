#include <stdio.h>
#include <pthread.h>

void *thread_routine(void *data)
{
    pthread_t pid;
    int *count;
    int i;

    i = 800;
    pid = pthread_self();
    count = (int *)data;

    printf("contagem: %d\n", *count);
    while (i > 0)
    {
        (*count)++;
        i--;
    }

    printf("contagem final: %d\n", *count);
    return (NULL);
}

int main()
{
    pthread_t tid1;
    pthread_t tid2;
    int count;

    count = 0;
    pthread_create(&tid1, NULL, thread_routine, &count);
    printf("count :%d\n" , count);
    pthread_create(&tid2, NULL, thread_routine, &count);
    printf("count :%d\n" , count);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("count :%d\n" , count);
    return(0);
}