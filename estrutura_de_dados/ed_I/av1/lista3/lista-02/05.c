/*
Escreva uma função que receba 2 vetores inteiros, v1 e v2, e suas respectivas quantidades de
elementos q1 e q2, que retorne um ponteiro para uma matriz, de ordem q1 x q2, alocada
dinamicamente, que contenha a multiplicação de cada elemento de v1 pelos elementos de v2. 
*/
#include <stdlib.h>
#include <stdio.h>

int **matriz(int *v1, int *v2, int q1, int q2){
    int **mat = (int **)calloc((q1) ,sizeof(int));
    int i, j;

    for(i = 0; i< q1; i++){
        mat[i] = (int *) calloc(q2, sizeof(int));
    }
    for(i = 0; i< q1; i++){
        for(j = 0; j< q2; j++){
            mat[i][j] = v1[i] * v2[j];
        }
    }
    return mat;
}

void main(){
    int vet1[] = {1, 2, 3, 4, 5};
    int vet2[] = {2, 4, 6};
    int i, j, sizeVet1 = (int) sizeof(vet1)/sizeof(int),  sizeVet2 = (int) sizeof(vet2)/sizeof(int);
   
    int **mat = matriz(vet1, vet2, sizeVet1, sizeVet2);
    for(i = 0; i <sizeVet1; i++){
        for(j = 0; j <sizeVet2; j++){
            printf("%02d ", mat[i][j]);
        }
        printf("\n");
    }
}   