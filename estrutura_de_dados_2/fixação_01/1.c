#include <stdio.h>
#include <string.h>
#include <math.h>
#define TAM 5

void misterio1(char b[TAM], float *dec, int p, int i)
{
    if (p < strlen(b))
    {
        if (b[p] == '1')
            *dec = *dec + pow(2, i);
        misterio1(b, dec, ++p, --i);
    }
}
/*Rastreio: Considere: b = '101', dec = 0, p=0 e i=2;
Ao chamar a funcão, entro no primeiro if, pois 0<3.
Entro também no segundo if, pois b[0] = '1', logo, dec = 0+2² = 4.
Saio do if, e chamo a função novamente, ficando sem pendencia.
Ao chamar a funcão, tenho os seguintes valores armazenados nas
minhas váriaveis: b = '101', dec = 4, p=1 e i=1
entro no primeiro if, pois 1<3.
Mas não entro no segundo if, pois b[1] != '1'.
Saio do if, e chamo a função novamente, ficando sem pendencia.
Ao chamar a funcão, tenho os seguintes valores armazenados nas
minhas váriaveis: b = '101', dec = 4, p=2 e i=0
entro no primeiro if, pois 2<3.
Entro também no segundo if, pois b[2] = '1', logo, dec = 4+1 = 5.
Saio do if, e chamo a função novamente, ficando sem pendencia.
Ao chamar a funcão, tenho os seguintes valores armazenados nas
minhas váriaveis: b = '101', dec = 5, p=3 e i=-1
Não entro no primeiro if, pois 3<3 é falso, logo cheguei ao fim da função.
E o valor de dec é 5.
*/

float misterio2(char b[TAM], float dec, int p, int i)
{

    if (p < strlen(b))
    {
        dec = misterio2(b, dec, p + 1, i - 1);
        printf("i: %d\n", i);
        printf("p: %d\n", p);
        printf("dec %f\n", dec);
        if (b[p] == '1')
            dec = dec + pow(2, i);
            printf("dec %f\n", dec);
    }
    return (dec);
}

/*Rastreio: Considere: b = '101', dec = 0, p=0 e i=2;
Ao entrar na funcão, entro no primeiro if, pois 0<3.
Chamo a função novamente, ficando com pendências, chamarei
de pendencia A,onde os valores são: b = '101', dec = 0, p=0 e i=2;
Ao chamar a funcão, tenho os seguintes valores armazenados nas
minhas váriaveis: b = '101', dec = 0, p=1 e i=1. Entro no if, pois 1<3 e 
Chamo a função novamente, ficando com pendências. chamarei
de pendencia B,onde os valores são: b = '101', dec = 0, p=1 e i=1;
Ao chamar a funcão, tenho os seguintes valores armazenados nas
minhas váriaveis: b = '101', dec = 0, p=2 e i=0. Entro no if, pois 2<3 e 
Chamo a função novamente, ficando com pendências. chamarei
de pendencia C,onde os valores são:  b = '101', dec = 0, p=2 e i=0;
Ao chamar a funcão, tenho os seguintes valores armazenados nas
minhas váriaveis: b = '101', dec = 0, p=3 e i=-1. Não entro no if, pois 3<3 é falso, então retorno 0
para a pendencia C.

Pendencia C: 
Dados: b = '101', dec = 0, p=2 e i=0;
Recebo 0 para o valor de dec. Entro no if, pois b[2] = '1', então dec = 0 + 1 = 1.
Saio do if e chego ao fim da função retornando 1 para pendencia B.

Pendencia B:
Dados: b = '101', dec = 0, p=1 e i=1;
Recebo 1 para o valor de dec. Não entro no if, pois b[1] != '1'.
Chego ao fim da função retornando 1 para pendencia A.

Pendencia A: 
Dados: b = '101', dec = 0, p=0 e i=2;
Recebo 1 para o valor de dec. Entro no if, pois b[3] = '1', então dec = 1 + 2² = 5.
Saio do if e chego ao fim da função retornando 5.

*/

void main()
{
    float dec = 0;
    int i, p = 0;
    char b[TAM];
    b[0] = '1';
    b[1] = '0';
    b[2] = '0';
    b[3] = '1';
    b[4] = '0';
    i = strlen(b) - 1;
    printf("%d\n", i);

    dec = misterio2(b, dec, p, i);

    printf("%f", dec);
}

/*
Os dois códigos recebem uma string que corresponde a um valor
binário e obtem esse valor em décimal.
A diferença dos dois códigos é que o primeiro faz o retorno
através de ponteiro e o segundo retorna na própria função um inteiro.
*/



