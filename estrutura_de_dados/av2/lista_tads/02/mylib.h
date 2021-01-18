#ifndef mylib
#define mylib

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Circulo Circulo;
typedef struct Ponto Ponto;

Circulo * criar_circulo(Ponto * centro, int raio);
Ponto * criar_ponto(int x, int y);

void mostrar_circulo(Circulo * circulo);
float area_circulo(Circulo * circulo);
void liberar(Circulo * circulo);
int interior(Circulo * circulo, Ponto * ponto); // return 0 where false and return 1 where true

#endif