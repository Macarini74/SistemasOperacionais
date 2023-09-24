#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int countC = 0;

void handlerZ(int signum) {
    printf("Você apertou Ctl-C '%d' vezes\n", countC);
    countC = 0;
}

void handlerC(int signum) {
    countC++;
    if (countC == 3) {
        printf("Realmente deseja sair? [Y/n]: ");
        char response;
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
            printf("Saindo...\n");
            exit(EXIT_SUCCESS);
        } else if (response == 'N' || response == 'n') {
            printf("Continuando...\n");
            countC = 0;
        }
    }
}

void handlerAlrm(int signum) {
    printf("\nDemorou muito para responder. Saindo...\n");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, handlerC);
    signal(SIGTSTP, handlerZ);
    signal(SIGALRM, handlerAlrm);

    while (1) {
        alarm(5);
        pause();
    }

    return 0;
}
