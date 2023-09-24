/*
O status passado como parâmetro à função wait(&status) é, na verdade, o mecanismo de retorno de resultado do wait/waitpid.
Ao retornar, esta variável contém informações sobre o resultado da execução do processo filho.
Por exemplo, se um processo terminou normalmente (i.e., chamou exit), o comando WIFEXITED(status) retorna true.
Este comando retorna false se o processo foi abortado (e.g., segmentation fault) ou morto (e.g., kill).
Investigue no manual do wait no Linux (man wait) o funcionamento do comando WEXITSTATUS(status), e use-o para modificar o exercício anterior para calcular o 5!,
endo que cada processo pode executar apenas uma multiplicação.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

   int pid, status;

    pid = fork(); 

    if(pid < 0){
        printf("Erro na chamada fork.\n");
    }else if (pid == 0){
        sleep(1);

        printf("Processo B. PID = %d.\n", getpid());
        sleep(1);
        pid = fork();

        if(pid == 0){
            pid = fork();

            if(pid == 0){
                printf("Processo C. PID = %d.\n", getpid());
                exit(5);
            }else{
                wait(&status);
                exit(WEXITSTATUS(status)*4);
            }
        }


        wait(&status);
        exit(WEXITSTATUS(status) * 3);


    }else{
        printf("Processo A. PID = %d. \n", getpid());
        wait(&status);
        if(WIFEXITED(status)){
            sleep(1);
            printf("Programa rodou normalmente.\n");
            sleep(1);
            printf("5! = %d.\n\n", WEXITSTATUS(status)*2);
        }
        
    }


    return 0;
}