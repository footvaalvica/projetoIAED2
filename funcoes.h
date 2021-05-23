/*
  Ficheiro: funcoes.h
  Autor: Mateus Leite Pinho ist195544/al95544
  Descricao: Ficheiro que define as funcoes principais
*/

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#define SLICE "/"
#define SPACE " "

#define NOT_FOUND "not found\n"
#define NO_DATA "no data\n"

#define HELP_STRING "help: Imprime os comandos disponíveis.\n"
#define QUIT_STRING "quit: Termina o programa.\n"
#define SET_STRING "set: Adiciona ou modifica o valor a armazenar.\n"
#define PRINT_STRING "print: Imprime todos os caminhos e valores.\n"
#define FIND_STRING "find: Imprime o valor armazenado.\n"
#define LIST_STRING "list: Lista todos os componentes imediatos de um sub-caminho.\n"
#define SEARCH_STRING "search: Procura o caminho dado um valor.\n"
#define DELETE_STRING "delete: Apaga um caminho e todos os subcaminhos.\n"

/*PROTOTIPOS DE FUNCOES*/
void help();
void set(char *input);
void print();
void find(char *input);
void search(char *input);
void list(char *input);
void delete(char *input);

#endif