// Faça um programa que aloque continuamente os valores inteiros digitados pelo
// usuário em um vetor. A alocação deve terminar quando um número negativo for
// inserido. Após, imprima na tela o vetor criado com as inserções.

#include <stdio.h>
#include <stdlib.h>

int main(){
  int input = 0, i, index = 0, *listNumbers; 
  while(1){
    scanf("%d", &input);
    if(input < 0)
      break;
    if(index > 0)
      listNumbers = (int *) realloc(listNumbers , (index+1) * sizeof(int));
    else
      listNumbers = (int *) calloc(1 , sizeof(int));
    listNumbers[index] = input;
    index++;
  }
  for(i = 0; i < index; i++)
    printf("%d ", listNumbers[i]);
}
