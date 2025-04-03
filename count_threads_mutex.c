#include <stdio.h>
#include <pthread.h>

typedef struct p_count {

    int *count;
    pthread_mutex_t *mutex;
} count_t;

void *thread_routine(void *data)
{
    pthread_t pid;
    pthread_mutex_t *mutex;
    int *count;
    int i;
    count_t *data_struct;

    data_struct = (count_t *)data;
    mutex = data_struct->mutex;
    i = 800;
    pid = pthread_self();
    count = (int *)data_struct->count;

    pthread_mutex_lock(mutex);
    printf("contagem: %d\n", *count);
    pthread_mutex_unlock(mutex);
    while (i > 0)
    {
        pthread_mutex_lock(mutex);
        (*count)++;
        pthread_mutex_unlock(mutex);
        i--;
    }

    pthread_mutex_lock(mutex);
    printf("contagem final: %d\n", *count);
    pthread_mutex_unlock(mutex);
    return (NULL);
}

int main()
{
    pthread_mutex_t mutex;
    pthread_t tid1;
    pthread_t tid2;
    count_t data;
    int count;

    count = 0;
    pthread_mutex_init(&mutex , NULL);
    data.mutex = &mutex;
    data.count = &count;
    pthread_create(&tid1, NULL, thread_routine, &data);
    pthread_mutex_lock(data.mutex);
    printf("count :%d\n" , count);
    pthread_mutex_unlock(data.mutex);

    pthread_create(&tid2, NULL, thread_routine, &data);
    pthread_mutex_lock(data.mutex);
    printf("count :%d\n" , count);
    pthread_mutex_unlock(data.mutex);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_lock(data.mutex);
    printf("count :%d\n" , count);
    pthread_mutex_unlock(data.mutex);
    pthread_mutex_destroy(data.mutex);
    return(0);
}