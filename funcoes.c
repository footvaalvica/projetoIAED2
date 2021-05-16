/*
  Ficheiro: funcoes.c
  Autor: Bruno Miguel da Silva Mendes ist195544/al95544
  Descricao: Ficheiro que contem as funcoes principais
*/

/*INCLUDES*/
#include "funcoes.h"

/*
  help: () -> void
  comando help: Imprime os comandos disponíveis.
*/
void help()
{
    printf("help	Imprime os comandos disponíveis.\n");
    printf("quit	Termina o programa.\n");
    printf("set	Adiciona ou modifica o valor a armazenar.\n");
    printf("print	Imprime todos os caminhos e valores.\n");
    printf("find	Imprime o valor armazenado.\n");
    printf("list	Lista todos os componentes imediatos de um sub-caminho.\n");
    printf("search	Procura o caminho dado um valor.\n");
    printf("delete	Apaga um caminho e todos os subcaminhos.\n");
}
