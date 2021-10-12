// Crie um programa que, dadas 6 strings inseridas pelo usuário (mínimo 4
// caracteres) alocadas dinamicamente (podem ser alocadas em uma matriz de
// caracteres ou 6 vetores), seja capaz de exibir qual a menor e qual a maior entre
// as strings inseridas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
  int i;
  char **words = (char **)calloc(6 ,sizeof(char *));
  char *smallWord, *bigWord;

  for (i = 0; i < 6; i++){
    char userInput[100];
    scanf("%s", userInput);
    int inputSize = strlen(userInput);

    words[i]  = (char *)calloc(inputSize, sizeof(char));
    strcpy(words[i], userInput);

    if(i == 0){
      smallWord  = (char *)calloc(inputSize, sizeof(char));
      bigWord  = (char *)calloc(inputSize, sizeof(char));
      strcpy(smallWord, userInput);
      strcpy(bigWord, userInput);
    
    }else if(inputSize > strlen(bigWord)){
      bigWord  = (char *)calloc(inputSize, sizeof(char));
      words[i]  = (char *)calloc(inputSize, sizeof(char));
      strcpy(bigWord, userInput);
      strcpy(words[i], userInput);

    }else if(inputSize < strlen(smallWord)){
      smallWord  = (char *)calloc(inputSize, sizeof(char));
      words[i]  = (char *)calloc(inputSize, sizeof(char));
      strcpy(smallWord, userInput);
      strcpy(words[i], userInput);
    }
  }
  printf("Maior string = %s\n", bigWord);
  printf("Menor string = %s\n", smallWord);
}