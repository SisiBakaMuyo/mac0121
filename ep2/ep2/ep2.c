#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "imprime.h"
#include "aloca.h"
#include "palavra.h"


back backtrack(pilha *p, int **tab, char **resultado, int m, int *jaFoi){
    back posicaoPal;

    posicaoPal = desempilha(p); 

    if (posicaoPal.orientacao == 'h'){
        apagaLinha(tab, resultado, posicaoPal.tab_i, posicaoPal.tab_j, posicaoPal.tamPal, m);
        jaFoi[posicaoPal.pal_i] = 0;
    }
    if (posicaoPal.orientacao == 'v'){
        apagaColuna(tab, resultado, posicaoPal.tab_i, posicaoPal.tab_j, m);
        jaFoi[posicaoPal.pal_i] = 0;
    }
    
    return posicaoPal;
}

void geraCruzadinha(int **tab, char **pal, int m, int n, int npal, int ini, int tamPal, int a, int b, int *jaFoi, char **resultado, pilha *p){
    back posicaoPal;
    int aciona = 0;
    int *letrasPreenchidas;
    int i, j, k;

    /* verifica na linha se tem um espaco pra inserir uma palavra e se houver, se
    ja esta preenchido com alguma letra*/
    for (i = a; i < m; i++){
        for (j = b; j < n; j++){

            /* garante a volta da recursao quando o vetor acaba */
            if (i == m-1 && j == n-1){
                return;
            }

            /* garante que volta nas colunas no backtrack da coluna*/
            if (ini == -1){
                posicaoPal = backtrack(p, tab, resultado, m, jaFoi);
                ini = procuraPalavra(pal, posicaoPal.tamPal, posicaoPal.pal_i + 1, npal);
                if (jaFoi[ini] == 1){
                    ini = procuraPalavra(pal, posicaoPal.tamPal, ini + 1, npal);
                }
                geraCruzadinha(tab, pal, m, n, npal, ini, posicaoPal.tamPal, posicaoPal.tab_i, posicaoPal.tab_j, jaFoi, resultado, p);
                return;
            }

            /* se for um espaco preto onde nao cabe letra*/
            if (tab[i][j] == -1){
                resultado[i][j] = '*';
                j++;
            }


             /* se ja esta preenchida, pode ja ter uma palavra na linha e so basta 
            preencher uma palavra na coluna. Ou so tem uma letra preenchida e é
            necessario inserir uma palavra na linha que contenha as letras ja pre
            preenchidas e depois inserir a coluna tambem.*/
            if (tab[i][j] == 1){
                letrasPreenchidas = verificaVazioLin(tab, i, j, n, resultado);
                tamPal = verificaTamanhoLin(tab, i, j, n);
                if (contaVetorPreenchido(letrasPreenchidas, n) == tamPal){
                    tamPal = verificaTamanhoCol(tab, i, j, m);
                    free(letrasPreenchidas);
                    letrasPreenchidas = verificaVazioCol(tab, i, j, m, resultado);
                    if (contaVetorPreenchido(letrasPreenchidas, m) == tamPal){
                        if ((j + 1) < n){
                            geraCruzadinha(tab, pal, m, n, npal, ini, tamPal, i, j + 1, jaFoi, resultado, p);
                            return;
                        }
                        else{
                            geraCruzadinha(tab, pal, m, n, npal, ini, tamPal, i + 1, 0, jaFoi, resultado, p);
                            return;
                        } 
                    }
                    ini = 0;
                    ini = procuraPalavra(pal, tamPal, ini, npal);
                    if (jaFoi[ini] == 1){
                        ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                    }
                    while (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 0){
                        ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                    }    
                    if (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 1){
                        inserePalavraCol(p, pal[ini], ini, tamPal, resultado, tab, i, j);
                        posicaoPal = topoDaPilha(p);
                        jaFoi[ini] = 1;
                    }
                    /*backtrack coluna*/
                    else{
                        posicaoPal = backtrack(p, tab, resultado, m, jaFoi);
                        ini = procuraPalavra(pal, posicaoPal.tamPal, posicaoPal.pal_i + 1, npal);
                        while (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 0){
                            ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                        }
                        if (jaFoi[ini] == 1){
                            ini = procuraPalavra(pal, posicaoPal.tamPal, ini + 1, npal);
                        }
                        if (ini == -1){
                            geraCruzadinha(tab, pal, m, n, npal, ini, posicaoPal.tamPal, posicaoPal.tab_i, posicaoPal.tab_j, jaFoi, resultado, p);
                            return;
                        }
                        else{
                            inserePalavraCol(p, pal[ini], ini, posicaoPal.tamPal, resultado, tab, posicaoPal.tab_i, posicaoPal.tab_j);
                        }    
                    }
                }
                else{
                    aciona = 1;
                }
            }



            /* se houver espaco vazio na linha sem estar preenchido, pode ter ou nao
            letras ja inseridas no meio do espaco da palavra, preenche a linha com a
            palavra que caiba*/
            if (tab[i][j] == 0 || aciona == 1){
                tamPal = verificaTamanhoLin(tab, i, j, n);
                ini = procuraPalavra(pal, tamPal, ini, npal);
                while (jaFoi[ini] == 1 && ini < npal){
                    ini = procuraPalavra(pal, tamPal, (ini+1), npal);
                }
                 /*backtrack*/
                if (ini == -1){
                    if (!pilhaVazia(p)){
                        posicaoPal = backtrack(p, tab, resultado, m, jaFoi);
                        ini = procuraPalavra(pal, tamPal, posicaoPal.pal_i, npal);
                        if (jaFoi[ini] == 1){
                            ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                        }
                        geraCruzadinha(tab, pal, m, n, npal, ini, tamPal, posicaoPal.tab_i,posicaoPal.tab_j, jaFoi, resultado, p);
                        return;
                    }
                    /* nao tem solucao na instancia*/
                    else{
                        resultado[0][0] = '#';
                        return;
                    }    
                }
                letrasPreenchidas = verificaVazioLin(tab, i, j, n, resultado);
                /* se nao houver letras preenchidas insere a primeira palavra com 
                o tamanho igual*/ 
                if (letrasPreenchidas[0] == 0){
                    inserePalavraLin(p, pal[ini], ini, tamPal, resultado, tab, i, j);
                    posicaoPal = topoDaPilha(p);
                    jaFoi[ini] = 1;     
                    tamPal = verificaTamanhoCol(tab, i, j, m);
                    ini = 0;
                    ini = procuraPalavra(pal, tamPal, ini, npal);
                    if (jaFoi[ini] == 1){
                        ini = procuraPalavra(pal, tamPal, (ini+1), npal);
                    }
                    while (verificaLetra(pal[ini], resultado[i][j], 0) == 0 && ini != -1){
                        ini = procuraPalavra(pal, tamPal, (ini+1), npal);
                    }    
                    if (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 1){
                        inserePalavraCol(p, pal[ini], ini, tamPal, resultado, tab, i, j);
                        posicaoPal = topoDaPilha(p);
                        jaFoi[ini] = 1;  
                    }
                    /*backtrack coluna*/
                    else{
                        posicaoPal = backtrack(p, tab, resultado, m, jaFoi);
                        ini = procuraPalavra(pal, posicaoPal.tamPal, posicaoPal.pal_i + 1, npal);
                        while (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 0){
                            ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                        }
                        if (jaFoi[ini] == 1){
                            ini = procuraPalavra(pal, posicaoPal.tamPal, ini + 1, npal);
                        }
                        if (ini == -1){
                            geraCruzadinha(tab, pal, m, n, npal, ini, posicaoPal.tamPal, posicaoPal.tab_i, posicaoPal.tab_j, jaFoi, resultado, p);
                            return;
                        }
                        else{
                            inserePalavraCol(p, pal[ini], ini, posicaoPal.tamPal, resultado, tab, posicaoPal.tab_i, posicaoPal.tab_j);
                        }  
                    }
                }
                /*se houver letras no meio da palavra procura uma palavra daquele
                tamanho que tenha essas letras na mesma posicao*/ 
                else{
                    for (k = 0; k < contaVetorPreenchido(letrasPreenchidas, n); k++){
                        while (letrasPreenchidas[k] != 1){
                            k++;
                        }
                        if (verificaLetra(pal[ini], resultado[i][j+k], k) == 0){
                            ini = procuraPalavra(pal, tamPal, (ini+1), npal);
                        }
                    }
                    if (ini != -1){
                        inserePalavraLin(p, pal[ini], ini, tamPal, resultado, tab, i, j);
                        posicaoPal = topoDaPilha(p);
                        jaFoi[ini] = 1;
                        tamPal = verificaTamanhoCol(tab, i, j, m);
                        free(letrasPreenchidas);
                        letrasPreenchidas = verificaVazioCol(tab, i, j, m, resultado);
                        if (contaVetorPreenchido(letrasPreenchidas, m) == tamPal){
                            if ((j + 1) < n){
                                geraCruzadinha(tab, pal, m, n, npal, ini, tamPal, i, j + 1, jaFoi, resultado, p);
                                return;
                            }
                            else{
                                geraCruzadinha(tab, pal, m, n, npal, ini, tamPal, i + 1, 0, jaFoi, resultado, p);
                                return;
                            }    
                        }
                        ini = 0;
                        ini = procuraPalavra(pal, tamPal, ini, npal);
                        if (jaFoi[ini] == 1){
                            ini = procuraPalavra(pal, tamPal, ini + 1, npal);    
                        }
                        while (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 0){
                            ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                        }    
                        if (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 1){
                            inserePalavraCol(p, pal[ini], ini, tamPal, resultado, tab, i, j);
                            jaFoi[ini] = 1;
                        }
                        /*backtrack coluna*/
                        else{
                            posicaoPal = backtrack(p, tab, resultado, m, jaFoi);
                            ini = procuraPalavra(pal, posicaoPal.tamPal, posicaoPal.pal_i + 1, npal);
                            while (ini != -1 && verificaLetra(pal[ini], resultado[i][j], 0) == 0){
                                ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                            }
                            if (jaFoi[ini] == 1){
                                ini = procuraPalavra(pal, posicaoPal.tamPal, ini + 1, npal);
                            }
                            if (ini == -1){
                                geraCruzadinha(tab, pal, m, n, npal, ini, posicaoPal.tamPal, posicaoPal.tab_i, posicaoPal.tab_j, jaFoi, resultado, p);
                                return;
                            }
                            else{
                                inserePalavraCol(p, pal[ini], ini, posicaoPal.tamPal, resultado, tab, posicaoPal.tab_i, posicaoPal.tab_j);
                            }  
                        }
                    }
                    /*backtrack: se nao houver uma palavra que tenha as letras na
                    mesma posicao, retorna a linha anterior e troca a palavra*/
                    else{
                        posicaoPal = backtrack(p, tab, resultado, m, jaFoi);
                        ini = procuraPalavra(pal, tamPal, posicaoPal.pal_i, npal);
                        if (jaFoi[ini] == 1){
                            ini = procuraPalavra(pal, tamPal, ini + 1, npal);
                        }
                        geraCruzadinha(tab, pal, m, n, npal, ini, tamPal, posicaoPal.tab_i,posicaoPal.tab_j, jaFoi, resultado, p);
                        return;
                    }
                }
            }
            aciona = 0;
            j = 0;
        }
    }
    return;
}


int main(){
    int instancia = 1;
    int **tabuleiro;
    int m, n;
    int i, j, npal;
    char **pal;
    int tam = 20;
    char **resultado;
    int *jaFoi;
    pilha *p;

    printf("Digite as instancias do programa:\n");
    
    while (1){
        scanf("%d", &m);
        scanf("%d", &n);

        tabuleiro = alocaTab(m, n);

        /* final das instancias - para de ler */
        if (m == 0 && n == 0){
            break;
        }

        /* le o tabuleiro e guarda na matriz */
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                scanf("%d", &tabuleiro[i][j]);
            }
        }

        scanf("%d", &npal);

        pal = alocaPal(npal, tam);

        /* le as palavras e guarda na matriz */
        for (i = 0; i < npal; i++){
            scanf("%s", pal[i]);  
        }


        /*vetor que vai marcar as palavras ja utilizadas na cruzadinha para nao
        repeti-las*/
        jaFoi = malloc (npal * sizeof(int));
        for (i = 0; i < npal; i++){
            jaFoi[i] = 0;
        }

        resultado = alocaPal(m , n);
        p = criaPilha(npal);

        geraCruzadinha(tabuleiro, pal, m, n, npal, 0, 0, 0, 0, jaFoi, resultado, p);
        printf("Instância %d:\n", instancia);
        imprimeCruzadinha(resultado, m, n);
        freePal(pal, npal);
        freeTab(tabuleiro, m);
        freePal(resultado, m);
        free(p);
        free(jaFoi);
        instancia++;

    }
    return 0;
}