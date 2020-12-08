// Desenvolva um programa que calcule a soma de duas matrizes MxN de números
// reais (double). A implementação deste programa deve considerar as dimensões
// fornecida pelo usuário (Dica: represente a matriz através de variáveis do tipo
// double **, usando alocação dinâmica de memória).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **allocMat(int m, int n){
  double **matriz;
  int i;
  matriz = (double **)calloc(m, sizeof(double *));
  for ( i = 0; i < m; i++){
    matriz[i] = (double *)calloc(n, sizeof(double));
  }
  return matriz;
}

void fillMat(int m, int n, double **matriz){
  int i, j;
  for ( i = 0; i < m; i++){
    for ( j = 0; j < n; j++)
      matriz[i][j] = rand() % 100;
  }
}

void sum(int m, int n, double **matriz1, double **matriz2, double **soma){
  int i,j;
  for ( i = 0; i < m; i++){
    for ( j = 0; j < n; j++)
      soma[i][j] = matriz1[i][j] + matriz2[i][j];
  }
}

void showMat(double **Matriz, int m, int n){
  int i, j;
  for ( i = 0; i < m; i++){
    for ( j = 0; j < n; j++)
      printf("%.2f ", Matriz[i][j]);
    printf("\n");
  }
  printf("\n");
}

void main(){
  srand(time(NULL));
  int m, n;
  scanf("%d %d", &m, &n);
  
  double **matriz1 = allocMat(m, n);
  double **matriz2 = allocMat(m, n);
  double **matrizSoma = allocMat(m, n);
  
  fillMat(m, n, matriz1);
  fillMat(m, n, matriz2);
  sum(m, n, matriz1, matriz2, matrizSoma);
  
  showMat(matriz1, m, n);
  showMat(matriz2, m, n);
  showMat(matrizSoma, m, n);
}
