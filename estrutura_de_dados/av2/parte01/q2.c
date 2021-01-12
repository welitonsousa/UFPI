#include <stdio.h>

int initial = 0;
void invert(int * array, int size){
  
  int aux = array[size];
  array[size] = array[initial];
  array[initial] = aux;
  
  if (size == initial) return;
  initial += 1;
  invert(array, size - 1);
}

void main(){
  int a [] = {1,2,3};
  invert(a, 2);
  for(int i = 0; i < 3; i++){
    printf("%d ",a[i]);
  }
}