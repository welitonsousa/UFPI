// Faça um programa que crie dinamicamente uma matriz de números do tipo float.
// Depois preencha a matriz com números digitados pelo usuário.

#include <stdio.h>
#include <stdlib.h>

float **allocMat(int line, int column){
  float **mat;
  int i;
  mat = (float **)calloc(line, sizeof(float));
  for (i = 0; i < line; i++)
    mat[i] = (float *)calloc(column, sizeof(float));
  return mat;
}

void fillMat(int m, int n, float **mat){
  int i, j;
  for ( i = 0; i < m; i++){
    for ( j = 0; j < n; j++)
      scanf("%f", &mat[i][j]);
  }
}



void main(){
  int line, column, i, j;
  scanf("%d %d", &line, &column);
  float **mat = allocMat(line, column);
  fillMat(line, column, mat);
  //showMat(line, column, mat);
  for ( i = 0; i < line; i++){
    for ( j = 0; j < column; j++)
      printf("%.2f ", mat[i][j]);
    printf("\n");
  }
}
