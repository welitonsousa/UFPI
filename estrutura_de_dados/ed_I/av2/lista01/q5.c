/*
Escreva uma função recursiva que receba um valor na base decimal e retorne ao método
principal seu respectivo valor de base binária
*/

#include <stdio.h>
#include "q3.c"

int binary = 0;
int decimalToBinary(int decimal){
  if (decimal == 0) return invert(binary, 0);
  binary = (binary * 10) + decimal % 2;
  return decimalToBinary(decimal/2);
}

void main(){
  printf("%d",decimalToBinary(39));
}