#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int status;
    int flag;
    int x, y;
    x = fork();
    int condition = 1;
    
    INICIO:while(condition){
        if(x > 0){
            //processo pai
            wait(1);
            if(flag == 0){
                printf("PRECESSO TERMINADO");
                condition = 0;
            }else{
                printf("NEW PROCESS\n");
                condition = 1;
                x = fork();
                break;
            }
            
        }else if(x == 0){
            //processo filho
            sleep(2);
            y = getpid();
            if (y%5 == 0){
                printf("%i é multiplo de 5\n", y);
                flag = 0;
                exit(0);
            }else{
                printf("%i nao é multiplo de 5\n", y);
                flag = 1;
                exit(1);
            }
        }else{
            printf("Erro");
        }
    }   
    return 0;
}