/*
Construa um programa (main) que aloque em tempo de execução (dinamicamente) uma
matriz de ordem m x n (linha por coluna), usando 2 chamadas à função malloc. Agora, aproveite
este programa para construir uma função que recebendo os parâmetros m e n aloque uma matriz de
ordem m x n e retorne um ponteiro para esta matriz alocada. Crie ainda uma função para liberar a
área de memória alocada pela matriz. Finalmente, crie um novo programa(main) que teste/use as
duas funções criadas acima. 
*/

#include <stdio.h>
#include <stdlib.h>

int **allocMatriz(int m, int n);
void freeMemory(int **mat, int sizeColum);

void main(){
  int **mat, m = 5, n = 5, i, j;
  mat = allocMatriz(m, n);

  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      mat[i][j] = j;
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  freeMemory(mat, n);
}

int **allocMatriz(int m, int n){
  int i;
  int **mat = (int **)malloc(m * sizeof(int *));
  for (i = 0; i < n; i++)
    mat[i] = (int *)malloc(n * sizeof(int));
  return mat;
}

void freeMemory(int **mat, int sizeColum){
  int i;
  for (int i = 0; i < sizeColum; i++)
    {
        free(mat[i]);
    }
    free(mat);
}