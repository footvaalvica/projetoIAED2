/*
    Ficheiro: funcoes.c
    Autor: Mateus Leite Pinho ist199282/al99282
    Descricao: Ficheiro que contem as funcoes principais
*/

/*INCLUDES*/
#include "funcoes.h"
#include "linkedList.h"
#include "ST.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* global need to fix */
link LLHead = NULL;
avlLink root = NULL;

void pathProcessingSet(char *input, char *valueChopped)
{
    char *string = input + 1;
    char *token;
    char *pathFixed;
    link t;

    /* remove \n from string */
    string[strcspn(string, "\n")] = '\0';
	/* get the first token */
	token = strtok(string, SPACE);

    /* allocates memory to place newPath */
    pathFixed = (char *)malloc(sizeof(char) * (strlen(token) + 1));
    /* initializes path fixed */
    strcpy(pathFixed, "");

    /*get the first token */
    token = strtok(string, SLICE);

    /* walk through other tokens and generate pathFixed, removing all
    excess '/' characters*/
	while(token != NULL) {
		strcat(pathFixed, token);

        t = lookupPath(LLHead, pathFixed);

        if (t == NULL) {
            /* alterei o insertEnd para insertBegin, pois para trocar
            a ordem basta inserir no inicio em vez de no fim */
            LLHead = insertBegin(LLHead, pathFixed, "");
            root = STinsert(root, pathFixed);
        }

        strcat(pathFixed, SLICE);
		token = strtok(NULL, SLICE);
   	}

    /* remove the last '/' from pathFixed */
    if (pathFixed[strlen(pathFixed) - 1] == '/') {
        pathFixed[strlen(pathFixed) - 1] = '\0';
    }

    /* change the value only */
    t = lookupPath(LLHead, pathFixed);
    free(t->value);
    t->value = (char *)malloc(sizeof(char) * (strlen(valueChopped) + 1));
    strcpy(t->value, valueChopped);

    /* free allocated memory */
    free(pathFixed);
}

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

    return pathFixed;
}

/*
	help: () -> void
	comando help: Imprime os comandos disponíveis.
*/
void help()
{
    printf(HELP_STRING);
    printf(QUIT_STRING);
    printf(SET_STRING);
    printf(PRINT_STRING);
    printf(FIND_STRING);
    printf(LIST_STRING);
    printf(SEARCH_STRING);
    printf(DELETE_STRING);
}

void set(char *input)
{
    char *string = input + 1;
    char *value;
    char *valueChopped;
    int chopVal;

    /* remove \n from string */
    string[strcspn(string, "\n")] = '\0';

    /* copy string to value */
    value = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(value, string);
    
    chopVal = strcspn(value, SPACE);
    valueChopped = value + chopVal + 1;

    pathProcessingSet(input, valueChopped);

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
        printf(NOT_FOUND);
    } else if (strcmp(t->value, "") == 0) {
        printf(NO_DATA);
    } else {
        printf("%s\n", t->value);
    }

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
        printf(NOT_FOUND);
    } else {
        printf("/%s\n", t->path);
    }
}

void list(char *input)
{
    char *path;
    int pathLen;

    if (strcmp(input, "\n") == 0) {
        STsort(root, -1, "");
    } else {
        path = pathProcessing(input);
        pathLen = strlen(path);
        STsort(root, pathLen, path);
        free(path);
    }
}

void delete(char *input)
{
    char *path;
    link t;
    int pathLen;

    if (strcmp(input, "\n") == 0 || (strcmp(input, "/\n") == 0)) {
        deleteList(&LLHead);
        root = STfree(root);
    } else {
        path = pathProcessing(input);
        t = lookupPath(LLHead, path);
        if (t == NULL) {
            puts(NOT_FOUND);
            free(path);
            return;
        } else {
        pathLen = strlen(path);
        LLHead = STsortDelete(&root, LLHead, pathLen, input);
        STdelete(&root, path);
        LLHead = deleteFromLinkedList(LLHead, path);
        free(path);
        }
    }
}