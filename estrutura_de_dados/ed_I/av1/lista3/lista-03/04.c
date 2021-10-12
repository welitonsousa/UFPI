// Escreva uma função que receba um caractere C e o transforme em uma STRING,
// ou seja, devolve uma string de comprimento 1 tendo C como único elemento.

#include<stdio.h>
#include<stdlib.h>

char *toString(char character){
    char *array = (char *)calloc(1, sizeof(int));
    array[0] = character;
    return array;
}

void main(){
    char * string = toString('w');
    printf("%s", string);
}
