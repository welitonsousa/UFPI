#include "mylib.h"

void main(){
    Racional * racional = criar_racional(2, 2);
    Racional * racional2 = criar_racional(1, 1);
    Racional * racioanl3 = somar_racional(racional, racional2);
    Racional * racioanl4 = multiplicar_racional(racional, racional2);
    printf("%d", testa(racional, racional2));
}
