#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXCARACTER 20
#define QUANTPALAVRAS 3


/*
Essa função recebe como parâmetro uma string e a lê
*/
void lerPalavra(char palavra[MAXCARACTER])
{
    scanf("%s", palavra);
}

/*
Essa função recebe como parâmetro um vetor de strings e para cada string chama a função ler Palavra.
*/
void criarPalavras(char palavras[QUANTPALAVRAS][MAXCARACTER])
{
    for (int i = 0; i < QUANTPALAVRAS; i++)
        lerPalavra(palavras[i]);
}

/*
Essa função recebe como parâmetro um vetor de strings e imprimir cada string.
*/
void imprimirPalavras(char palavras[QUANTPALAVRAS][MAXCARACTER])
{
    for (int i = 0; i < QUANTPALAVRAS; i++)
        printf("%s\n", palavras[i]);
}

/*
Essa função retorna o número de caracteres da maior palavra que contém na lista de strings 'palavras', armazenando a maior palavra
na string 'maiorPalavra'.
O parâmetro i assumirá todas as posições na lista 'palavras'. Deverá receber 0 ao chamar a função.
*/
int maiorPalavraFunc(char palavras[QUANTPALAVRAS][MAXCARACTER], int i, char maiorPalavra[MAXCARACTER])
{
    int maior = 0;
    if (i < QUANTPALAVRAS)
    {
        maior = maiorPalavraFunc(palavras, i + 1, maiorPalavra);
        if (strlen(palavras[i]) > maior)
        {
            maior = strlen(palavras[i]);
            strcpy(maiorPalavra, palavras[i]);
        }
    }
    return maior;
}

/*
Essa função armazena na lista de strings 'novoVetor' todas as strings da lista de strings 'palavras'
que iniciam com letra maiscula e possue 4 ou mais caracteres.
O parâmetro i assumirá todas as posições na lista 'palavras'. Deverá receber 0 ao chamar a função.
O parâmetro 'quantNovoVetor' corresponde a quantidade de strings presentes em 'novoVetor';
*/
void maisculaMaiorIgual4(char palavras[QUANTPALAVRAS][MAXCARACTER], int i, char novoVetor[QUANTPALAVRAS][MAXCARACTER], int *quantNovoVetor)
{
    if (i < QUANTPALAVRAS)
    {
        if (strlen(palavras[i]) >= 4 && isupper(palavras[i][0]) != 0)
        {
            strcpy(novoVetor[*quantNovoVetor], palavras[i]);
            (*quantNovoVetor)++;
        }
        maisculaMaiorIgual4(palavras, i+1, novoVetor, quantNovoVetor);
    }
}


/*
Nessa função, o ponteiro 'quantidade' aponta para a quantidade de strings da lista de strings 'palavras' que iniciam com vogal.
Deve receber o endereço de memória de uma variável contendo 0.
O parâmetro i assumirá todas as posições na lista 'palavras'. Deverá receber 0 ao chamar a função.
*/
void quantIniciaVogal(char palavras[QUANTPALAVRAS][MAXCARACTER], int i, int *quantidade)
{
    if (i < QUANTPALAVRAS)
    {
        char inicio = palavras[i][0];
        if (inicio == 'a' || inicio == 'e' || inicio == 'i' || inicio == '0' || inicio == 'u')
            (*quantidade)++;
        quantIniciaVogal(palavras, ++i, quantidade);
    }
}

void main()
{
    char palavras[QUANTPALAVRAS][MAXCARACTER];
    char novoVetor[QUANTPALAVRAS][MAXCARACTER];
    char maiorPalavra[MAXCARACTER];
    printf("Digite %d palavras:\n", QUANTPALAVRAS);
    criarPalavras(palavras);
    // imprimirPalavras(palavras);

    maiorPalavraFunc(palavras, 0, maiorPalavra);
    printf("\nmaior palavra: %s\n", maiorPalavra);

    int quantidade = 0;
    quantIniciaVogal(palavras, 0, &quantidade);
    printf("\nQuantidade de palavras iniciada com vogal: %d\n", quantidade);
    quantidade = 0;

    printf("\nPalavras que iniciam com letra maiúscula e que possuem tamanho maior ou igual a 4:");
    maisculaMaiorIgual4(palavras, 0, novoVetor, &quantidade);
    for (int i = 0; i < quantidade; i++)
    {
        printf("\n%s", novoVetor[i]);
    }
}
