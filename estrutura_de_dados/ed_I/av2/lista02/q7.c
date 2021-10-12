/*
Escreva um algoritmo recursivo para avaliar a * b usando a adição, onde a e b são
inteiros não-negativos
*/
#include <stdio.h>

int multplicacao(int a, int b){
  if (b == 0) return 0;
  return a + multplicacao(a, b - 1);
} 

void main(){
  printf("%d", multplicacao(2,3));
}