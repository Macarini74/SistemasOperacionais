/*
Excrever um programa C que cria uma árvore de 3 processos, onde o processo A faz um fork() criando um processo B, o processo B, por sua vez, faz um fork() criando um processo C.
Cada processo deve exibir uma mensagem "Eu sou o processo XXX, filho de YYY", onde XXX e YYY são PIDs de processos.
Utilizar wait() para garantir que o processo C imprima sua resposta antes do B, e que o processo B imprima sua resposta antes do A.
Utilizar sleep() (man 3 sleep) para haver um intervalo de 1 segundo entre cada mensagem impressa.*/

//Criar 3 processos
//Cada um escrever qual processo é, e filho de quem, pelo pid

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pidA, pidB, pidC;
    
    // Processo A
    pidA = getpid();
    printf("Eu sou o processo %d, filho de %d\n", pidA, getppid());

    // Processo B (criado por A)
    if ((pidB = fork()) == 0) {
        sleep(1); // Aguarda 1 segundo
        pidB = getpid();
        printf("Eu sou o processo %d, filho de %d\n", pidB, pidA);
        
        // Processo C (criado por B)
        if ((pidC = fork()) == 0) {
            sleep(1); // Aguarda 1 segundo
            pidC = getpid();
            printf("Eu sou o processo %d, filho de %d\n", pidC, pidB);
        } else {
            wait(NULL); // Espera o processo C terminar
        }
    } else {
        wait(NULL); // Espera o processo B terminar
    }
    
    return 0;
}
