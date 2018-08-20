#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *minhathread(void *arg)
{
    pthread_t x;
    x =  pthread_self();
    printf("Nova thread criada. TID = %ld!!", x);
    //pthread_exit(0);
}

int main()
{
   pthread_t thread;
   int flag;
    
    printf("Antes de criar a thread\n");

    pthread_create(&thread, NULL, minhathread, NULL);
    pthread_join(thread, NULL);
    return 0;
}