#include "mylib.h"

void main(){
    Cilindro * cilindro = criar_cilidro(3, 2);
    printf("%f\n", volume(cilindro));
    printf("%f\n", area(cilindro));
}