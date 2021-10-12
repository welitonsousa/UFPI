/*
Escreva uma função recursiva que calcule a soma dos dígitos de um número inteiro. Por
exemplo, se a entrada for 123, a saída deverá ser 1+2+3 = 6
*/

#include <stdio.h>

int sunDigit(int number, int *numberAdded){
  if (number == 0) return *numberAdded;
  *numberAdded += number % 10;
  sunDigit(number / 10, numberAdded);
}

void main(){
  int sun = 0;
  printf("%d", sunDigit(123, &sun));
}