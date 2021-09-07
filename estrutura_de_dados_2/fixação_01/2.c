#include <stdio.h>
#define MAX 20

/*
Essa função retorna os divisores de um número n, armazenando-os em um vetor vet.
quantDivisores é um ponteiro que armazena o tamanho do vetor, inicialmente é 0.
O paramêtro i corresponde a possíveis divisores que n poderá ter. Deverá receber 1 ao chamar a função.
No decorrer da função, ele assumirá os valores de 1 até n.
*/

void divisores(int n, int vet[MAX],  int *quantDivisores, int i){
    if(i<= n){
        if(n % i == 0){
            vet[*quantDivisores] = i;
            (*quantDivisores) ++;
        }
        divisores(n, vet, quantDivisores,++i);
    }
}

void main(){
    int vet[MAX], qntDivisores =0;

    divisores(20, vet, &qntDivisores, 1);

    for(int i=0; i<qntDivisores; i++){
        printf("%d, ", vet[i]);
    }
}