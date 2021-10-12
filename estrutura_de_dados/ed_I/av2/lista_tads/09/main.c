#include "mylib.h"

void main(){
    Esfera * esfera = criar_esfera(3);
    printf("%f\n", volume(esfera));
    printf("%f\n", area(esfera));
}