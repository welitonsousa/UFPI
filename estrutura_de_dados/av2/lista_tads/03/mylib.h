#ifndef mylib
#define mylib

#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz Matriz;

void cria(Matriz *m, int linha, int coluna);
void libera(Matriz *matriz);
void atribui(Matriz *matriz, int i, int j, int novoNumero);
int acessa(Matriz *matriz, int i, int j);
int linhas(Matriz *matriz);
int colunas(Matriz *matriz);

#endif