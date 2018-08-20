#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREAD 20800

pthread_mutex_t mutex;
int contador_global = 0;
void incremento();

void *minhathread(void *arg)
{
    int i = 0;
    pthread_t x;
    x = pthread_self();
    printf("Nova thread criada. TID = %ld!!\n", x);
    pthread_mutex_lock(&mutex);
    while(i < 100)
    {
        incremento();
        i++;
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{
    int j = 0;
    pthread_t threads[N_THREAD];
    pthread_mutex_init(&mutex, NULL); 
    for (j = 0; j < N_THREAD; j++)
    {
        pthread_create(&threads[j], NULL, minhathread, NULL);
    }

    for (j = 0; j < N_THREAD; j++)
    {
        pthread_join(threads[j], NULL);
    }
    pthread_mutex_destroy(&mutex); 

    printf("Contador = %i\n", contador_global);

    return 0;
}

void incremento()
{
    contador_global++;
}