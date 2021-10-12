#include <stdio.h>
#include <math.h>

void teste_parametros(int n, float *maior, float *menor, float *varianca, float *media)
{
    int i = 0;
    float soma = 0, vet[n];
    scanf("%f", &vet[0]);

    *menor = vet[0];
    *maior = vet[0];
    soma += vet[0];
    for ( i = 1; i < n; i++)
    {
        printf("Interacao %d: ", i);
        scanf("%f", &vet[i]);
        soma += vet[i];

        if (*maior < vet[i])
            *maior = vet[i];
        else if (*menor > vet[i])
            *menor = vet[i];
    }
    *media = soma / n;
    soma = 0;

    for ( i = 0; i < n; i++)
    {
        soma += (vet[i] - (*media)) * (vet[i] - (*media));
    }

    *varianca = soma / n;
}
void main()
{

    int n;
    float maior, menor, varianca, media;
    printf("Informe a quantidade de termos: ");
    scanf("%d", &n);

    teste_parametros(n, &maior, &menor, &varianca, &media);

    printf("Maior = %.2f\nMenor = %.2f\nVarianca = %.2f\nMedia = %.2f\n", maior, menor, varianca, media);
}
