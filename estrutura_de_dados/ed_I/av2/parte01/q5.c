/*
Crie uma função recursiva que retorne a soma dos elementos de um vetor
de inteiros
*/

#include <stdio.h>

int sumArray(int *array, int size){
  if (size == 0) return 0;
  return array[size - 1] + sumArray(array, size - 1);
}

void main(){
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //total = 45

  printf("sum array = %d", sumArray(array, 9));
}