#include <stdio.h>
#include "funcoes.h"

/* Defines */

#define MAX_CHAR 65535

int main () 
{   
    /*Variavel que contem o comando a ser executado*/
    char input[MAX_CHAR + 1];
    /*Le carateres da stdin ate encontrar o caso terminal ou 
    um comando a executar*/
    do {
        fgets(input, (MAX_CHAR + 1), stdin);
        switch(input) {
            case "help":
                help();
                break;
        }
    }
    while((strcmp(input, "quit") != 0));
    return 0;    
}