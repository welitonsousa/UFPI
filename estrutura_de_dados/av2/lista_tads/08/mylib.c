#include "mylib.h"

struct Cilindro{
    float raio, altura;
};

Cilindro * criar_cilidro(float raio, float altura){
    Cilindro * cilindro = (Cilindro *) malloc(sizeof(Cilindro *));
    cilindro->altura = altura;
    cilindro->raio = raio;
    return cilindro;
}

float volume(Cilindro * cilindro){
    float pi = 3.14; 
    return (float) pi * cilindro->raio * cilindro->altura;
}

float area(Cilindro * cilindro){
    float pi = 3.14; 
    return (float) 2 * (pi * pow(cilindro->raio, 2)) + (2 * (pi * cilindro->raio * cilindro->altura));
}