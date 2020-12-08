// Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e
// as suas respectivas quantidades de elementos, n1 e n2. A função deverá retornar um
// ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2) elementos,
// alocado dinamicamente, contendo a união de v1 e v2. Por exemplo, se v1 = {11, 13, 45,
// 7} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}.

#include <stdio.h>
#include <stdlib.h>

int * joinArray(int * array1, int * array2, int sizeArray1, int sizeArray2, int *sizeArray3){
  int i, *join = (int *) calloc(sizeArray1 + sizeArray2, sizeof(int));
  for (i = 0; i < sizeArray1; i++)
    join[i] = array1[i];
  for (i = sizeArray1; i < sizeArray2 + sizeArray1; i++)
    join[i] = array2[i - sizeArray1];
  *sizeArray3 = sizeArray1 + sizeArray2;
  return join;
}

int main(){
  int sizeArray1 = 5, sizeArray2 = 5, sizeArray3, i;
  int array1[] = {1,2,3,4,5};
  int array2[] = {6,7,8,9,10};
  
  int *arrayJoined = joinArray(array1, array2, sizeArray1, sizeArray2, &sizeArray3);
  for (i = 0; i < sizeArray3; i++){
    printf("%d ",arrayJoined[i]);
  }
}
