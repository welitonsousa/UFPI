#include "mylib.h"

struct Ponto{
    int x, y;
};typedef Ponto Ponto;

struct Circulo{
    int raio;
    Ponto centro;
};typedef Circulo Circulo;

Circulo * criar_circulo(Ponto * centro, int raio){
    Circulo * circulo = (Circulo *) malloc(sizeof(Circulo *));
    circulo->centro.x = centro->x;
    circulo->centro.y = centro->y;
    circulo->raio = raio;
    return circulo;
}

Ponto * criar_ponto(int x, int y){
    Ponto * ponto = (Ponto *) malloc(sizeof(Ponto));
    ponto->x = x;
    ponto->y = y;
    return ponto;
}

void mostrar_circulo(Circulo * circulo){
    printf("Centro: \n");
    printf("X = %d | Y = %d\n",circulo->centro.x, circulo->centro.y);
    printf("Raio = %d\n", circulo->raio);
}

float area_circulo(Circulo * circulo){
    float pi = 3.14;
    return pi * pow(circulo->raio, 2);
}

int interior(Circulo * circulo, Ponto * ponto){
    float distancia = sqrt(pow((circulo->centro.x - ponto->x), 2) + pow((circulo->centro.y - ponto->y), 2));    
    if (distancia > circulo->raio) return 0;
    return 1;
}

void liberar(Circulo * circulo){
    free(circulo);
}
