int verificaLetra(char *pal, char letra, int posicao);

void inserePalavraCol(pilha *p, char *pal, int pal_i, int tamPal, char **resultado, int **tab, int i, int j);

void inserePalavraLin(pilha *p, char *pal, int pal_i, int tamPal, char **resultado, int **tab, int i, int j);

int verificaTamanhoLin(int **tab, int lin, int col, int n);

int verificaTamanhoCol(int **tab, int lin, int col, int m);

int procuraPalavra(char **pal, int tamPal, int ini, int npal);

int *verificaVazioLin(int **tab, int lin, int col, int n, char **resultado);

void apagaColuna(int **tab, char **resultado, int i, int j, int m);

void apagaLinha(int **tab, char **resultado, int i, int j, int tamPal, int m);

int contaVetorPreenchido(int *vet, int n);

int *verificaVazioCol(int **tab, int lin, int col, int m, char **resultado);
