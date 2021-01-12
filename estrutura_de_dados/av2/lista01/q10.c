/*
Crie um programa em C, que contenha uma função recursiva para encontrar o menor elemento
em um vetor. A leitura dos elementos do vetor e impressão do menor elemento devem ser feitas no
programa principal
*/

#include <stdio.h>

#include <stdbool.h>

int smallElement(int *array, int size, int *small){
  if (array[size] == (sizeof(array) / sizeof(array[0]))) *small = array[size];
  if (array[size] < *small) *small = array[size];
  if (size == 0) return * small;
  smallElement(array, size - 1, small);
}

void main(){
  int array[] = {20, 2, 3, 4, 5, 6, 4, 3, 0, 2};
  int small;
  printf("\nretorno %d", smallElement(array, 9, &small));

}