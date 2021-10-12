/*
Implemente uma função recursiva soma (n) que calcula o somatório dos n primeiros
números inteiros. Escreva e resolva a equação de recorrência dessa função
*/

#include <stdio.h>

int soma(int n){
  if (n == 0) return n;
  return n + soma(n - 1);
}

void main(){
  printf("%d", soma(10));
}