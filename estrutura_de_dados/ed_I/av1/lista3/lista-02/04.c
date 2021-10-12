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

void showArray(int *vet, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("%d ", vet[i]);
    }
}

void freeMemory(int * vet){
    free(vet);
}

int *joinArray(int *vet1, int *vet2, int sizeVet1, int sizeVet2){
    int *vet = (int *) calloc(sizeVet1 + sizeVet2, sizeof(int));
    int i;
    for(i = 0; i< sizeVet1; i++)
        vet[i] = vet1[i];
    for(i = 0; i< sizeVet2; i++)
        vet[i + sizeVet1] = vet2[i];

    return vet;
}

void main(){
    int *vet = createArray(10);
    int *vet2 = createArray(20);
    int *vet3 = joinArray(vet, vet2, 10, 20);
    showArray(vet3, 30);
    
    freeMemory(vet);
    freeMemory(vet2);
    freeMemory(vet3);
}