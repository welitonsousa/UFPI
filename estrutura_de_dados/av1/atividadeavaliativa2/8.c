#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ***distanciaEspacial(int ***cubo, int size){
  int centro = (int) size/2;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      for(int h = 0; h < size; h++){
        int distancia = sqrt(pow(centro - h, 2) + pow(centro - j, 2) + pow(centro - i, 2)); 
        if(distancia <= centro){
          cubo[i][j][h] = 1;
        }
      }
    }
  }
  return cubo;
}

int ***allocCubo(int size){
  int ***cubo = (int ***) calloc(size, sizeof(int));
  for(int i = 0; i < size; i++){
    cubo[i] = (int **) calloc(size, sizeof(int));
    for(int j = 0; j < size; j++){
      cubo[i][j] = (int *) calloc(size, sizeof(int));
    }
  }
  return cubo;
}

void main(){
  int ***cubo, size = 5;
  cubo = allocCubo(size);
  cubo = distanciaEspacial(cubo, size);
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      for(int h = 0; h < size; h++){
        printf("%d ", cubo[i][j][h]);
      }
      printf("\n");
    }
    printf("\n");
  }
}