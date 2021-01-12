/*
Escreva uma função recursiva onde dado um vetor de números inteiros,
retorne o menor elemento
*/

#include <stdio.h>

int smallElement(int *array, int size, int *small){
  if (array[size] == (sizeof(array) / sizeof(array[0]))) *small = array[size];
  if (array[size] < *small) *small = array[size];
  if (size == 0) return * small;
  smallElement(array, size - 1, small);
}

void main(){
  int array[] = {20, 2, 3, 4, 5, 6, 4, 3, 0, 2};
  int small;
  printf("%d", smallElement(array, 9, &small));

}
