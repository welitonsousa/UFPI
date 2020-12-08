/*
Crie uma função que percorra um determinado vetor alocado dinamicamente
sem utilizar índices, apenas com a aritmética de ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *allocArray(int n){
  int *array;
  array = (int *)calloc(n, sizeof(int));
  return array;
}

void showAray(int *array, int n){
  int i;
  for (i = 0; i < n; i++){
    printf("%d", *(array + i));
    if(i + 1 != n)
      printf(", ");
  }
}

void freeMemory(int *array){
  free(array);
}

void main(){
  int sizeArray, i;
  scanf("%d", &sizeArray);
  int *array = allocArray(sizeArray);

  srand(time(NULL));
  for (i = 0; i < sizeArray; i++)
    *(array + i) = rand() % 100;
  showAray(array, sizeArray);
  freeMemory(array);
}
