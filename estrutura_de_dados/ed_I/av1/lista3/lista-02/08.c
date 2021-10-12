/*
Escreva uma função que receba uma String (cadeia de caracteres) e um caractere, percorra a
String, conte a quantidade de vezes que o caractere se repete, armazene em um vetor as posições
que o caractere foi encontrado e retorne um ponteiro para o vetor alocado.
*/
#include <stdlib.h>
#include <stdio.h>

int *countItem(char *string, char character, int *size){
  int *position, sizePosition = 0, i;
  for(i = 0; string[i] != '\0'; i++){

    if(string[i] == character){
      sizePosition ++;
      if(sizePosition == 1){
        position = (int *) malloc(sizePosition * sizeof(int));
      }else{
        position = (int *) realloc(position, 4 * sizePosition);
      }
      position[sizePosition - 1] = i;
    }
  }
  printf("\"%c\" se repetiu %d vezes", character, sizePosition);
  *size = sizePosition;
  return position;
}
void main(){
  int i, size;
  int *positions = countItem("weliton de sousa araujo", 'e', &size);
  printf("\n");
  for(i = 0; i< size; i++){
    printf("%d ", positions[i]);
  }
}