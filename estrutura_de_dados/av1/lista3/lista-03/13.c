// Crie uma função que aloque um vetor de inteiros dinamicamente e em seguida,
// preencha o mesmo e inverta a ordem dos seus valores.

#include <stdio.h>
#include <stdlib.h>

int *allocArray(int size){
  int *array;
  array = (int *)calloc(size, sizeof(int));
  return array;
}

void fillArray(int *array, int size){
  int i;
  for ( i = 0; i < size; i++){
    array[i] = i;
  }
}

void invertArray(int *array, int size){
  int i;
  if (size % 2 == 0){
    for ( i = 0; i <= size / 2 - 1; i++){
      int aux = array[i];
      array[i] = array[size - i - 1];
      array[size - i - 1] = aux;
    }
  }
  if (size % 2 == 1){
    for ( i = 0; i <= (size - 1) / 2; i++){
      int aux = array[i];
      array[i] = array[size - i - 1];
      array[size - i - 1] = aux;
    }
  }
}

void showArray(int *array, int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
}

void main(){
  int size;
  scanf("%d", &size);
  int *array = allocArray(size);
  fillArray(array, size);
  showArray(array, size);
  invertArray(array, size);
  printf("\n");
  showArray(array, size);
}
