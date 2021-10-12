/*
Considerando a existência de duas matrizes de números inteiros (A[5][5] e
B[5][5]), desenvolva uma função que retorne a soma entre estas duas matrizes
usando alocação dinâmica de memória. Após a exibição, libere a memória
ocupada pelas três matrizes criadas.
*/

#include <stdio.h>
#include <stdlib.h>

void freeMemory(int **matriz, int m){
  int i;
  for ( i = 0; i < m; i++)
    free(matriz[i]);
  free(matriz);
}

int **joinMatriz(int **matUnion, int **matriz1, int **matriz2, int m, int n){
  int i, j;
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++)
      matUnion[i][j] = matriz1[i][j] + matriz2[i][j];
  }
  return matUnion;
}

int **allocMatriz(int **mat, int line, int colum){
  int i;
  mat = (int **)malloc(line * sizeof(int));
  for (i = 0; i < colum; i++)
    mat[i] = (int *) malloc(colum * sizeof(int));
  return mat;
}

int **fillMatriz(int **mat, int line, int colum){
  int i, j;
  for (i = 0; i < line; i++){
    for (j = 0; j < colum; j++)
      mat[i][j] = j;
  }
  return mat;
}

void showMattriz(int **mat, int line, int colum){
  int i, j;
  for (i = 0; i < line; i++){
    for (j = 0; j < colum; j++)
      printf("%d ",mat[i][j]);
  printf("\n");
  }
}

void main(){
  int i, j, sizeLine = 5, sizeColum = 5;
  int **mat1 = allocMatriz(mat1, sizeLine, sizeColum);
  int **mat2 = allocMatriz(mat2, sizeLine, sizeColum);
  int **unionMat = allocMatriz(mat2, sizeLine, sizeColum);

  mat1 = fillMatriz(mat1, sizeLine, sizeColum);
  mat2 = fillMatriz(mat2, sizeLine, sizeColum);
  
  unionMat = joinMatriz(unionMat ,mat1, mat2, sizeLine, sizeColum);
  showMattriz(unionMat, sizeLine, sizeColum);

  freeMemory(mat1, sizeLine);
  freeMemory(mat2, sizeLine);
  freeMemory(unionMat, sizeLine);
}
