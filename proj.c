#include <stdio.h>
#include <string.h>
#include "funcoes.h"

/* Defines */

#define MAX_CHAR 65535

/* string defines */
#define HELP "help"
#define QUIT "quit"

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
        }
    }
    while(strcmp(input, QUIT) != 0);
    return 0;
}