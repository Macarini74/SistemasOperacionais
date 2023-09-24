/*
Um procedimento para contar o número de vezes que o usuário enviou o sinal SIGINT para o processo em execução.
 Pressionar Ctl-C no teclado envia esse sinal.
 Quando o processo recebe o sinal SIGTSTP (Ctl-Z), ele deve imprimir no terminal o número de sinais SIGINT que recebeu.
 Depois de receber 3 sinais SIGINT, o programa deve perguntar se o usuário deseja sair do programa.
 Se o usuário não responder em 20 segundos, um sinal SIGALRM deve forçar a saída do programa.
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void handlerAlarm(int signum){
    write(1, "Saindo...\n", 10);  
    exit(1);
}

void handlerC(int signum){
    count++;
    char op;

    if(count == 3){
        write(1, "\nDeseja sair do programa? [y/n]\n", 32);
        
        alarm(3);

        read(0, &op, sizeof(char));
        
        if(op == 'y' || op == 'Y'){
            int cont = count + '0';
            write(1, "\nCtrl C Apertado ", 18);
            write(1, &cont, 1);
            write(1, " vezes\n", 7);

            write(1, "Saindo...\n", 10);
            exit(1);
        }else if(op == 'n' || op == 'N'){
            write(1, "Continuando...\n", 15);
            count = 0;
        }else{
            write(1, "Escolha invalida, continuando\n", 30);
            count = 0;
        }
        pause();
    }
}

void handlerZ(int signum){
    int cont = count + '0';
    write(1, "\nCtrl C Apertado ", 18);
    write(1, &cont, 1);
    write(1, " vezes\n", 7);
}


int main(){

    signal(SIGINT, handlerC);
    signal(SIGTSTP, handlerZ);
    signal(SIGALRM, handlerAlarm);

    while(1);

    return 0;
    
}