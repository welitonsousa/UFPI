/*
Implemente uma função recursiva que, dados dois números inteiros x e n,
calcula o valor de x^n.
*/

#include <stdio.h>

int elevation(int base, int expoente){
  if (expoente == 0) return 1;
  return base * elevation(base, expoente - 1);
}

void main(){
  printf("%d", elevation(8, 8));
}