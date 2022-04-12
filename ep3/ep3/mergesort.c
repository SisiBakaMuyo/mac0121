#include <stdio.h>
#include <stdlib.h>
#include "testes.c"

void intercala(int ini,int meio,int fim,int v[], int *cont){
    int *w;
    int p = ini, s = meio, pw = 0;
    int i;

    w = malloc ((fim-ini)*sizeof(int));

    while (p < meio && s < fim){
        cont[0]++; /*comparação*/
        cont[1]++; /*movimentação*/
        if (v[p] < v[s]){
            w[pw++] = v[p++];
        }
        else{
            w[pw++] = v[s++];
        }
    }
    while (p < meio){
        cont[0]++; /*comparação*/
        cont[1]++; /*movimentação*/
        w[pw++] = v[p++];
    }
    while (s < fim){
        cont[0]++; /*comparação*/
        cont[1]++; /*movimentação*/
        w[pw++] = v[s++];
    }
    for (i = ini; i < fim; i++){
        cont[1]++; /*movimentação*/
        v[i] = w[i-ini];
    }
    free(w);
    
}

void mergesort (int i, int f, int v[], int *cont) {
    int meio;

    if (f - i > 1) {
        meio = (i + f)/2;
        mergesort(i, meio, v, cont);
        mergesort(meio, f, v, cont);
        intercala(i, meio, f, v, cont);
    }
}

int main(){
    int *v;
    int *cont = malloc (2 * sizeof(int));

    printf("Teste com vetor totalmente randômico\n\n");
    /* cont[0] é o numero de comparacoes e cont[1] é o numero de movimentacoes*/
    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(250);
    mergesort (0, 250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);
    
    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(500);
    mergesort (0, 500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(750);
    mergesort (0, 750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(1000);
    mergesort (0, 1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(1250);
    mergesort (0, 1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(1500);
    mergesort (0, 1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(2000);
    mergesort (0, 2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(4000);
    mergesort (0, 4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(8000);
    mergesort (0, 8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(10000);
    mergesort (0, 10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(20000);
    mergesort (0, 20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(50000);
    mergesort (0, 50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(80000);
    mergesort (0, 80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(100000);
    mergesort (0, 100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);

    printf("\n\n");

    printf("Teste com vetor crescente\n\n");

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(250);
    mergesort (0, 250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(500);
    mergesort (0, 500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(750);
    mergesort (0, 750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(1000);
    mergesort (0, 1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(1250);
    mergesort (0, 1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(1500);
    mergesort (0, 1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(2000);
    mergesort (0, 2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(4000);
    mergesort (0, 4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(8000);
    mergesort (0, 8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(10000);
    mergesort (0, 10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(20000);
    mergesort (0, 20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(50000);
    mergesort (0, 50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(80000);
    mergesort (0, 80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(100000);
    mergesort (0, 100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);

    printf("\n\n");

    printf("Teste com vetor decrescente\n\n");

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(250);
    mergesort (0, 250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(500);
    mergesort (0, 500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(750);
    mergesort (0, 750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(1000);
    mergesort (0, 1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(1250);
    mergesort (0, 1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(1500);
    mergesort (0, 1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(2000);
    mergesort (0, 2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(4000);
    mergesort (0, 4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(8000);
    mergesort (0, 8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(10000);
    mergesort (0, 10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(20000);
    mergesort (0, 20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(50000);
    mergesort (0, 50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(80000);
    mergesort (0, 80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(100000);
    mergesort (0, 100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);

    printf("\n\n");

    printf("Teste com vetor metade crescente e metade randômico\n\n");

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(250);
    mergesort (0, 250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(500);
    mergesort (0, 500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(750);
    mergesort (0, 750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(1000);
    mergesort (0, 1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(1250);
    mergesort (0, 1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(1500);
    mergesort (0, 1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(2000);
    mergesort (0, 2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(4000);
    mergesort (0, 4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(8000);
    mergesort (0, 8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(10000);
    mergesort (0, 10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(20000);
    mergesort (0, 20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(50000);
    mergesort (0, 50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(80000);
    mergesort (0, 80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(100000);
    mergesort (0, 100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);
    free(cont);

    printf("\n\n");
    
    return 0;
}
