// Crie um programa para manipular vetores. O seu programa deve implementar uma
// função que receba um vetor de inteiros V e retorne um outro vetor de inteiros alocado
// dinamicamente com todos os valores de V que estejam entre o valor mínimo e máximo
// (que também são passados como parâmetro para a função).

#include <stdio.h>
#include <stdlib.h>

int *rangeArray(int *vetor, int min, int max){
  int *pont = (int *)calloc(max - min + 1, sizeof(int));
  int j = min, i;
  for (i = 0; i <= max - min + 1; i++){
    pont[i] = j;
    j++;
  }
  return pont;
}

void main(){
  int n = 3, array[5] = {1,2,3,4,5};
  int *newArray = rangeArray(array, 2, 5);
}
