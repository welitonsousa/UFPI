#include <stdio.h>

int invert(int n, int aux){
  if (n == 0) return aux;
  return invert(n / 10, (aux * 10) + (n % 10));
}

void main(){
  printf("%d", invert(321, 0));
}
