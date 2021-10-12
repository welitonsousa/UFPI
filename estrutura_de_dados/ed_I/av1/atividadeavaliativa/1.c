#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int **circulo(int **mat, int linha, int coluna, int raio, int raio2){
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      float dis = (float)sqrt(pow(raio2 - j, 2) + pow(raio - i, 2));
      if(dis <= raio){
        mat[i][j] = 1;
      }
    }
  }
  return mat;
}

void main(){
  int linha = 0, coluna = 0;
  printf("Tamanho da matriz: ");
  scanf("%d", &linha);
  coluna = linha * 5;

  int **mat = (int **) calloc(linha, sizeof(int));
  for (int i = 0; i < linha; i ++){
    mat[i] = (int *) calloc(coluna, sizeof(int));
  }
  int raio = (int) linha/2;

  mat = circulo(mat, linha, coluna, raio, raio);
  mat = circulo(mat, linha, coluna, raio, raio*3);
  mat = circulo(mat, linha, coluna, raio, raio*5);
  mat = circulo(mat, linha, coluna, raio, raio*7);
  mat = circulo(mat, linha, coluna, raio, raio*9);

  for(int i = 0; i <linha; i++){
    for(int j = 0; j < coluna; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }

}