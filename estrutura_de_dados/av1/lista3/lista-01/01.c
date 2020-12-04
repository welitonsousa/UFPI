/*
Faça um programa que leia um valor n e crie dinamicamente um vetor de n
elementos e passe esse vetor para uma função que vai ler os elementos desse vetor.
Depois, no programa principal, o vetor preenchido deve ser impresso. Além disso,
antes de finalizar o programa, deve-se liberar a área de memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

void fillArray(char *vet, int size);

void main()
{
    int sizeVet = 0;
    char *vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sizeVet);

    vet = (char *)calloc(sizeVet, sizeof(char));

    fillArray(vet, sizeVet);
    printf("%s", vet);
    free(vet);
}

void preencherVetor(char *vet, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        vet[i] = i + '0';
    }
}