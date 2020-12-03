#include <stdio.h>

void somaValores(int * soma, int a, int b)
{
    *soma = a + b;
}

void main()
{
    int a, b, soma;
    printf("Informe dois valores: ");
    scanf("%d %d", &a, &b);
    somaValores(&soma, a, b);
    printf("SOMA: %ld",soma);
}