#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define N_THREAD 100

void *minhathread(void *arg)
{
    pthread_t x;
    x = pthread_self();
    printf("Nova thread criada. TID = %ld!!\n", x);
    pthread_exit(0);
}

int main()
{
    int i = 0;
    pthread_t thread[N_THREAD];
    printf("Antes de criar as threads\n");
    for(i = 0; i < N_THREAD; i++)
    {
        pthread_create(&thread[i], NULL, minhathread, NULL);
    }

    for (i = 0; i < N_THREAD; i++)
    {
        pthread_join(thread[i], NULL);
    }

    printf("Fim das thread\n");
    return 0;
}