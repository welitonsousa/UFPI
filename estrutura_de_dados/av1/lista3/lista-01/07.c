// Implemente a função char *repete(char *s, int n) que cria dinamicamente uma nova
// string com n cópias da string original, separadas por espaço, exceto a última
// ocorrência. Exemplo: repete(“Ola”,4) -> “Ola Ola Ola Ola”.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repete(char *s, int n){
  char *string;
  int i, j, size = strlen(s) - 1;

  string = (char *)calloc((size+10) * n, sizeof(char));
  
  strcpy(string, s);
  for ( i = 0; i < n - 1; i++){
    if( i + 1 != n)
      strcat(string, " ");
    strcat(string, s);
  }
  return string;
}
void main(){
  int i;
  char *stringNova = repete("Hello", 3);
  printf("%s", stringNova);
}
