#include "mylib.h"

void main(){
    Matriz * matriz;
    cria(matriz, 3, 3);
    printf("%d\n", acessa(matriz, 2, 2));
    atribui(matriz, 2, 2, 3);
    printf("%d\n", acessa(matriz, 2, 2));
    
    printf("linhas = %d\n", linhas(matriz));
    printf("colunas  = %d\n", colunas(matriz));
    
    libera(matriz);
}