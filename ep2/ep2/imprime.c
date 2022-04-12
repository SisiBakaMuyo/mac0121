#include <stdlib.h>
#include <stdio.h>
#include "imprime.h" 

void imprimeCruzadinha(char **resultado, int m, int n){
    int i, j;

    if (resultado[0][0] == '#'){
        printf("Nao tem solucao\n");
    }
    else{
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                printf("%c  ", resultado[i][j]);
            }
            printf("\n");
        }
    }
}

void imprimeListaPal(char **pal, int npal){
    int i;

    for (i = 0; i < npal; i++){
        printf("%s\n", pal[i]);
    }
}


void desenhaInstancia(int **tab, int m, int n){
    int i, j;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf ("%d  ", tab[i][j]);
        }
        printf("\n");
    }
}
