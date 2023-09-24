/*Faça um programa para disparar uma mensagen de bons estudos a cada 10 segundos utilizando a API posix do linux.*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void handler(int signum){
    write(1, "Bons Estudos!!\n", 16);
}

int main(){


    signal(SIGALRM, handler);

    while(1){
        alarm(3);
        pause();
    }

    return 0;
}