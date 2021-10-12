#include <stdio.h>
#include <math.h>

float harmonica(int n, float *v)
{
    int i = 0;
    float result = 0;
    for (i = 3; i < n; i++)
    {
        result += 1 / v[i];
    }
    return 1 / result;
}

float geometrica(int n, float *v)
{
    int i = 0;
    float result = 1;
    for (i = 3; i < n; i++)
    {
        result *= v[i];
    }
    return pow(result, 1.0 / n);
}

float ponderada(int n, float *v, float *w)
{
    int i = 0;
    float result = 0, soma = 0;

    for (i = 0; i < n; i++)
    {
        soma += w[i];
        result += v[i] * w[i];
    }
    result /= soma;
    return result;
}
void main()
{
    float notas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, pesos[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float mediaHarmonica, mediaPonderada, mediaGeometrica;
    int n = 10;

    mediaHarmonica = harmonica(n, notas);
    mediaGeometrica = geometrica(n, notas);
    mediaPonderada = ponderada(n, notas, pesos);
    printf("Media hamonica: %f\n", mediaHarmonica);
    printf("Media ponderada: %f\n", mediaPonderada);
    printf("Media geometrica: %f\n", mediaGeometrica);
}