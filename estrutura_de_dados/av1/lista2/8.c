#include <stdio.h>

void inverte(int n, int *vet)
{
    int i = 0, aux, fim = n - 1;
    for (i = 0; i < n / 2; i++)
    {
        aux = vet[i];
        vet[i] = vet[fim];
        vet[fim] = aux;
        fim --;
    }
}
void main()
{
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0, n = 10;

    inverte(n, vet);

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", vet[i]);
    }
}