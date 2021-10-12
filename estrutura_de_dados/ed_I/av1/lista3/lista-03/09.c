// Crie uma função que, dado determinado vetor V de ordem ímpar alocado
// dinamicamente, imprima os seus valores “do centro para fora” e logo após libere
// a memória antes ocupada por V.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *allocArray(int n){
  int *array;
  array = (int *)calloc(n, sizeof(int));
  return array;
}

void showArray(int *vetor, int n){
  int i;
  for (i = 0; i < n; i++){
    printf("%d", vetor[i]);
    if (i + 1 != n)
      printf(", ");
  }
}

void showArray(int *array, int n){
  //mostrar array de dentro para fora
  int metade = (n - 1) / 2;
  printf("%d\n", array[(int) n/2]);
  int i = 0;
  do{
    i++;
    printf("%d, %d\n", array[metade - i], array[metade + i]);
  }while (metade - i > 0);
}

void freeMemory(int *array){
  free(array);
}

void main(){
  int n = 7, i;
  int *array = allocArray(n);

  srand(time(NULL)); 
  for (i = 0; i < n; i++)
    array[i] = rand() % 100;

  showArray(array, n);
  printf("\n");
  showArray(array, n);
  freeMemory(array);
}
