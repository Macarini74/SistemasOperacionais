#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *amsg;

void handler(int signum){
	write(1, amsg, strlen(amsg));
}

void printsinc(char* msg, int segundos){
	msg = malloc(strlen(msg)*(sizeof(char)));
	strcpy(amsg, msg);
	
	signal(SIGALRM, handler);
	
	while(1){
		alarm(segundos);
		pause();
	}

}

int main(){

	printsinc("Ola\n", 5);
	
	return 0;

}
