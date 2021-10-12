#ifndef mylib
#define mylib

typedef struct Racional Racional;

#include <stdlib.h>
#include <stdio.h>

Racional *criar_racional(int numerador, int denominador);
Racional *somar_racional(Racional *racional1, Racional *racional2);
Racional *multiplicar_racional(Racional *racional1, Racional *racional2);
int testa(Racional *racional1, Racional *racional2); // return 1 where true and return 0 where false

#endif
