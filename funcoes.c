/*
  Ficheiro: funcoes.c
  Autor: Bruno Miguel da Silva Mendes ist195544/al95544
  Descricao: Ficheiro que contem as funcoes principais
*/

/*INCLUDES*/
#include "funcoes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/* slice path const */
const char slice[2] = "/";
char *token;
char *stringSet;
linkedListLink linkedListHead = NULL;
linkedListLink linkedListTail = NULL;
const char space = ' ';
char *string2;
char *string1;

/*
	help: () -> void
	comando help: Imprime os comandos disponíveis.
*/
void help()
{
    printf("help: Imprime os comandos disponíveis.\n");
    printf("quit: Termina o programa.\n");
    printf("set: Adiciona ou modifica o valor a armazenar.\n");
    printf("print: Imprime todos os caminhos e valores.\n");
    printf("find: Imprime o valor armazenado.\n");
    printf("list: Lista todos os componentes imediatos de um sub-caminho.\n");
    printf("search: Procura o caminho dado um valor.\n");
    printf("delete: Apaga um caminho e todos os subcaminhos.\n");
}

void set(char *input)
{
	char* inputWithoutSpace = input + 1;
    /* adicionar um ao pointer para tirar o primeiro white space */
    string2 = (strchr(inputWithoutSpace, space) + 1);

    /* copy inputWithOutSpace to string1 */     
    string1 = (char *) malloc(sizeof(char) * (strlen(inputWithoutSpace)));
    strcpy(string1, inputWithoutSpace);

    /* remove \n from strings */
    string1[strcspn(string1, "\n")] = '\0';
    string2[strcspn(string2, "\n")] = '\0';

    /* slice first string at ' ', seg faults if value is null, prolly need to fix this */
    string1[strcspn(string1, " ")] = '\0';

    /* creating string to store */
    stringSet = (char *) malloc(sizeof(char) * (strlen(string1) + strlen(string2) + 1));
	
	/* get the first token
	token = strtok(string1, slice);
   
	walk through other tokens
	while(token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, slice);
   	}
    */
    strcpy(stringSet, string1);
    strcat(stringSet, " ");
    strcat(stringSet, string2);

    linkedListHead = insertEnd(linkedListHead, stringSet);

	free(string1);
	free(stringSet);
}

void print() {
	printList(linkedListHead);
}