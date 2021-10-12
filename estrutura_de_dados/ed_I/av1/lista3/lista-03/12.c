// Crie uma função que, dadas duas strings S1 e S2 alocadas dinamicamente, troque
// seus conteúdos e imprima na tela o resultado da troca.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *allocArray(int size){
  char *array;
  array = (char *)calloc(size, sizeof(char));
  return array;
}

int main(){
  char *string1 = allocArray(7);
  char *string2 = allocArray(5);
  int sizeBigString = 0;

  strcpy(string1, "weliton");
  strcpy(string2, "sousa");
  int sizeString1 = strlen(string1);
  int sizeString2 = strlen(string2);
  
  if (sizeString1 > sizeString2)
    sizeBigString = sizeString1;
  else
    sizeBigString = sizeString2;
  
  char *auxiliar = allocArray(sizeBigString);
  
  strcpy(auxiliar, string1);
  strcpy(string1, string2);
  strcpy(string2, auxiliar);
  
  printf("%s\n", string1);
  printf("%s", string2);
}
