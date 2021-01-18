#include "mylib.h"

void main(){
    Ponto * ponto = criar_ponto(10, 0);
    Ponto * ponto_interno = criar_ponto(10, 0);
    Ponto * ponto_externo = criar_ponto(11, 12);

    Circulo *circulo = criar_circulo(ponto, 5);
    
    mostrar_circulo(circulo);
    printf("Area = %f\n", area_circulo(circulo));
    printf("%d\n", interior(circulo, ponto_interno));
    printf("%d\n", interior(circulo, ponto_externo));
    liberar(circulo);
}