// Construa um programa (main) que aloque em tempo de execução (dinamicamente)
// uma matriz de ordem m x n (linhas por colunas), usando 2 chamadas a função malloc.

#include <stdio.h>
#include <stdlib.h>

void main(){
  int line, column, i, j;
  scanf("%d %d", &line, &column);

  int **mat;

  mat = (int **)calloc(line, sizeof(int));
  mat[0] =(int *) calloc(line, column * sizeof(int));

  for (i = 1; i < line; i++)
    mat[i] = mat[0] + i * column;

  for(i = 0; i < line; i++){
    for(j = 0; j < column; j++){
      mat[i][j] = j;
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}
