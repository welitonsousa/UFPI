#include "mylib.h"

struct Racional{
    int numerador, denominador;
};

Racional *criar_racional(int numerador, int denominador){
    Racional *racional;
    racional = (Racional *) calloc(1, sizeof(Racional));
    racional->numerador = numerador;
    racional->denominador = denominador;
    return racional;
}

Racional *somar_racional(Racional *racional1, Racional *racional2){
    Racional *soma;
    soma->numerador = racional1->numerador * racional2->denominador + racional2->numerador * racional1->denominador;
    soma->denominador = racional1->denominador * racional2->denominador;
    return soma;
}

Racional *multiplicar_racional(Racional *racional1, Racional *racional2)
{
    Racional *produto;
    produto->numerador = racional1->numerador * racional2->numerador;
    produto->denominador = racional1->denominador * racional2->denominador;
    return produto;
}

int testa(Racional *racional1, Racional *racional2){
    if (racional1->numerador * racional2->denominador == racional2->numerador * racional1->denominador) return 1;
    return 0;
}

