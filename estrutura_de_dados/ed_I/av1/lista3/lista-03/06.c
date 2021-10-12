// Crie um programa que aloque dinamicamente um vetor de 1500 posições,
// inicialize-as com os valores de seus índices e logo após, imprima o valor das 10
// primeiras e das 10 ultimas posições do vetor.

#include <stdio.h>
#include <stdlib.h>

int *allocArray(int size){
  int *array;
  array = (int *)calloc(size, sizeof(int));
  return array;
}

void fillArray(int *array, int size){
  int i;
  for (i = 0; i < size; i++)
    array[i] = i;
}

void freeMemory(int *array){
  free(array);
}

void main(){
  int sizeArray = 1500, i;
  int *array = allocArray(sizeArray);
  fillArray(array, sizeArray);

  for(i = 0; i < 10; i++){
    printf("%d", array[i]);
    if(i + 1 != 10)
      printf(", ");
  }
  printf("\n");

  for (i = sizeArray - 10; i < sizeArray; i++){
    printf("%d", array[i]);
    if(i + 1 != sizeArray)
      printf(", ");
  }

  freeMemory(array);
}
