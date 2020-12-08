// Escreva uma função que receba um ponteiro V com 10 posições alocadas. A função
// deve retornar o ponteiro V com o valor de cada posição multiplicado pela sua terça
// parte. Escreva uma função main para testar o código.

#include <stdio.h>
#include <stdlib.h>

float * divider3(float *array, int size){
  int i;
  for ( i = 0; i < size; i++)
    array[i] = (float) array[i] / 3;
  return array;
}

int main(){
  int size = 10, i;
  float *array = (float*) calloc(size, sizeof(float));
  
  for (i = 0; i < size; i++)
    array[i] = (float) i;
  
  array = divider3(array, size);

  for (i = 0; i < size; i++)
    printf("%.2f ", array[i]);
}
