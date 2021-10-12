/*
A função fatorial duplo é definida como o produto de todos os números
naturais ímpares de 1 até algum número natural ímpar N. Assim, o fatorial
duplo de 5 é 5!! = 1 * 3 * 5 = 15 Faça uma função recursiva que receba
um número inteiro positivo impar N e retorne o fatorial duplo desse
número
*/

#include <stdio.h>

int fatDuplo(int fat){
  if (fat == 0 || fat == 1) return fat;
  else if (fat % 2 == 0) return -1;
  return fat * fatDuplo(fat - 2);
}

void main(){
  printf("%d", fatDuplo(5));
}