#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int x, y;
    x = fork();
    
    if(x > 0){
        printf("Eu sou o processo pai, ID=%i", getpid());
    }
    else if( x == 0)
    {
        printf("\nEu sou o filho, ID=%i e meu pai é ID=%i", getpid(), getppid());
    }
    else{
        printf("Erro");
    }
    
    return 0;
}