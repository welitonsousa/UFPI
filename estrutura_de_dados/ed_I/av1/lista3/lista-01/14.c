// Faça um programa que leia o tamanho de um vetor de inteiros e reserve
// dinamicamente memoria para esse vetor. Em seguida, leia os elementos desse vetor,
// imprima o vetor lido e mostre o resultado da soma dos numeros ímpares presentes no
// vetor.

#include <stdio.h>
#include <stdlib.h>

void showArray(int *array, int size){
  int i;
  for ( i = 0; i < size; i++)
    printf("%d ", array[i]);
}

int sumOdd(int *array, int size){
  int soma = 0, i;
  for (i = 0; i < size; i++){
    if (array[i] % 2 == 1)
      soma += array[i];
  }
  return soma;
}

void main(){
  int n, i;
  
  scanf("%d", &n);
  int *array = (int *) calloc(n, sizeof(int));

  for (i = 0; i < n; i++)
    array[i] = i;

  showArray(array, n);
  int sumImpares = sumOdd(array, n);
  printf("\nSoma dos impares: %d", sumImpares);
}
