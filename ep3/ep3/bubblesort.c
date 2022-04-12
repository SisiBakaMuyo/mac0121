#include <stdio.h>
#include <stdlib.h>
#include "testes.c"

void troca (int v[], int a, int b){
    int x;
    
    x = v[a];
    v[a] = v[b];
    v[b] = x;
}

void bubblesort (int v[], int n){
    int inv = 1, i;
    int comp = 0;
    int mov = 0;

    while (inv){
        inv = 0;
        for (i = 0; i < n-1; i++){
            comp++;
            if (v[i] > v[i+1]){
                mov++;
                troca (v, i, i+1);
                inv = 1;
            }
        }
    }

    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", n, comp, mov);
}

int main(){
    int *v;

    printf("Teste com vetor totalmente randômico\n\n");

    v = criaVetorRand(250);
    bubblesort (v, 250);
    free(v);

    v = criaVetorRand(500);
    bubblesort (v, 500);
    free(v);

    v = criaVetorRand(750);
    bubblesort (v, 750);
    free(v);

    v = criaVetorRand(1000);
    bubblesort (v, 1000);
    free(v);

    v = criaVetorRand(1250);
    bubblesort (v, 1250);
    free(v);

    v = criaVetorRand(1500);
    bubblesort (v, 1500);
    free(v);

    v = criaVetorRand(2000);
    bubblesort (v, 2000);
    free(v);

    v = criaVetorRand(4000);
    bubblesort (v, 4000);
    free(v);

    v = criaVetorRand(8000);
    bubblesort (v, 8000);
    free(v);

    v = criaVetorRand(10000);
    bubblesort (v, 10000);
    free(v);

    v = criaVetorRand(20000);
    bubblesort (v, 20000);
    free(v);

    v = criaVetorRand(50000);
    bubblesort (v, 50000);
    free(v);

    v = criaVetorRand(80000);
    bubblesort (v, 80000);
    free(v);

    v = criaVetorRand(100000);
    bubblesort (v, 100000);
    free(v);

    printf("\n\n");

    printf("Teste com vetor crescente\n\n");

    v = criaVetorCres(250);
    bubblesort (v, 250);
    free(v);

    v = criaVetorCres(500);
    bubblesort (v, 500);
    free(v);

    v = criaVetorCres(750);
    bubblesort (v, 750);
    free(v);

    v = criaVetorCres(1000);
    bubblesort (v, 1000);
    free(v);

    v = criaVetorCres(1250);
    bubblesort (v, 1250);
    free(v);

    v = criaVetorCres(1500);
    bubblesort (v, 1500);
    free(v);

    v = criaVetorCres(2000);
    bubblesort (v, 2000);
    free(v);

    v = criaVetorCres(4000);
    bubblesort (v, 4000);
    free(v);

    v = criaVetorCres(8000);
    bubblesort (v, 8000);
    free(v);

    v = criaVetorCres(10000);
    bubblesort (v, 10000);
    free(v);

    v = criaVetorCres(20000);
    bubblesort (v, 20000);
    free(v);

    v = criaVetorCres(50000);
    bubblesort (v, 50000);
    free(v);

    v = criaVetorCres(80000);
    bubblesort (v, 80000);
    free(v);

    v = criaVetorCres(100000);
    bubblesort (v, 100000);
    free(v);

    printf("\n\n");

    printf("Teste com vetor decrescente\n\n");

    v = criaVetorDecres(250);
    bubblesort (v, 250);
    free(v);

    v = criaVetorDecres(500);
    bubblesort (v, 500);
    free(v);

    v = criaVetorDecres(750);
    bubblesort (v, 750);
    free(v);

    v = criaVetorDecres(1000);
    bubblesort (v, 1000);
    free(v);

    v = criaVetorDecres(1250);
    bubblesort (v, 1250);
    free(v);

    v = criaVetorDecres(1500);
    bubblesort (v, 1500);
    free(v);

    v = criaVetorDecres(2000);
    bubblesort (v, 2000);
    free(v);

    v = criaVetorDecres(4000);
    bubblesort (v, 4000);
    free(v);

    v = criaVetorDecres(8000);
    bubblesort (v, 8000);
    free(v);

    v = criaVetorDecres(10000);
    bubblesort (v, 10000);
    free(v);

    v = criaVetorDecres(20000);
    bubblesort (v, 20000);
    free(v);

    v = criaVetorDecres(50000);
    bubblesort (v, 50000);
    free(v);

    v = criaVetorDecres(80000);
    bubblesort (v, 80000);
    free(v);

    v = criaVetorDecres(100000);
    bubblesort (v, 100000);
    free(v);

    printf("\n\n");

    printf("Teste com vetor metade crescente e metade randômico\n\n");

    v = criaVetorOrdRand(250);
    bubblesort (v, 250);
    free(v);

    v = criaVetorOrdRand(500);
    bubblesort (v, 500);
    free(v);

    v = criaVetorOrdRand(750);
    bubblesort (v, 750);
    free(v);

    v = criaVetorOrdRand(1000);
    bubblesort (v, 1000);
    free(v);

    v = criaVetorOrdRand(1250);
    bubblesort (v, 1250);
    free(v);

    v = criaVetorOrdRand(1500);
    bubblesort (v, 1500);
    free(v);

    v = criaVetorOrdRand(2000);
    bubblesort (v, 2000);
    free(v);

    v = criaVetorOrdRand(4000);
    bubblesort (v, 4000);
    free(v);

    v = criaVetorOrdRand(8000);
    bubblesort (v, 8000);
    free(v);

    v = criaVetorOrdRand(10000);
    bubblesort (v, 10000);
    free(v);

    v = criaVetorOrdRand(20000);
    bubblesort (v, 20000);
    free(v);

    v = criaVetorOrdRand(50000);
    bubblesort (v, 50000);
    free(v);

    v = criaVetorOrdRand(80000);
    bubblesort (v, 80000);
    free(v);

    v = criaVetorOrdRand(100000);
    bubblesort (v, 100000);
    free(v);

    printf("\n\n");

    return 0;
}