/*
Crie um algoritmo que receba do usuário a quantidade de elementos a ser
inserida em um vetor de inteiros. Logo após, preencha este vetor, imprima os
seus elementos e exiba a soma dos seus elementos impares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *allocArray(int size){
  int *array;
  array = (int *)calloc(size, sizeof(int));
  return array;
}

void showArray(int *array, int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d, ", array[i]);
}

void freeMemory(int *array){
  free(array);
}

void sumOdd(int *array, int size){
  int sum = 0, i;
  for (i = 0; i < size; i++){
    if (array[i] % 2 == 1)
      sum += array[i];
  }
  printf("Soma dos impares: %d", sum);
}

void main(){
  int n, i;
  scanf("%d", &n);
  int *vet = allocArray(n);
  
  srand(time(NULL));
  for ( i = 0; i < n; i++)
    vet[i] = rand() % 10;

  showArray(vet, n);

  sumOdd(vet, n);
  freeMemory(vet);
}
