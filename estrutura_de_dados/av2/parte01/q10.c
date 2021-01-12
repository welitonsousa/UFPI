/*
Crie uma função recursiva onde dado N valores, imprimir todos os
números naturais de 0 até N em ordem decrescente
*/

#include <stdio.h>

void rangeShow(int * array, int lastElementShow){
  printf("%d ",array[lastElementShow]);
  if (lastElementShow == 0) return;
  rangeShow(array, lastElementShow - 1);
}

void main(){
  int array [] = {1,2,3,4,5,6,7,8,9,10};
  rangeShow(array, 5);
}