// Escreva um programa em linguagem C que solicita ao usuário a quantidade de
// alunos de uma turma e aloca um vetor de notas (números reais). Depois de ler as
// notas, imprime a média aritmética. Não deve ocorrer desperdício de memória; e após
// ser utilizada a memória deve ser desalocada.

#include <stdio.h>
#include <stdlib.h>

float mid(float *vetor, int n){
  float sum = 0, i;
  for (i = 0; i < n; i++)
    sum += vetor[(int)i];
  return sum / n;
}

void main(){
  int n, index;
  printf("quantidade de alunos: ");
  scanf("%d", &n);
  
  float *vetor = (float *)calloc(n, sizeof(float));

  for (index = 0; index < n; index++){
    printf("Nota %d: ", index + 1);
    scanf("%f", &vetor[index]);
  }

  float media = mid(vetor, n);
  printf("%.2f", media);
}
