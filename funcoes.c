/*
    Ficheiro: funcoes.c
    Autor: Mateus Leite Pinho ist199282/al99282
    Descricao: Ficheiro que contem as funcoes principais
*/

/*INCLUDES*/
#include "funcoes.h"
#include "linkedList.h"
#include "avl.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* global need to fix */
link LLHead = NULL;

char* pathProcessing(char *input)
{
    char *string = input + 1;
    char *token;
    char *path;
    char *pathFixed;

    /* remove \n from string */
    string[strcspn(string, "\n")] = '\0';
	/* get the first token */
	token = strtok(string, SPACE);
    
    /*first token is path */
    path = (char *)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(path, token);

    /* allocates memory to place newPath */
    pathFixed = (char *)malloc(sizeof(char) * (strlen(path) + 1));

    /*get the first token */
    token = strtok(string, SLICE);

    /* walk through other tokens and generate pathFixed, removing all
    excess '/' characters*/
	while(token != NULL) {
		strcat(pathFixed, token);
        strcat(pathFixed, SLICE);
		token = strtok(NULL, SLICE);
   	}

    /* remove the last '/' from pathFixed */
    if (pathFixed[strlen(pathFixed) - 1] == '/') {
        pathFixed[strlen(pathFixed) - 1] = '\0';
    }

    free(path);

    return pathFixed;
}

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
    char *string = input + 1;
    char *path;
    char *value;
    char *valueChopped;
    int chopVal;

    /* remove \n from string */
    string[strcspn(string, "\n")] = '\0';

    /* copy string to value */
    value = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(value, string);
    
    chopVal = strcspn(value, " ");
    valueChopped = value + chopVal + 1;

    path = pathProcessing(input);

    LLHead = insertEnd(LLHead, path, valueChopped);
    
    /* free allocated memory */
    free(path);
    free(value);
}

void print() {
	printList(LLHead);
}

void find(char *input)
{   
    char *path;
    link t;

    path = pathProcessing(input);
    t = lookupPath(LLHead, path);

    if (t == NULL) {
        printf("not found\n");
    } else if (strcmp(t->value, "") == 0) {
        printf("no data\n");
    } else {
        printf("%s\n", t->value);
    }

    free(t);
    free(path);
}

void search(char *input)
{
    char *value = input + 1;
    link t;

    /* remove \n from string */
    value[strcspn(value, "\n")] = '\0';

    t = lookupValue(LLHead, value);

    if (t == NULL) {
        printf("not found\n");
    } else {
        printf("/%s\n", t->path);
    }

    free(t);
}