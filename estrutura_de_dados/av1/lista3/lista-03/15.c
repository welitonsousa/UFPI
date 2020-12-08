// (QUESTÃO DESAFIO) escreva uma função que, dado determinado vetor de no
// máximo 3 caracteres, seja capaz de devolver todos os anagramas possíveis, ou
// seja, todas as sequencias passíveis de formação com os caracteres inseridos no
// vetor. (Obs.: Não é necessário verificar a validade das palavras. Apenas exiba as
// possibilidades.)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *allocArray(int size){
  char *array;
  array = (char *)calloc(size, sizeof(char));
  return array;
}

void showAnagrams(char *array, int size){
  int i, j;
  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++)
      printf("%c",array[j]);
    printf("\n");
    for(j = size; j >= 0 && size >= 3; j--)
      printf("%c",array[j]);
    if(size >= 3)
      printf("\n");
    if(i + 1 != size){
      char aux = array[i];
      array[i] = array[i + 1];
      array[i + 1] = aux;
    }
  }
}

void main(){
  int size = 4;
  char *array = allocArray(size);
  scanf("%s", array);
  
  size = strlen(array);
  showAnagrams(array, size);
}
