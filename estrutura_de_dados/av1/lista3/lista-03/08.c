// Crie um algoritmo que, dados dois valores N e M inseridos pelo usuário, crie a
// matriz MxN alocada dinamicamente, preencha-a (com valores aleatórios ou
// inseridos pelo usuário) e logo após, aloque e preencha a sua matriz transposta e
// em seguida imprima ambas.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocMat(int m, int n){
  int **matriz, i;
  matriz = (int **)calloc(m, sizeof(int *));
  for (i = 0; i < m; i++)
    matriz[i] = (int *)calloc(n, sizeof(int));
  return matriz;
}

void freeMemory(int **mat, int m){
  int i;
  for ( i = 0; i < m; i++)
    free(mat[i]);
  free(mat);
}

void fillMat(int m, int n, int **mat){
  srand(time(NULL));
  int i, j;
  for ( i = 0; i < m; i++){
    for ( j = 0; j < n; j++)
      mat[i][j] = rand() % 100;
  }
}

void fillMatT(int m, int n, int **mat, int **trans){
  int i, j;
  for ( i = 0; i < m; i++){
    for ( j = 0; j < n; j++)
      trans[j][i] = mat[i][j];
  }
}

void showMat(int **mat, int m, int n){
  int i, j;
  for ( i = 0; i < m; i++){
    for ( j = 0; j < n; j++){
      printf("%03d", mat[i][j]);
      if(j + 1 != n)
        printf(", ");
    }
    printf("\n");
  }
}

void main(){
  int m, n;
  scanf("%d %d", &m, &n);
  int **mat = allocMat(m, n);
  fillMat(m, n, mat);
  
  int **matT = allocMat(n, m);
  fillMatT(m, n, mat, matT);
  showMat(mat, m, n);
  printf("\n");

  showMat(matT, n, m);
  freeMemory(mat, m);
  freeMemory(matT, m);
}
