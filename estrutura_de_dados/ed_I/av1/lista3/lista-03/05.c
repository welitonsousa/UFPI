// Crie um algoritmo que, após receber do usuário uma cadeia simples de
// caracteres (apenas permitindo letras), seja capaz de imprimir na tela a mesma
// sequência inserida pelo usuário em letras maiúsculas, minúsculas e preencha um
// vetor com a sequência de caracteres inseridos alternando entre maiúsculas e
// minúsculas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

char *strupper(char *string){
  char *result = (char *) calloc(strlen(string), sizeof(char));
  int i;

  for (i = 0; i < strlen(string); i++){
    char characterUpper = toupper(string[i]);
    printf("%c", characterUpper);
    result[i] = characterUpper;
  }
  printf("\n");
  for (i = 0; i < strlen(string); i++){
    char characterLower = tolower(string[i]);
    printf("%c", characterLower);
    if(i % 2 == 1)
      result[i] = characterLower;
  }
  printf("\n");
  return result;
}

void main(){
  char userInput[100];
  scanf("%s", userInput);
  strcpy(userInput,strupper(userInput));
  printf("%s", userInput); 
}
