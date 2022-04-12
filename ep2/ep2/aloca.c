#include <stdio.h>
#include <stdlib.h> 
#include "aloca.h"

int **alocaTab(int m, int n){
    int **tab;
    int i;

    tab = malloc (m * sizeof(int*));
    for (i = 0; i < m; i++){
        tab[i] = malloc (n * sizeof(int));
    }
    return tab;
}

char **alocaPal(int npal, int tam){
    int i; 
    char **pal;

    pal = malloc (npal * sizeof(char*));
    for (i = 0; i < npal; i++){
        pal[i] = malloc (tam * sizeof(char));
    }
    return pal;
}

void freePal(char **pal, int npal){
    int i;

    for (i = 0; i < npal; i++){
        free(pal[i]);
    }
    free(pal);
}

void freeTab(int **tab, int m){
    int i;

    for (i = 0; i < m; i++){
        free(tab[i]);
    }
    free(tab);
}
