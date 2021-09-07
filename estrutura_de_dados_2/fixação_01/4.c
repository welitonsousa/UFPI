#include <stdio.h>
#define TAM 3


/*
Essa função recursiva sem pendencia recebe como parâmetro uma lista de números e calcula seu mmc, retornando esse valor.
O parâmetro 'posicao' assumirá todas as posições na lista números. Deverá receber 0 ao chamar a função.
O parâmetro 'mmc' deverá receber 2 na chamada da função. Assumirá possíveis valores para o MMC,
sempre que ao tentar dividir 'mmc' por um número da lista e não obter resto 0, a função será chamada de novo
com o valor de mmc sendo mmc+1.
*/

int calcularMMC1(int numeros[TAM], int mmc, int posicao)
{
    if (posicao < TAM)
    {
        if (mmc % numeros[posicao] == 0)
        {
            calcularMMC1(numeros, mmc, posicao + 1);
        }
        else
        {
            calcularMMC1(numeros, mmc + 1, 0);
        }
    }
    else
    {
        return mmc;
    }
}



/*
Essa função recursiva com pendencia recebe como parâmetro uma lista de números e calcula seu mmc, retornando esse valor.
O parâmetro 'posicao' assumirá todas as posições na lista números. Deverá receber 0 ao chamar a função.
O parâmetro 'mmc' deverá receber 2 na chamada da função. Assumirá possíveis valores para o MMC,
sempre que ao tentar dividir 'mmc' por um número da lista e não obter resto 0, a função será chamada de novo
com o valor de mmc sendo mmc+1.
*/
int calcularMMC2(int numeros[TAM], int mmc, int posicao)
{
    if (posicao < TAM)
    {
        if (mmc % numeros[posicao] == 0)
        {
            mmc = calcularMMC2(numeros, mmc, posicao + 1);
        }
        else
        {
            mmc = calcularMMC2(numeros, mmc + 1, 0);
        }

    }
    return mmc;
}

void main()
{
    int numeros[TAM];
    printf("Digite %d números:\n", TAM);
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }
    int mmc = calcularMMC1(numeros, 2, 0);
    printf("\nMMC sem pendência: %d\n", mmc);
    mmc = calcularMMC2(numeros, 2, 0);
    printf("\nMMC com pendência: %d\n", mmc);
}