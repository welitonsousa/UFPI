/*
Escreva uma função recursiva que calcule a média dos valores de um vetor de
inteiros
*/

#include <stdio.h>

float numberMagic = 0;
float media(float * array, int size){
    printf("array = %d\n", sizeof(array) / sizeof(float));
  if ((int) sizeof(array) / sizeof(float) == size) {
    numberMagic = size;}
  if (size == 0) return 0;
  return (float) array[size - 1] / 3 + media(array, size - 1);
}

void main(){
  float array[] = {8, 9, 8}; //total = 45

  printf("sum array = %f", media(array, 3));
}