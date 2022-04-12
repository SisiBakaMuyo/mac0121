#include <stdio.h>
#include <stdlib.h>
#include "testes.c"

void troca (int v[], int a, int b){
    int x;
    
    x = v[a];
    v[a] = v[b];
    v[b] = x;
}

void rebaixa (int v[], int n, int i, int *cont){
    int pai, filho;
    pai = i;
    filho = 2 * i + 1;

    while (filho < n){
        cont[0]++; /*comparacao*/
        if (filho+1 < n && v[filho+1] > v[filho]){
            filho++;
        }
        cont[0]++; /*comparacao*/
        if (v[pai] < v[filho]){
            cont[1]++; /*movimentacao*/
            troca (v, pai, filho);
        }
        else{
            break;
        }
        pai = filho; 
        filho = 2 * pai + 1;
    } 
}

void heapfica (int v[], int n, int *cont){
    int i;

    for (i = (n-2)/2; i >= 0; i--){
        rebaixa (v, n, i, cont);
    }
}

void heapsort (int n, int v[], int *cont){
    int i;

    heapfica (v, n, cont);
    for (i = n-1; i > 0; i--){
        cont[1]++; /*movimentacao*/
        troca (v, i, 0);
        rebaixa (v, i, 0, cont);
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
    heapsort (250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);
    
    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(500);
    heapsort (500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(750);
    heapsort (750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(1000);
    heapsort (1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(1250);
    heapsort (1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(1500);
    heapsort (1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(2000);
    heapsort (2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(4000);
    heapsort (4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(8000);
    heapsort (8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(10000);
    heapsort (10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(20000);
    heapsort (20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(50000);
    heapsort (50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(80000);
    heapsort (80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorRand(100000);
    heapsort (100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);

    printf("\n\n");

    printf("Teste com vetor crescente\n\n");

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(250);
    heapsort (250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(500);
    heapsort (500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(750);
    heapsort (750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(1000);
    heapsort (1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(1250);
    heapsort (1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(1500);
    heapsort (1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(2000);
    heapsort (2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(4000);
    heapsort (4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(8000);
    heapsort (8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(10000);
    heapsort (10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(20000);
    heapsort (20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(50000);
    heapsort (50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(80000);
    heapsort (80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorCres(100000);
    heapsort (100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);

    printf("\n\n");

    printf("Teste com vetor decrescente\n\n");

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(250);
    heapsort (250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(500);
    heapsort (500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(750);
    heapsort (750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(1000);
    heapsort (1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(1250);
    heapsort (1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(1500);
    heapsort (1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(2000);
    heapsort (2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(4000);
    heapsort (4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(8000);
    heapsort (8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(10000);
    heapsort (10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(20000);
    heapsort (20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(50000);
    heapsort (50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(80000);
    heapsort (80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorDecres(100000);
    heapsort (100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);

    printf("\n\n");

    printf("Teste com vetor metade crescente e metade randômico\n\n");

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(250);
    heapsort (250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(500);
    heapsort (500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(750);
    heapsort (750, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 750, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(1000);
    heapsort (1000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(1250);
    heapsort (1250, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1250, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(1500);
    heapsort (1500, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 1500, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(2000);
    heapsort (2000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 2000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(4000);
    heapsort (4000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 4000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(8000);
    heapsort (8000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 8000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(10000);
    heapsort (10000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 10000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(20000);
    heapsort (20000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 20000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(50000);
    heapsort (50000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 50000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(80000);
    heapsort (80000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 80000, cont[0], cont[1]);
    free(v);

    cont[0] = 0;
    cont[1] = 0;
    v = criaVetorOrdRand(100000);
    heapsort (100000, v, cont);
    printf("Para o vetor de tamanho %d, temos %d comparacoes e %d movimentacoes\n", 100000, cont[0], cont[1]);
    free(v);
    free(cont);

    printf("\n\n");
    
    return 0;
}