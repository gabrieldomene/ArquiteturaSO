#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int status;
    int x;
    
    x = fork();
    
    if(x == 0){
        //processo filho
        execl("/bin/ls",  "ls", "-la", NULL);
    }else{
        wait(&status);
        printf("Processo terminado");
    }
    
    
    return 0;
}