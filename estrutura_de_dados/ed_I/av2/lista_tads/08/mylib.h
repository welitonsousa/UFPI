#ifndef mylib
#define mylib

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Cilindro Cilindro;

Cilindro * criar_cilidro(float raio, float altura);

float volume(Cilindro * cilindro);
float area(Cilindro * cilindro);

#endif