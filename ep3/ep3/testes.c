#include <stdio.h>
#include <stdlib.h>

void intercalaTeste(int p,int q,int r,int v[]){
    int i, j, k, *w;
    w = malloc ((r-p)*sizeof(int));
    
    for (i = 0, k = p; k < q; i++, k++){
        w[i] = v[k];
    }    
    for (j = r-p-1; k < r; j--, k++){
        w[j] = v[k];
    }    
    
    i = 0; j = r-p-1;
    for (k = p; k < r; k++){
        if (w[i] <= w[j]){
            v[k] = w[i++];
        }    
        else{
            v[k] = w[j--];
        }    
    }    
    free (w);
}

int *inverte (int v[], int tam){
    int i, j;
    int *vet = malloc (tam * sizeof(int));
    j = tam-1;

    for(i = 0; i < tam; i++){
        vet[j] = v[i];
        j--;
    }
    free(v);
    return vet;
}

void mergesortTeste (int p, int r, int v[]) {
    int q;

    if (p < r-1) {
        q = (p + r)/2;
        mergesortTeste(p, q, v);
        mergesortTeste(q, r, v);
        intercalaTeste(p, q, r, v);
    }
}

int *criaVetorRand (int tam){
    int *v = malloc (tam * sizeof(int));
    int i; 

    for (i = 0; i < tam; i++){
        v[i] = rand() % 100;
    } 
    return v;
}

int *criaVetorCres (int tam){
    int *v = malloc (tam * sizeof(int));

    v = criaVetorRand (tam);
    mergesortTeste (0, tam, v);

    return v;
}

int *criaVetorDecres (int tam){
    int *v = malloc (tam * sizeof(int));

    v = criaVetorRand (tam);
    mergesortTeste (0, tam, v);
    v = inverte (v, tam);

    return v;
}

int *criaVetorOrdRand (int tam){
    /* metade ordenado e metade randomico*/
    int *v = malloc (tam * sizeof(int));

    v = criaVetorRand (tam);
    mergesortTeste(0, tam/2, v);

    return v;
}