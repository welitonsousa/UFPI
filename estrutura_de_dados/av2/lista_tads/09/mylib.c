#include "mylib.h"

struct Esfera{
    float raio;
};

Esfera * criar_esfera(float raio){
    Esfera * esfera = (Esfera *) malloc(sizeof(Esfera *));
    esfera->raio = raio;
    return esfera;
}

float volume(Esfera * esfera){
    float pi = 3.14; 
    return (float) (4/3) * pi * pow(esfera->raio, 3);
}

float area(Esfera * esfera){
    float pi = 3.14; 
    return (float) 4 * pi * pow(esfera->raio, 2);
}