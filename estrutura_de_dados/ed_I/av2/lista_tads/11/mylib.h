#ifndef mylib
#define mylib

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TConjunto TConjunto;

TConjunto * criar_conjunto();
void ler_conjunto(TConjunto * conjunto);
void imprimir(TConjunto * conjunto);
int conjunto_igual(TConjunto * conjunto1, TConjunto conjunto2);
void intersecao(TConjunto * conjunto1, TConjunto * conjunto2){
void uniao(TConjunto * conjunto1, TConjunto * conjunto2){

#endif