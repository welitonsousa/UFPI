#ifndef mylib
#define mylib

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Esfera Esfera;

Esfera * criar_esfera(float raio);

float volume(Esfera * esfera);
float area(Esfera * esfera);

#endif