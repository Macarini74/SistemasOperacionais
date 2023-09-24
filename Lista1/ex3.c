/*Crie um processo para printar na tela uma lista de processos em execução no sistema.

DICA: usar o programa ps*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Listando processos em execução:\n");
    system("ps aux");
    return 0;
}
