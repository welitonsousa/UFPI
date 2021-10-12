/*
Escreva uma função que receba um valor N e aloque dinamicamente um vetor de inteiros com N
elementos, uma função que libere o espaço de memória utilizado, um função que imprima os
elementos de um vetor na tela e, por fim, realize testes de todas as funções anteriores em main. 
*/

#include <stdio.h>
#include <stdlib.h>

int *createArray(int n){
    int *vet, i;
    vet = (int *) calloc(n, sizeof(int));

    for (i = 0; i < n; i++){
        vet[i] = (int) i;
    }
    return vet;
}

void showArray(int *vet, int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }
}

void freeMemory(int * vet){
    free(vet);
}

void main(){
    int *vet = createArray(10);
    showArray(vet, 10);
    freeMemory(vet);
}