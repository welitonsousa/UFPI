/*
Desenvolva um algoritmo que calcula a multiplicação de uma matriz por um vetor.
Considere uma matriz quadrada. Use alocação dinâmica para o vetor e para a matriz. Ao
final, liberar a memória
*/

#include <stdio.h>
#include <stdlib.h>

void freeMemory(int **mat, int size){
  for (int i = 0; i < size; i++)
    free(mat[i]);
}

void main(){
  int sizeArray;
  
  printf("Tamanho do vetor: ");
  scanf("%d", &sizeArray);
  
  int *array = (int *) calloc(sizeArray, sizeof(int));
  int **mat = (int **) calloc(sizeArray, sizeof(int));
  int **oldMat = (int **) calloc(sizeArray, sizeof(int));
  
  for (int i = 0; i < sizeArray; i++){
    oldMat[i] = (int *) calloc(sizeArray, sizeof(int));
    mat[i] = (int *) calloc(sizeArray, sizeof(int));
    array[i] = i;
    for (int j = 0; j < sizeArray; j ++)
      mat[i][j] = j;
  }

  for (int i = 0; i < sizeArray; i++){
    for (int j = 0; j < sizeArray; j ++){
      oldMat[i][j] = mat[i][j] * array[j];
      printf("%d ",oldMat[i][j]);
    }
    printf("\n");
  }

  freeMemory(mat, sizeArray);
  freeMemory(oldMat, sizeArray);
  free(array);
}