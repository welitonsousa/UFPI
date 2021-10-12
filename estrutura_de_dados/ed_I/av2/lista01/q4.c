/*
Escreva uma função recursiva que retorne quantas vezes um número X aparece em um dado
número natural. Por exemplo, o número 3 aparece 2 vezes no número 45303
*/

#include <stdio.h>

int count = 0;

int countRepetition(int number, int numberChecker){
  if (number == 0) return count;
  else if (number % 10 == numberChecker) count ++;
  return countRepetition(number / 10, numberChecker);
}

void main(){
  printf("%d", countRepetition(2332342, 2));
}