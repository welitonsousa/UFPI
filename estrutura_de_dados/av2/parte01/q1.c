#include <stdio.h>

int sucessor(int n){
  return n + 1;
}

int predecessor(int n){
  return n - 1;
}

int soma(int a, int b){
  if (b == 0) return a;
  soma(sucessor(a), predecessor(b));
}

void main(){
  printf("%d", soma(5, 5));
}