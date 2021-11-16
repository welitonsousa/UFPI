#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000
#define TESTES 30
struct arvore
{
    struct arvore *esquerda;
    int info;
    struct arvore *direita;
    int altura;
};
typedef struct arvore Arvore;

/*preenche vetor de tamanho TAM com números sequenciais de 0 a TAM-1*/
void preencherVetor(int vetor[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        vetor[i] = i;
    }
}

/*embaralha os elementos entre as posições do vetor*/
void embaralharVetor(int vetor[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        int aux = vetor[i];
        int aleatorio = rand() % TAM;
        vetor[i] = vetor[aleatorio];
        vetor[aleatorio] = aux;
    }
}

/*verica se no é folha, se sim, retorna 1, se não, retorna 0*/
int ehFolha(Arvore *no)
{
    int folha = 0;
    if (no != NULL)
    {
        if (no->direita == NULL && no->esquerda == NULL)
            folha = 1;
    }
    return folha;
}

/*calcula a profundidade de nó na arvore raiz e retorna*/
int profundidade(Arvore *Raiz, Arvore *No)
{
    int profNo = -1;
    if (Raiz != NULL)
    {
        if ((*No).info < (*Raiz).info)
            profNo = profundidade((*Raiz).esquerda, No) + 1;
        else if ((*No).info > (*Raiz).info)
            profNo = profundidade((*Raiz).direita, No) + 1;
        else
            profNo = 0;
    }
    return profNo;
}

/*calcula o nível da folha de maior profundidade e retorna
Raiz e No devem receber inicialmente a raiz da arvore*/
int profundidadeMaior(Arvore *Raiz, Arvore *No)
{
    int profRaiz, maiorEsquerda = 0, maiorDireita = 0, maiorProf = -1;

    if (No != NULL)
    {
        if (ehFolha(No))
        {
            profRaiz = profundidade(Raiz, No);
            if (profRaiz > maiorProf)
                maiorProf = profRaiz;
        }
        else
        {
            maiorEsquerda = profundidadeMaior(Raiz, No->esquerda);
            maiorDireita = profundidadeMaior(Raiz, No->direita);
            if (maiorEsquerda > maiorDireita)
                maiorProf = maiorEsquerda;
            else
                maiorProf = maiorDireita;
        }
    }
    return maiorProf;
}

/*calcula o nível da folha de menor profundidade e retorna
Raiz e No devem receber inicialmente a raiz da arvore*/
int profundidadeMenor(Arvore *Raiz, Arvore *No)
{
    int profRaiz, menoresquerda = 0, menordireita = 0, menorProf = 10000;

    if (No != NULL)
    {
        if (ehFolha(No))
        {
            profRaiz = profundidade(Raiz, No);
            if (profRaiz < menorProf)
                menorProf = profRaiz;
        }
        else
        {
            menoresquerda = profundidadeMenor(Raiz, No->esquerda);
            menordireita = profundidadeMenor(Raiz, No->direita);
            if (menoresquerda < menordireita)
                menorProf = menoresquerda;
            else
                menorProf = menordireita;
        }
    }
    return menorProf;
}

/*recebe o clock de inicio e o de fim e retorna
a quantidade de clocks por milisegundos*/
double calcularTempo(clock_t inicio, clock_t fim)
{
    double tempo = ((double)(fim - inicio) * 1000 / CLOCKS_PER_SEC);
    return tempo;
}

/*busca na arvore o no com info='elemento', se encontra retorna o no,
se não, retorna NULL*/
Arvore *buscar(Arvore *raiz, int elemento)
{
    Arvore *no;
    if (raiz != NULL)
    {
        if (elemento == raiz->info)
        {
            no = raiz;
        }
        else
        {
            if (elemento < raiz->info)
                no = buscar(raiz->esquerda, elemento);
            else
                no = buscar(raiz->direita, elemento);
        }
    }
    else
    {
        no = NULL;
    }
    return no;
}

/*Preenche o vetor com a diferença entre a profundidade máxima e mínima
A primeira dimensão armazena a diferença das profundidadas
A segunda dimensão armazena a quantidade de vezes que tal diferença aparece
diferença é a nova dimensão que será adicionado no vetor
quanTtermos é um ponteiro com a quantidade de elementos que o vetor possui
*/
void inserirDiferencaProfundidade(int vetor[2][TESTES], int diferenca, int *quantTermos)
{
    for (int i = 0; i < *quantTermos && diferenca != -1; i++)
    {
        if (vetor[0][i] == diferenca)
        {
            vetor[1][i]++;
            diferenca = -1;
        }
    }
    if (diferenca != -1)
    {
        vetor[0][*quantTermos] = diferenca;
        vetor[1][*quantTermos] = 1;
        (*quantTermos)++;
    }
}

Arvore *girarHorario(Arvore *raiz)
{
    Arvore *no = raiz->esquerda;
    raiz->esquerda = no->direita;
    no->direita = raiz;
    return no;
}

Arvore *girarAntiHorario(Arvore *raiz)
{
    Arvore *no = raiz->direita;
    raiz->direita = no->esquerda;
    no->esquerda = raiz;
    return no;
}

/*calcula o fator de balanceamento do nó raiz e retorna*/
int fatorBalanceamento(Arvore *raiz)
{
    int fator = 0, esq, dir;
    if (raiz->esquerda == NULL)
        esq = -1;
    else
        esq = raiz->esquerda->altura;
    if (raiz->direita == NULL)
        dir = -1;
    else
        dir = raiz->direita->altura;
    fator = esq - dir;
    return fator;
}

/*calcula a altura do nó raiz e retorna*/
int alturaElemento(Arvore *raiz)
{
    int altura = 1;
    int esquerda = -1;
    int direita = -1;

    if (raiz->esquerda != NULL)
        esquerda = raiz->esquerda->altura;
    if (raiz->direita != NULL)
        direita = raiz->direita->altura;
    altura = 1;
    if (esquerda > direita)
        altura += esquerda;
    else
        altura += direita;

    return altura;
}

/*calcula a altura da raiz e de seus descendentes e armazena em raiz->altura*/
int calcularAlturaCadaElementoGalho(Arvore *raiz)
{
    int altura = 0;
    if (raiz == NULL)
    {
        altura = -1;
    }
    else
    {
        altura = 1;
        int direita = calcularAlturaCadaElementoGalho(raiz->direita);
        int esquerda = calcularAlturaCadaElementoGalho(raiz->esquerda);
        if (esquerda > direita)
            altura += esquerda;
        else
            altura += direita;
        raiz->altura = altura;
    }
    return altura;
}

/*balanceia raiz*/
Arvore *balancear(Arvore *raiz)
{
    if (fatorBalanceamento(raiz) > 0) //positivo
    {
        if (fatorBalanceamento(raiz->esquerda) < 0) //negativo
        {
            raiz->esquerda = girarAntiHorario(raiz->esquerda);
        }
        raiz = girarHorario(raiz);
    }
    else if (fatorBalanceamento(raiz) < 0) //negativo
    {

        if (fatorBalanceamento(raiz->direita) > 0) //positivo
        {
            raiz->direita = girarHorario(raiz->direita);
        }
        raiz = girarAntiHorario(raiz);
    }

    return raiz;
}

/*Insire nó na arvore e balanceia*/
void inserirNo(Arvore **raiz, Arvore *no)
{
    if (*raiz == NULL)
    {
        *raiz = no;
    }
    else
    {
        if (no->info < (*raiz)->info)
        {
            inserirNo(&((*raiz)->esquerda), no);
        }
        else if (no->info > (*raiz)->info)
        {
            inserirNo(&((*raiz)->direita), no);
        }
        (*raiz)->altura = alturaElemento(*raiz);
        if (abs(fatorBalanceamento(*raiz)) > 1)
        {
            *raiz = balancear(*raiz);
            calcularAlturaCadaElementoGalho(*raiz);
        }
    }
}

/*cria no com info n e retorna no*/
Arvore *criarNo(int n)
{
    Arvore *no = (Arvore *)calloc(1, sizeof(Arvore));
    no->info = n;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;
    return no;
}

/*libera a arvore da memória*/
void liberarArvore(Arvore *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

/*insire os elementos do vetor na arvore*/
void inserirElementosArvore(Arvore **raiz, int vetor[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        Arvore *no = criarNo(vetor[i]);
        inserirNo(raiz, no);
    }
}

void main()
{

    int vetor[TAM];
    preencherVetor(vetor);
    Arvore *raiz = NULL;
    int diferencasProfundidade[2][TESTES];
    int quantTermos = 0;
    clock_t inicio, fim;
    double tempo, somaInsercao = 0, somaBusca = 0;
    srand(time(NULL));
    for (int i = 0; i <= TESTES; i++)
    {
        raiz = NULL;
        printf("\nTeste %d:\n", i);
        if (i != 0)
        {
            embaralharVetor(vetor);
            embaralharVetor(vetor);
        }
        inicio = clock();
        inserirElementosArvore(&raiz, vetor);
        fim = clock();
        tempo = calcularTempo(inicio, fim);
        printf("Inserção tempo: %lf\n", tempo);
        if (i != 0)
            somaInsercao += tempo;
        int maiorProfundidade = profundidadeMaior(raiz, raiz);
        printf("Maior profundidade: %d\n", maiorProfundidade);
        int menorProfundidade = profundidadeMenor(raiz, raiz);
        printf("Menor profundidade: %d\n", menorProfundidade);
        int diferenca = maiorProfundidade - menorProfundidade;
        if (i != 0)
            inserirDiferencaProfundidade(diferencasProfundidade, diferenca, &quantTermos);
        inicio = clock();
        for (int j = 0; j < TAM; j++)
            buscar(raiz, j);
        fim = clock();
        tempo = calcularTempo(inicio, fim);
        printf("Busca tempo: %lf\n", tempo);
        if (i != 0)
            somaBusca += tempo;
        liberarArvore(raiz);
    }

    printf("\nDiferencas de profundidade:\n");
    for (int i = 0; i < quantTermos; i++)
    {
        printf("%d (%d vez(es))\n", diferencasProfundidade[0][i], diferencasProfundidade[1][i]);
    }

    printf("media do tempo de insercao: %lf\n", somaInsercao / TESTES);
    printf("media do tempo de busca: %lf\n", somaBusca / TESTES);
}
