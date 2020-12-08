// Implemente a função char *inverte(char *s) que cria dinamicamente uma nova
// string contendo a string s invertida.

#include <stdio.h>
#include <stdlib.h>

void invertString(char *string, int size){
  int i, len = size;
  for (i = 0; i < (int) size / 2; i++){
    char aux = string[i];
    string[i] = string[(len - 2)];
    string[(len - 2)] = aux;
    len -= 1;
  }
}

void main(){
  int size;
  scanf("%d", &size);
  char *string = (char *)calloc(size, sizeof(char));
  scanf("%s", string);

  invertString(string, size);
  printf("%s", string);
}
