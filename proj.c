/* INCLUDES */

#include <stdio.h>
#include <string.h>
#include "funcoes.h"

/* Defines */

#define MAX_CHAR 65535

/* string defines */
#define HELP "help"
#define SET "set"
#define QUIT "quit"

/*FUNCAO MAIN*/

/*
  main: () -> int
  Primeira funcao a ser executada, trata de reconhecer e processar o input para cada função
*/

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
            /* mover o pointer para a frente na string para tirar o primeiro white space */
        }
    }
    while(strcmp(input, QUIT) != 0);
    return 0;
}