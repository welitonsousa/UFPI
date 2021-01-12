/*
Escreva uma função recursiva que calcule o produto de todos os números que estão
presentes em uma posição par de um vetor de inteiros
*/
#include <stdio.h>

int product(int * array, int size){
  if (size == 0) return 1;
  int aux = 2;
  if(size % 2 == 1) aux = 1;
  return array[size - aux] * product(array, size - aux);
}

void main(){
  int array [] = {2, 2, 3, 4, 5, 9};
  printf("%d", product(array, 6));
}