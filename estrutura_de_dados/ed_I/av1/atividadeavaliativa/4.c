#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main(){
  int n = 0;
  printf("Tamanho da matriz: ");
  scanf("%d", &n);
  int **mat = (int **) calloc(n, sizeof(int));
  for (int i = 0; i < n; i ++){
    mat[i] = (int *) calloc(n, sizeof(int));
  }

  int raio = (int) n/2;
  int raioMenor = raio/2;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      float dis = (float)sqrt(pow(raio - j, 2) + pow(raio - i, 2));
      if(dis <= raio){
        mat[i][j] = 1;
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      float dis = (float)sqrt(pow(raio - j, 2) + pow(raio - i, 2));
      if(dis <= raioMenor){
        mat[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }

  for(int i = 0; i< n; i++){
    free(mat);
  }
}