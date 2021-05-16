/* INCLUDES */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

/* Defines */

#define MAX_CHAR 65535

/* string defines */
#define HELP "help"
#define SET "set"
#define QUIT "quit"
#define PRINT "print"

/*FUNCAO MAIN*/

/*
  main: () -> int
  Primeira funcao a ser executada, trata de reconhecer e processar o input para cada função
*/

void init();

int main() 
{   
    /*Variavel que contem o comando a ser executado*/
    char input[MAX_CHAR + 1];
    /*Le carateres da stdin ate encontrar o caso terminal ou 
    um comando a executar*/
    do {
        scanf("%s", input);
        if (strcmp(input, HELP) == 0) {
            help();
        } else if (strcmp(input, SET) == 0) {
            fgets(input, (MAX_CHAR + 1), stdin);
            set(input);
        } else if (strcmp(input, PRINT) == 0) {
            print();
        }
    }
    while(strcmp(input, QUIT) != 0);
    return 0;
}