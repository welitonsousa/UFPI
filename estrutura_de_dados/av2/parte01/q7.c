/*
Dado um número n na base decimal, escreva uma função recursiva em C
que converte este número para binário
*/

#include <stdio.h>
#include "./../lista01/q3.c"

int binary = 0;
int decimalToBinary(int decimal){
  if (decimal == 0) return invert(binary, 0);
  binary = (binary * 10) + decimal % 2;
  return decimalToBinary(decimal/2);
}

void main(){
  printf("%d",decimalToBinary(39));
}