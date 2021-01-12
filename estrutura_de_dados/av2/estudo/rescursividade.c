#include <stdio.h>

int fatorial(int fat){
  if (fat == 0 || fat == 1) return 1;
  return fat * fatorial(fat - 1);
}

int sumArray(int *array, int size){
  if (size == 0) return 0;
  return array[size - 1] + sumArray(array, size - 1);
}

void main(){
  int array[] = {6, 2, 3, 4, 5, 6, 7, 8, 9}; //total = 45

  printf("fat = %d\n", fatorial(3));
  printf("sum array = %d", sumArray(array, 9));
}