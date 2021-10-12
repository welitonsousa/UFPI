#include <stdio.h>

int expo(int number, int exp){
  if(exp == 0) return 1;
  return number * expo(number, exp - 1);
}

void main(){
  printf("%d", expo(3, 3));
}

