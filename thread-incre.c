#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREAD 1000

void incremento();

void *minhathread(void *arg)
{
    int i = 0;
    pthread_t x;
    x = pthread_self();
    printf("Nova thread criada. TID = %ld!!\n", x);
    while(i < 100)
    {
        incremento();
        i++;
    }
}


int contador_global = 0;

int main()
{
    int j = 0;
    pthread_t threads[N_THREAD];
    for (j = 0; j < N_THREAD; j++)
    {
        pthread_create(&threads[j], NULL, minhathread, NULL);
    }

    for (j = 0; j < N_THREAD; j++)
    {
        pthread_join(threads[j], NULL);
    }

    printf("Contador = %i\n", contador_global);

    return 0;
}

void incremento()
{
    contador_global++;
}