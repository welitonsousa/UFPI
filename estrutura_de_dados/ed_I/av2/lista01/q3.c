/*
Crie uma função recursiva que imprima em ordem inversa os dígitos de um valor inteiro
(de tamanho qualquer) inserido pelo usuário.
*/


int invert(int n, int aux){
  if (n == 0) return aux;
  return invert(n / 10, (aux * 10) + (n % 10));
}