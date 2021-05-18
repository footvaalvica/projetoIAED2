/* INCLUDES */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"
#include "linkedList.h"
#include "avl.h"

/* Defines */

#define MAX_CHAR 65536

/* string defines */
#define FIND "find"
#define HELP "help"
#define SET "set"
#define QUIT "quit"
#define PRINT "print"
#define SEARCH "search"

/*FUNCAO MAIN*/

/*
  main: () -> int
  Primeira funcao a ser executada, trata de reconhecer e processar o input para cada função
*/
int main()
{   
    /* inits avl and linked list */
    /*Variavel que contem o comando a ser executado*/
    char input[MAX_CHAR];
    /*Le carateres da stdin ate encontrar o caso terminal ou 
    um comando a executar*/
    do {
        scanf("%s", input);
        if (strcmp(input, HELP) == 0) {
            help();
        } else if (strcmp(input, SET) == 0) {
            fgets(input, MAX_CHAR, stdin);
            set(input);
        } else if (strcmp(input, PRINT) == 0) {
            print();
        } else if (strcmp(input, FIND) == 0) {
            fgets(input, MAX_CHAR, stdin);
            find(input);
        } else if (strcmp(input, SEARCH) == 0) {
            fgets(input, MAX_CHAR, stdin);
            search(input);
        }
    }
    while(strcmp(input, QUIT) != 0);
    return 0;
}