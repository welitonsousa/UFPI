/*
Escreva uma função recursiva maxmin que calcule o valor de um elemento máximo
e o valor de um elemento mínimo de um vetor
*/

#include <stdio.h>

void smallAndBigElement(int * array, int size, int * small, int * big){
  if (array[size] == (sizeof(array) / sizeof(int))) {
    *small = array[size];
    *big = array[size];
  }
  if (array[size] > * big) * big = array[size];
  if (array[size] < *small) * small = array[size];
  if (size == 0) return;
  
  smallAndBigElement(array, size - 1, small, big);
}

void main(){
  int array[] = {20, 2, 3, 4, 5, 6, 4, 3, 0, 2};
  int small, big;
  smallAndBigElement(array, 9, &small, &big);
  printf("maior = %d\nmenor = %d", big, small);

}