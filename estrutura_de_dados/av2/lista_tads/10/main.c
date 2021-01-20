#include "mylib.h"

void main(){
    char a[] = "weliton";
    char b[] = "gato";
    
    printf("%d\n", comprimento(a));
    
    printf("%s\n", a);
    printf("%s\n", b);

    copia(a, b);
    printf("%s\n", a);

    concatena(a, b);
    printf("%s\n", a);

}