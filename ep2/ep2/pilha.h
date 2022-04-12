/*evita duplicacoes de variaveis com arquivos .h */
/* nota: sempre usar o #ifndef e terminar o arquivo com #endif */
#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#include <stdlib.h>

/* struct usada para o backtrack, guardando a posicao da palavra na cruzadinha,
qual palavra (posicao no vetor de palavras), o tamanho dessa palavra e se ela esta 
na horizontal ou vertical*/
typedef struct {
    int tamPal;
    int pal_i;
    int tab_i;
    int tab_j;
    char orientacao;
}back;

typedef struct {
  back * v;
  int topo;
  int tam;
} pilha;

pilha * criaPilha (int tam);
void destroiPilha (pilha * p);
void empilha (pilha * p, back x);
back desempilha (pilha * p);
int pilhaVazia (pilha * p);
back topoDaPilha (pilha *p);
pilha * aumentaPilha (pilha * p); 


#endif
