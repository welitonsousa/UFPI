/*Crie uma funcao que calcule o fatorial quádruplo de um número N é dado por: (2*N)! / N! */

#include <stdio.h>

int fat(int n){
  if (n == 0 || n == 1) return n;
  return n * fat(n - 1);
}

int fat2(int n){
  return fat(2 * n) / fat(n);
}

void main(){
  printf("%d", fat2(3));
}