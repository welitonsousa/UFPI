#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void mostrarOcorrencias(int **ocorre, int size){
  for (int i = 0; i < size; i++){
    printf("%d X %d\n", ocorre[0][i], ocorre[1][i]);
  }
}

int **ocorrencias(int **mat, int l, int c){
  int **ocorre = (int **)calloc(2, sizeof(int));
  int sizeOcorre = 0;

  for(int i = 0; i < 2; i++){
    ocorre[i] = (int *)calloc(1, sizeof(int));
  }
  
  for (int n = 0; n <= 1000; n++){
    int cont = 0;
    for (int i = 0; i < l; i++){
      for (int j = 0; j < c; j++){
        if (mat[i][j] == n){
          cont++;
        }
      }
    }
    if (cont != 0){
      if (sizeOcorre > 0){
        for(int z = 0; z < 2; z++){
          ocorre[z] = (int *)realloc(ocorre[z], (sizeOcorre + 1) * sizeof(int));
        }
      }

      ocorre[0][sizeOcorre] = n;
      ocorre[1][sizeOcorre] = cont;
      sizeOcorre++;
    }
  }
  mostrarOcorrencias(ocorre, sizeOcorre);
  return ocorre;
}

int **preencher(int l, int c){
  int **mat = (int **)calloc(l, sizeof(int));
  for (int i = 0; i < l; i++){
    mat[i] = (int *)calloc(c, sizeof(int));
  }
  for (int i = 0; i < l; i++){
    for (int j = 0; j < l; j++){
      mat[i][j] = rand() % 1001;
    }
  }
  return mat;
}

void main(){
  int **mat, m, n, **ocorre;
  srand(time(NULL));
  printf("Linhas por colunas no formato abaixo\n");

  printf("MXN: ");
  scanf("%dX%d", &m, &n);

  mat = preencher(m, n);
  mat = ocorrencias(mat, m, n);

  for (int i = 0; i < m; i++){
    free(mat[i]);
  }
}
