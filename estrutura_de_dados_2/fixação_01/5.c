#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define ANOATUAL 2021

struct Pessoa
{
    int id;
    char nome[MAX];
    int anoNascimento;
    int altura;
};

struct Lista
{
    struct Pessoa info;
    struct Lista *prox;
};


/*
Essa função recebe as informações de uma pessoa e retorna uma string com esses valores.
*/
struct Pessoa criarPessoa(int id, char nome[MAX], int anoNascimento, int altura)
{
    struct Pessoa pessoa;
    pessoa.id = id;
    strcpy(pessoa.nome, nome);
    pessoa.anoNascimento = anoNascimento;
    pessoa.altura = altura;
    return pessoa;
}

/*
Essa função adiciona 'pessoa' na lista 'lista'.
O parametro quant representa a quantidade de pessoas na lista
*/
void adicionarPessoa(struct Lista *lista, struct Pessoa pessoa, int *quant)
{
    struct Lista *aux = lista;
    if (*quant == 0)
    {
        lista->info = pessoa;
        lista->prox = NULL;
        (*quant)++;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = (struct Lista *)calloc(1, sizeof(struct Lista));
        aux->prox->info = pessoa;
        aux->prox->prox = NULL;
        (*quant)++;
    }
}

/*
Essa função recebe uma struct Pessoa e imprime todas as suas informações;
*/
void imprimirPessoa(struct Pessoa pessoa)
{
    printf("\n%d\n", pessoa.id);
    printf("%s\n", pessoa.nome);
    printf("%d\n", pessoa.anoNascimento);
    printf("%d\n", pessoa.altura);
}

/*
Essa função imprimi uma lista de pessoas;
O parametro quant representa a quantidade de pessoas na lista
*/
void imprimirListaPessoas(struct Lista *lista, int quant)
{
    struct Lista *aux = lista;
    if (quant == 0)
    {
        printf("lista vazia");
    }
    else
    {
        for (; aux != NULL; aux = aux->prox)
            imprimirPessoa(aux->info);
    }
}

/*
Essa função preenche a lista de strings 'maisVelhos' com as pessoas mais velhas da lista 'aux'.
O parametro quantMaisVelhos representa a quantidade de pessoas na lista 'maisVelhos'
A função retorna o ano de nascimento da pessoa mais velha.
Na chamada da função, anoMaisvelho deve receber um ano de nascimento de uma pessoa qualquer da lista, e quantMaisVelhos deve receber 0.
*/
int obterMaisVelhos(struct Lista *aux, int anoMaisVelho, char maisVelhos[MAX][MAX], int *quantMaisVelhos)
{
    if (aux != NULL)
    {
        if (aux->info.anoNascimento < anoMaisVelho)
        {
            anoMaisVelho = aux->info.anoNascimento;
        }

        anoMaisVelho = obterMaisVelhos(aux->prox, anoMaisVelho, maisVelhos, quantMaisVelhos);
        if (aux->info.anoNascimento == anoMaisVelho)
        {
            strcpy(maisVelhos[*quantMaisVelhos], aux->info.nome);
            (*quantMaisVelhos)++;
        }
    }
    return anoMaisVelho;
}

/*
A função recebe uma lista de pessoas e retorna através de ponteiro a menor e a maior altura encontrada nessa lista.
Na chamada da função, menorAltura e maiorAltura devem receber a altura de uma pessoa qualquer da lista.
*/
void menorMaiorAltura(struct Lista *aux, int *menorAltura, int *maiorAltura)
{
    if (aux != NULL)
    {
        if (aux->info.altura < *menorAltura)
        {
            *menorAltura = aux->info.altura;
        }
        if (aux->info.altura > *maiorAltura)
        {
            *maiorAltura = aux->info.altura;
        }
        menorMaiorAltura(aux->prox, menorAltura, maiorAltura);
    }
}

/*
A função recebe uma lista de pessoas e retorna a quantidade de pessoas que possui altura igual a mediana.
Na chamada da função, mediana deve receber a mediana das alturas da lista.
*/
int quantAlturaMediana(struct Lista *aux, float mediana)
{
    int quant = 0;
    if (aux != NULL)
    {
        quant = quantAlturaMediana(aux->prox, mediana);
        if (aux->info.altura == mediana)
        {
            quant++;
        }
    }
    return quant;
}

/*
A função recebe uma lista de pessoas e retorna a quantidade de pessoas que possui altura maior que a mediana e idade menor que 40.
Na chamada da função, mediana deve receber a mediana das alturas da lista.
*/
int quantIdadeMenor40AlturaMaiorMediana(struct Lista *aux, float mediana)
{
    int quant = 0;
    if (aux != NULL)
    {
        quant = quantIdadeMenor40AlturaMaiorMediana(aux->prox, mediana);
        if (aux->info.altura > mediana && ANOATUAL - aux->info.anoNascimento < 40)
            
        {
            quant++;
        }
    }
    return quant;
}

void main()
{
    int quant = 0;
    struct Lista *lista = (struct Lista *)calloc(1, sizeof(struct Lista));
    char maisVelhos[MAX][MAX];
    struct Pessoa p2 = criarPessoa(2, "Weliton", 1997, 185);
    struct Pessoa p1 = criarPessoa(1, "Darice", 1999, 164);
    struct Pessoa p3 = criarPessoa(3, "Daise", 1997, 174);
    adicionarPessoa(lista, p1, &quant);
    adicionarPessoa(lista, p2, &quant);
    adicionarPessoa(lista, p3, &quant);

    imprimirListaPessoas(lista, quant);

    printf("\n");
    if (quant > 0)
    {

        struct Lista *aux = lista;
        int quantMaisVelhos = 0;
        obterMaisVelhos(aux, aux->info.anoNascimento, maisVelhos, &quantMaisVelhos);
        printf("Mais velho(s):\n");
        for (int i = 0; i < quantMaisVelhos; i++)
        {
            printf("%s\n", maisVelhos[i]);
        }

        printf("\n");

        aux = lista;
        int menorAltura = lista->info.altura;
        int maiorAltura = lista->info.altura;
        menorMaiorAltura(aux, &menorAltura, &maiorAltura);
        printf("Menor altura: %d\n", menorAltura);
        printf("Maior altura: %d\n", maiorAltura);

        printf("\n");

        aux = lista;
        float mediana = (menorAltura + maiorAltura) / 2;
        printf("mediana: %f\n", mediana);
        printf("Quantidade de pessoas com altura mediana: %d\n", quantAlturaMediana(aux, mediana));

        printf("\n");

        aux = lista;
        printf("Quantidade de pessoas com altura maior que a mediana e idade abaixo de 40: %d\n",quantIdadeMenor40AlturaMaiorMediana(aux, mediana));
    }
}