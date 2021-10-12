#ifndef mylib
#define mylib

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro Livro;

Livro *livro_cria(char titulo[], char autor[], char genero[], int ano);
char *genero(Livro *livro);
char *autor(Livro *livro);
char *titulo(Livro *livro);
int ano(Livro *livro);
int livro_verifica(Livro *livro);

#endif
