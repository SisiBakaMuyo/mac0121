#include <stdlib.h>
#include <stdio.h>
#include "testes.c"

void inserctionsort (int v[], int n){
    int bag, x, i;
    int comp = 0, mov = 0;
    for (bag = 1; bag < n; bag++){
        x = v[bag];
        comp++;
        for (i = bag-1; i >= 0 && v[i] > x; i--){
            mov++;
            comp++;
            v[i+1] = v[i];
        }
        v[i+1] = x;
        mov++;
    }

    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", n, comp, mov);
}

int main(){
    int *v;

    printf("Teste com vetor totalmente randômico\n\n");

    v = criaVetorRand(250);
    inserctionsort (v, 250);
    free(v);

    v = criaVetorRand(500);
    inserctionsort (v, 500);
    free(v);

    v = criaVetorRand(750);
    inserctionsort (v, 750);
    free(v);

    v = criaVetorRand(1000);
    inserctionsort (v, 1000);
    free(v);

    v = criaVetorRand(1250);
    inserctionsort (v, 1250);
    free(v);

    v = criaVetorRand(1500);
    inserctionsort (v, 1500);
    free(v);

    v = criaVetorRand(2000);
    inserctionsort (v, 2000);
    free(v);

    v = criaVetorRand(4000);
    inserctionsort (v, 4000);
    free(v);

    v = criaVetorRand(8000);
    inserctionsort (v, 8000);
    free(v);

    v = criaVetorRand(10000);
    inserctionsort (v, 10000);
    free(v);

    v = criaVetorRand(20000);
    inserctionsort (v, 20000);
    free(v);

    v = criaVetorRand(50000);
    inserctionsort (v, 50000);
    free(v);

    v = criaVetorRand(80000);
    inserctionsort (v, 80000);
    free(v);

    v = criaVetorRand(100000);
    inserctionsort (v, 100000);
    free(v);

    printf("\n\n");

    printf("Teste com vetor crescente\n\n");

    v = criaVetorCres(250);
    inserctionsort (v, 250);
    free(v);

    v = criaVetorCres(500);
    inserctionsort (v, 500);
    free(v);

    v = criaVetorCres(750);
    inserctionsort (v, 750);
    free(v);

    v = criaVetorCres(1000);
    inserctionsort (v, 1000);
    free(v);

    v = criaVetorCres(1250);
    inserctionsort (v, 1250);
    free(v);

    v = criaVetorCres(1500);
    inserctionsort (v, 1500);
    free(v);

    v = criaVetorCres(2000);
    inserctionsort (v, 2000);
    free(v);

    v = criaVetorCres(4000);
    inserctionsort (v, 4000);
    free(v);

    v = criaVetorCres(8000);
    inserctionsort (v, 8000);
    free(v);

    v = criaVetorCres(10000);
    inserctionsort (v, 10000);
    free(v);

    v = criaVetorCres(20000);
    inserctionsort (v, 20000);
    free(v);

    v = criaVetorCres(50000);
    inserctionsort (v, 50000);
    free(v);

    v = criaVetorCres(80000);
    inserctionsort (v, 80000);
    free(v);

    v = criaVetorCres(100000);
    inserctionsort (v, 100000);
    free(v);

    printf("\n\n");

    printf("Teste com vetor decrescente\n\n");

    v = criaVetorDecres(250);
    inserctionsort (v, 250);
    free(v);

    v = criaVetorDecres(500);
    inserctionsort (v, 500);
    free(v);

    v = criaVetorDecres(750);
    inserctionsort (v, 750);
    free(v);

    v = criaVetorDecres(1000);
    inserctionsort (v, 1000);
    free(v);

    v = criaVetorDecres(1250);
    inserctionsort (v, 1250);
    free(v);

    v = criaVetorDecres(1500);
    inserctionsort (v, 1500);
    free(v);

    v = criaVetorDecres(2000);
    inserctionsort (v, 2000);
    free(v);

    v = criaVetorDecres(4000);
    inserctionsort (v, 4000);
    free(v);

    v = criaVetorDecres(8000);
    inserctionsort (v, 8000);
    free(v);

    v = criaVetorDecres(10000);
    inserctionsort (v, 10000);
    free(v);

    v = criaVetorDecres(20000);
    inserctionsort (v, 20000);
    free(v);

    v = criaVetorDecres(50000);
    inserctionsort (v, 50000);
    free(v);

    v = criaVetorDecres(80000);
    inserctionsort (v, 80000);
    free(v);

    v = criaVetorDecres(100000);
    inserctionsort (v, 100000);
    free(v);

    printf("\n\n");

    printf("Teste com vetor metade crescente e metade randômico\n\n");

    v = criaVetorOrdRand(250);
    inserctionsort (v, 250);
    free(v);

    v = criaVetorOrdRand(500);
    inserctionsort (v, 500);
    free(v);

    v = criaVetorOrdRand(750);
    inserctionsort (v, 750);
    free(v);

    v = criaVetorOrdRand(1000);
    inserctionsort (v, 1000);
    free(v);

    v = criaVetorOrdRand(1250);
    inserctionsort (v, 1250);
    free(v);

    v = criaVetorOrdRand(1500);
    inserctionsort (v, 1500);
    free(v);

    v = criaVetorOrdRand(2000);
    inserctionsort (v, 2000);
    free(v);

    v = criaVetorOrdRand(4000);
    inserctionsort (v, 4000);
    free(v);

    v = criaVetorOrdRand(8000);
    inserctionsort (v, 8000);
    free(v);

    v = criaVetorOrdRand(10000);
    inserctionsort (v, 10000);
    free(v);

    v = criaVetorOrdRand(20000);
    inserctionsort (v, 20000);
    free(v);

    v = criaVetorOrdRand(50000);
    inserctionsort (v, 50000);
    free(v);

    v = criaVetorOrdRand(80000);
    inserctionsort (v, 80000);
    free(v);

    v = criaVetorOrdRand(100000);
    inserctionsort (v, 100000);
    free(v);

    printf("\n\n");

    return 0;
}