#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*lista ligada da linha e numero de ocorrencias que aparecem nessa linha*/
typedef struct ocorr{
    int linha;
    int numOcorr;
    struct ocorr *prox;
}ocorrencias;

/*celula da hash table, que em caso de colisao vira uma lista ligada*/
typedef struct cel{
    char palavra[100];
    ocorrencias *ocor;
    struct cel *prox;
}celula;


/* multiplca cada caracter por um primo e divide pelo tamanho da tabela hash para
obter a dispersao*/
int hash(char *palavra, int tam){
    int i, h = 0;
    int primo = 149;

    for (i = 0; palavra[i] != '\0'; i++){
        h = (h * primo + palavra[i]) % tam;
    }
    if (h < 0){
        return h * (-1);
    }    
    return h;
}

/*insere a palavra na primeira vez que ela aparece */
void insereHash(celula **tab, char *palavra, int linha, int tam) {
    int h;
    celula *p, *q;
    ocorrencias *o;
    h = hash(palavra, tam);
    q = tab[h];

    /* o numero de ocorrencias da palavra é uma lista ligada, onde cada celula 
    é uma linha que tem o numero de ocorrencia naquela linha*/
    /* trata o caso de colisao, se ja existir uma palavra no h, insere uma lista
    ligada ali*/
    if (q == NULL){
        p = malloc (sizeof(*p));
        o = malloc (sizeof(ocorrencias));
        strcpy(p->palavra, palavra);
        p->ocor = o;
        p->ocor->linha = linha;
        p->ocor->numOcorr = 1;
        p->ocor->prox = NULL;
        tab[h] = p;
        p->prox = NULL;
    }
    else{
        while (q->prox != NULL){
            q = q->prox;
        }
        p = malloc (sizeof(*p));
        o = malloc (sizeof(ocorrencias));
        strcpy(p->palavra, palavra);
        o->linha = linha;
        o->numOcorr = 1;
        o->prox = NULL;
        p->ocor = o;
        q->prox = p;
        p->prox = NULL;
    }    
}

/*verifica se a palavra ja existe no hash*/
int buscaHash(celula **tab, char *palavra, int h) {
    celula *p, *q;
    p = tab[h];
    q = p;

    if (p == NULL){
        return 0;
    }

    while (p != NULL){
        if (strcmp(palavra, p->palavra) != 0){
            q = p;
            p = p->prox;
        }
        break;    
    }

    if (strcmp(palavra, q->palavra) == 0){
        return 1;
    }
    return 0;
}

void freeHash(celula **tab, int tam) {
    celula *p, *q;
    int i;
    
    for(i = 0; i < tam -1; i++){
        p = tab[i];
        while (p != NULL && p->prox != NULL){
            q = p->prox;
            free(p);
            p = q;
        }
    }
    free(tab);
}

void imprimeHash(celula **tab, int tam){
    celula *p;
    int i;

    for (i = 0; i < tam-1; i++){
        p = tab[i];
        while (p != NULL){
            if (p->palavra != NULL){
                if (p->ocor != NULL){
                    printf("%s: ", p->palavra);
                }    
                while (p->ocor != NULL){
                    printf("%d(%d) ", p->ocor->linha, p->ocor->numOcorr);
                    p->ocor = p->ocor->prox;
                }
                printf("\n");
            }
            p = p->prox;
        }

    }
}

/*funcao do bubblesort*/
void troca (celula **tab, int a, int b){
    celula *p;
    
    p = tab[a];
    tab[a] = tab[b];
    tab[b] = p;
}

void bubblesort (celula **tab, int n){
    int inv = 1, i;

    while (inv){
        inv = 0;
        for (i = 0; i < n-1; i++){
            if (strcmp(tab[i]->palavra, tab[i+1]->palavra) > 0){
                troca (tab, i, i+1);
                inv = 1;
            }
        }
    }
}

/* copia o hash pra um vetor e ordena em ordem alfabética com o bubblesort*/
void imprimeAlfabetico (celula **tab, int tam){
    celula **vet;
    celula *p;
    int i, j;

    vet = malloc (tam * 2 * sizeof(celula));

    j = 0;
    for (i = 0; i < tam-1; i++){
        p = tab[i];
        while (p != NULL && p->ocor != NULL){
            if (p->palavra != NULL){
                vet[j] = p;
                j++;
            }
            p = p->prox;
        }
    }

    bubblesort (vet, j);
    imprimeHash (vet, tam);
}

/*insere uma nova linha e nova ocorrencia numa palavra ja iniciada*/
void alteraHash (celula **tab, char *palavra, int h, int linha){
    celula *p;
    ocorrencias *o, *atual, *ant;
    p = tab[h];

    while (p->prox != NULL && strcmp(palavra, p->palavra) != 0){
        p = p->prox;
    }

    /* se a linha ja apareceu na lista de ocorrencias so acrescenta mais um item,
    se nao, insere uma nova linha na lista de ocorrencia da palavra*/
    if (strcmp(palavra, p->palavra) == 0){
        for (atual = p->ocor, ant = NULL; atual != NULL; ant = atual, atual = atual->prox);
        
        if (ant->linha == linha){
            ant->numOcorr = ant->numOcorr + 1;
        }
        else{
            o = malloc (sizeof(ocorrencias));
            o->linha = linha;
            o->numOcorr = 1;
            o->prox = NULL;
            ant->prox = o;
        }
    }
}

int main(){
    char palavra[100];
    celula **tab;
    int tam, i, linha, j, h; 
    char *nome = malloc (80 * sizeof(char));
    char *texto = malloc (1000000 * sizeof(char));
    FILE * arq; /* variável que recebe um ponteiro para o arquivo que será lido */

    printf ("Digite o nome do arquivo a ser analisado: ");
    scanf ("%s", nome);

    arq = fopen (nome, "r"); /* abre o arquivo com o nome lido para leitura "r" */
    if (arq == NULL) {
        printf ("Nao encontrei o arquivo %s\n", nome);
    }

    tam = 0;
    /* grava no vetor texto todos os caracteres do arquivo */
    while (!feof (arq)) {
        fscanf (arq, "%c", &texto[tam]);
        tam++;
    }


    /* ve caracter por caracter. analisa a palavra e a linha que ela esta e 
    adiciona uma ocorrencia a tabela */
    linha = 1;
    j = 0;
    h = 0;
    tab = malloc (tam * sizeof(celula));

    for (i = 0; i < tam - 1; i++){
        palavra[0] = '\0';
        j = 0;  
        if (texto[i] == '\n'){
           linha++;
        }
        if (texto[i] != ' ' && texto[i] != ',' && texto[i] != '.' && texto[i] != ','
            && texto[i] != '?' && texto[i] != '\n' && texto[i] != ';' && 
            texto[i] != ':'){
            
            while (texto[i] != ' ' && texto[i] != ',' && texto[i] != '.' && texto[i] != ','
            && texto[i] != '?' && texto[i] != '\n' && texto[i] != ';' && 
            texto[i] != ':'){
                palavra[j] = texto[i];
                j++;
                i++;
            }
            i--;
            palavra[j] = '\0';

            h = hash(palavra, tam);

            if (buscaHash(tab, palavra, h) == 0){
                insereHash(tab, palavra, linha, tam);
            }
            else{
                alteraHash(tab, palavra, h, linha);
            }

        }
    }
    imprimeAlfabetico(tab, tam);
    freeHash(tab, tam);

    return 0;
}