/*
 *
 * Nome: Ísis Ardisson Logullo
 * nUSP:7577410
 * 
 * EP1 - MAC 121
 * 
 */

#include <stdio.h>
#include <stdlib.h>

char cifraCesar(int d1, int d2, char c){
    char alfMin[26] = {"abcdefghijklmnopqrstuvwxyz"};
    char alfMai[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int i;
    char *cript = malloc (sizeof(char));

    /* faz a troca da letra na cifra de cesar correspondente ao numero
     * digitado em d1 e d2. Se esse numero estourar o vetor do alfabeto, 
     * volta pro inicio do vetor e continua delocando */
    for (i = 0; i < 26; i++){
        if (c == alfMai[i]){
            if (i + d1 < 26)
                *cript = alfMai[i + d1];
            else
                *cript = alfMai[(i + d1) - 26];  
        }    
        if (c == alfMin[i]){
            if (i + d2 < 26)
                *cript = alfMin[i + d2];  
            else 
                *cript = alfMin[(i + d2) - 26];  
        }    
    }

    return cript[0];
}

char *cifraEspecial(char c){
    char *cript = malloc (2 * sizeof(char));

    /* troca apenas os caracteres especiais, transformando em vetor,
     * pois sao duas letras (string) e nao mais um char */

    if (c == ','){
        cript[0] = 'v';
        cript[1] = 'r';
    }
    if (c == '.'){
        cript[0] = 'p';
        cript[1] = 't';
    }
    if (c == ':'){
        cript[0] = 'd';
        cript[1] = 'p';
    }
    if (c == '!'){
        cript[0] = 'e';
        cript[1] = 'x';
    }
    if (c == '?'){
        cript[0] = 'i';
        cript[1] = 'n';
    }
    if (c == '\n'){
        cript[0] = 'n';
        cript[1] = 'l';
    }

    return cript;
}

int main(){
    char cript;
    int tam, i, d1, d2, ok; 
    char *nome = malloc (80 * sizeof(char));
    char *texto = malloc (10000 * sizeof(char));
    char *c = malloc (2 * sizeof(char));

    printf ("Digite o nome do arquivo que será criptografado: ");
    scanf ("%s", nome);

    FILE * arq; /* variável que recebe um ponteiro para o arquivo que será lido */
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

    /* garante que o valor de entrada de d1 e d2 seja entre 0 e 26 */
    ok = 0;
    while (!ok){
        ok = 1;
        printf ("Digite o numero da cifra para maiusculas \n");
        scanf ("%d", &d1);
        if (d1 > 26 || d1 < 0){
            printf("Erro! O valor tem que estar entre 0 e 26\n");
            ok = 0;
        }
        printf ("Digite o numero da cifra para minusculas \n");
        scanf ("%d", &d2);
        if (d2 > 26 || d2 < 0){
            printf("Erro! O valor tem que estar entre 0 e 26\n");
            ok = 0;
        }
    }    

    /* ve o texto e criptografa caractere por caractere */
    i = 0;
    for (i = 0; i < tam; i++){
        if (texto[i] == ' ')
            continue;   
        else if ( texto[i] == ',' || texto[i] == '.' || texto[i] == ':' ||
            texto[i] == '!' || texto[i] == '?' || texto[i] == '\n'){

            c = cifraEspecial(texto[i]);
            printf("%c%c", c[0], c[1]);
        }
        else{     
            cript = cifraCesar(d1, d2, texto[i]);
            printf("%c", cript);
        }  
    }
    printf("\n");  
    free (nome);
    free (texto);
    free (c);
    return 0;
}