#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "palavra.h"

/* verifica se na palavra tem uma letra especiica na posicao dada*/
int verificaLetra(char *pal, char letra, int posicao){
    if (pal[posicao] == letra)
        return 1;
    return 0;    
}

/* insere a palavra na coluna da posicao indicada e empilha essa posicao, a palavra, 
o tamanho da palavra e que ela esta na vertical*/
void inserePalavraCol(pilha *p, char *pal, int pal_i, int tamPal, char **resultado, int **tab, int i, int j){
    back posicaoPal;
    int z;

    posicaoPal.tamPal = tamPal;
    posicaoPal.pal_i = pal_i;
    posicaoPal.tab_i = i;
    posicaoPal.tab_j = j;
    posicaoPal.orientacao = 'v';

    empilha(p, posicaoPal);

    for (z = 0; z < tamPal; z++){
        resultado[i][j] = pal[z];
        tab[i][j] = 1;
        i++;
    }
}

/* insere a palavra na linha da posicao indicada e empilha essa posicao, a palavra, 
o tamanho da palavra e que ela esta na horizontal*/
void inserePalavraLin(pilha *p, char *pal, int pal_i, int tamPal, char **resultado, int **tab, int i, int j){
    back posicaoPal;
    int z, k;

    posicaoPal.tamPal = tamPal;
    posicaoPal.pal_i = pal_i;
    posicaoPal.tab_i = i;
    posicaoPal.tab_j = j;
    posicaoPal.orientacao = 'h';

    empilha(p, posicaoPal);

    k = 0;
    for (z = j; z < tamPal + j; z++){
        resultado[i][z] = pal[k];
        tab[i][z] = 1;
        k++;
    }
}

/* verifica o tamanho do espaco, assim descobrindo o tamanho da palavra que cabe 
ali*/
int verificaTamanhoLin(int **tab, int lin, int col, int n){
    int j = col;
    int tamPal = 0;

    while (j < n && tab[lin][j] != -1) {
        tamPal++;    
        j++;
    }
    return tamPal;
}

int verificaTamanhoCol(int **tab, int lin, int col, int m){
    int i = lin;
    int tamPal = 0;

    while (tab[i][col] != -1) {
        tamPal++;
        i++;
        if (i >= m){
            break;
        }
    }
    return tamPal;
}


/* procura na lista de palavras a primeira palavra que tem o tamanho indicado, a 
partir do ponto inicial inserido */
int procuraPalavra(char **pal, int tamPal, int ini, int npal){
    int i;

    for (i = ini; i < npal; i++){
        if (strlen(pal[i]) == tamPal)
            return i;
    }
    return -1;
}

/* verifica se existe alguma letra preenchida no espaco da linha onde colocaremos
 uma palavra, guarda as posicoes das letras ja preenchidas na palavra*/
int *verificaVazioLin(int **tab, int lin, int col, int n, char **resultado){
    int j = col;
    int *posicoes;
    int i = 0;
    
    posicoes = malloc ((n-1) * sizeof(int));
    posicoes[0] = 0;
    
    while (j < n && tab[lin][j] != -1) {
        if (tab[lin][j] == 1){
            posicoes[j] = 1;
        }
        j++;
        i++;
    }
    return posicoes;
}

/* verifica se existe alguma letra preenchida no espaco da coluna onde colocaremos
 uma palavra, guarda as posicoes das letras ja preenchidas na palavra*/
int *verificaVazioCol(int **tab, int lin, int col, int m, char **resultado){
    int j = 0;
    int *posicoes;
    int i = lin;
    
    posicoes = malloc ((m-1) * sizeof(int));
    posicoes[0] = 0;
    
    while (i < m && tab[i][col] != -1) {
        if (tab[i][col] == 1){
            posicoes[i] = 1;
        }
        j++;
        i++;
    }
    return posicoes;
}

/* apaga a palavra da coluna na posicao dada*/
void apagaColuna(int **tab, char **resultado, int i, int j, int m){
    int k = i+1;

    while (tab[k][j] != -1 && k < m){
        tab[k][j] = 0;
        resultado[k][j] = ' ';
        k++;
    }
}

/* apaga a palavra da linha na posicao dada*/
void apagaLinha(int **tab, char **resultado, int i, int j, int tamPal, int m){
    int k;

    for (k = j; k < tamPal + j; k++){
        tab[i][k] = 0;
        resultado[i][k] = ' ';
    }
}

int contaVetorPreenchido(int *vet, int n){
    int i, cont;
    cont = 0;

    for (i = 0; i < n ; i++){
        if (vet[i] == 1){
            cont++;
        }
    }

    return cont;
}


