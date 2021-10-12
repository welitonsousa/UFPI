#include "mylib.h"

struct Matriz{
    int linha, coluna, **matriz;
};

void cria(Matriz *matriz, int linha, int coluna){
    matriz->matriz = (int **)calloc(linha, sizeof(int*));
    for (int i = 0; i < linha; i++)
        matriz->matriz[i] = (int*) calloc(coluna,sizeof(int));
    matriz->linha = linha;
    matriz->coluna =coluna;

    for(int i=0; i<linha;i++){
        for(int j=0; j<coluna;j++)
            matriz->matriz[i][j] = j;
    }
}

void libera(Matriz *matriz){
    int linhas = matriz->linha;
    for (int i = 0; i < linhas; i++)
        free(matriz->matriz[i]);
    free(matriz->matriz);
}

int acessa(Matriz *matriz, int i, int j){   
    if(i>=0 && i<matriz->linha && j>=0 && j<matriz->coluna) return matriz->matriz[i][j];
    else exit(0);
}

void atribui(Matriz *matriz, int i, int j, int novoNumero){
    if(i>=0 && i<matriz->linha && j>=0 && j<matriz->coluna) matriz->matriz[i][j] = novoNumero;
    else exit(0);
}

int linhas(Matriz *matriz){
    return "%d linhas\n", matriz->linha;
}

int colunas(Matriz *matriz){
    return "%d colunas\n", matriz->coluna;
}
