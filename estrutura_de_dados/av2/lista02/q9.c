#include <stdio.h>

int search(int * array, int sizeArray, int value){
  if (array[sizeArray - 1] == value) return sizeArray - 1; 
  search(array, sizeArray - 1, value);
}

void main(){
  int array [] = {1,2,3,4,5,6};
  printf("posicao de 3 = %d", search(array, 6, 3));

}