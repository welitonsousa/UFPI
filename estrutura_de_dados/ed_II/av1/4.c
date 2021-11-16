#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct lista
{
    char palavra[MAX];
    struct lista *prox;
};
typedef struct lista Lista;

struct arvore
{
    int altura;
    char portugues[MAX];
    struct lista *ingles;
    struct arvore *esquerda;
    struct arvore *direita;
};
typedef struct arvore Arvore;

struct unidade
{
    int id;
    char nome[MAX];
    struct arvore *raiz;
    struct unidade *prox;
};
typedef struct unidade Unidade;

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

/*calculo o fator de balanceamento do nó*/
int fatorBalanceamento(Arvore *no)
{
    int fator = 0, esq, dir;
    if (no->esquerda == NULL)
        esq = -1;
    else
        esq = no->esquerda->altura;
    if (no->direita == NULL)
        dir = -1;
    else
        dir = no->direita->altura;
    fator = esq - dir;
    return fator;
}

//Calculo a altura do elemento raiz (com base na altura dos seus filhos) e retorno ela.
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

/*calcula a altura da raiz e de seus descendentes e para cada um armazena em raiz->altura*/
int calcularAlturaCadaElementoGalho(Arvore *raiz)
{
    int altura = -1;
    int direita = 0;
    int esquerda = 0;
    if (raiz != NULL)
    {
        altura = 1;

        direita += calcularAlturaCadaElementoGalho(raiz->direita);
        esquerda += calcularAlturaCadaElementoGalho(raiz->esquerda);
        if (esquerda > direita)
        {
            altura += esquerda;
            raiz->altura = altura;
        }
        else
        {
            altura += direita;
            raiz->altura = altura;
        }
    }
    return altura;
}

/*balanceio a raiz*/
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

/*cria unidade e retorna.
Recebe a string nome que será armazenada em unidade->nome
e o id que será armazenado em unidade->id */
Unidade *criarUnidade(char nome[MAX], int id)
{
    Unidade *unidade = (Unidade *)calloc(1, sizeof(Unidade));
    strcpy(unidade->nome, nome);
    unidade->id = id;
    unidade->prox = NULL;
    unidade->raiz = NULL;
    return unidade;
}

/*Insire o nó unidade na lista dicionario*/
void inserirUnidadeNoDicionario(Unidade **dicionario, Unidade *unidade)
{
    if (*dicionario == NULL)
    {
        *dicionario = unidade;
    }
    else
    {
        Unidade *aux = *dicionario;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = unidade;
    }
}

/*cria uma arvore, tal qual arvore->portugues recebe a string 'portugues'.
Retorna a arvore*/
Arvore *criarArvore(char portugues[MAX])
{
    Arvore *arvore = (Arvore *)calloc(1, sizeof(Arvore));
    arvore->direita = NULL;
    arvore->esquerda = NULL;
    arvore->ingles = NULL;
    arvore->altura = 0;
    strcpy(arvore->portugues, portugues);
    return arvore;
}

/*compara a palavra1 e a palavra 2 para averiguar qual vem primeiro em ordem alfabetica.
retorna 1 se a palavra que vem primeiro for palavra1
retorna 2 se a palavra que vem primeiro for palavra2
retorna 0 se as duas palavras possuem os mesmos caracteres
A variavel i indica a posição do caracter a ser comparado. Deve receber 0 na chamada da função*/
int compararPalavras(char palavra1[MAX], char palavra2[MAX], int i)
{
    int palavraQueVemPrimeiro = 0;
    if (strlen(palavra1) > i && strlen(palavra2) > i)
    {
        if (tolower(palavra1[i]) == tolower(palavra2[i]))
        {
            palavraQueVemPrimeiro = compararPalavras(palavra1, palavra2, i + 1);
        }
        else
        {
            if (tolower(palavra1[i]) < tolower(palavra2[i]))
                palavraQueVemPrimeiro = 1;
            if (tolower(palavra1[i]) > tolower(palavra2[i]))
                palavraQueVemPrimeiro = 2;
        }
    }
    return palavraQueVemPrimeiro;
}

/*Insere nó em raiz, se necessario, balanceia a raiz*/
void inserirArvoreNaRaizDaUnidade(Arvore **raiz, Arvore *arvore)
{
    if (*raiz == NULL)
    {
        *raiz = arvore;
    }
    else
    {
        int primeiro = compararPalavras(arvore->portugues, (*raiz)->portugues, 0);
        if (primeiro == 1)
            inserirArvoreNaRaizDaUnidade(&((*raiz)->esquerda), arvore);
        else
            inserirArvoreNaRaizDaUnidade(&((*raiz)->direita), arvore);
        (*raiz)->altura = alturaElemento(*raiz);
        if (abs(fatorBalanceamento(*raiz)) > 1)
        {
            *raiz = balancear(*raiz);
            calcularAlturaCadaElementoGalho(*raiz);
        }
    }
}

/*cria um nó de lista que conterá a palavra em ingles
tal qual no->palavra recebe a string 'palavra'.
Retorna o no*/
Lista *criarPalavraIngles(char palavra[MAX])
{
    Lista *lista = (Lista *)calloc(1, sizeof(Lista));
    strcpy(lista->palavra, palavra);
    lista->prox = NULL;
    return lista;
}

/*insere o nó ingles  na lista*/
void inserirPalavraIngles(Lista **lista, Lista *ingles)
{
    if (*lista == NULL)
    {
        *lista = ingles;
    }
    else
    {
        Lista *aux = *lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = ingles;
    }
}

/*busca uma unidade na lista dicionario pelo id. Retorna a unidade*/
Unidade *buscarUnidade(Unidade *dicionario, int id)
{
    Unidade *aux = dicionario;
    while (aux != NULL && aux->id != id)
    {
        if (aux->id != id)
        {
            aux = aux->prox;
        }
    }
    return aux;
}

/*Função recursiva que busca um nó na árvore raiz pela string raiz.portugues.*/
Arvore *buscarPalavraPortuguesEmArvore(Arvore *raiz, char portugues[MAX])
{
    Arvore *no = NULL;
    if (raiz != NULL)
    {
        if (strcmp(raiz->portugues, portugues) == 0)
        {
            no = raiz;
        }
        else
        {
            int primeiro = compararPalavras(portugues, raiz->portugues, 0);
            if (primeiro == 1)
                no = buscarPalavraPortuguesEmArvore(raiz->esquerda, portugues);
            else
                no = buscarPalavraPortuguesEmArvore(raiz->direita, portugues);
        }
    }
    return no;
}

/*Remove o nó. Nó é uma folha.
Retorno a nova raiz */
Arvore *removerFolha(Arvore *no)
{
    Arvore *aux = no;
    no = NULL;
    free(aux);
    return no;
}

/*Remove o nó. Nó tem um único filho.
Retorno a nova raiz*/
Arvore *removerNoUnicoFilho(Arvore *no)
{
    Arvore *filho;
    if (no->direita == NULL)
        filho = no->esquerda;
    else
        filho = no->direita;
    free(no);
    return filho;
}

/*Retorna o nó de maior descendente de raiz*/
Arvore *noMaiorElemento(Arvore *raiz)
{
    if (raiz->direita != NULL)
        noMaiorElemento(raiz->direita);
    else
        return raiz;
}

/*Retorna o maior descendente de raiz*/
Arvore *removerNoDoisfilhos(Arvore *no)
{
    Arvore *maior = noMaiorElemento(no->esquerda);
    maior->direita = no->direita;
    Arvore *aux = no;
    no = aux->esquerda;
    free(aux);
    return no;
}

/*Retorna a quantidade de filhos que nó tem*/
int quantFilhos(Arvore *no)
{
    int filhos;
    if (no->direita == NULL && no->esquerda == NULL)
        filhos = 0;
    else if (no->direita != NULL && no->esquerda != NULL)
        filhos = 2;
    else
        filhos = 1;
    return filhos;
}

/*Deleta uma arvore se raiz->protugues for igual ao conteudo da string 'portugues'.
'Encontrei' deve receber 0. Se encontrar o elemento buscado, ele recebe 1.
Retorna a nova raiz*/
Arvore *deletarPalavraPortuguesEmArvore(Arvore *raiz, char portugues[MAX], int *encontrei)
{
    if (raiz != NULL)
    {
        if (strcmp(raiz->portugues, portugues) == 0)
        {
            *encontrei = 1;
            if (quantFilhos(raiz) == 0)
                raiz = removerFolha(raiz);
            else if (quantFilhos(raiz) == 1)
                raiz = removerNoUnicoFilho(raiz);
            else
                raiz = removerNoDoisfilhos(raiz);
            calcularAlturaCadaElementoGalho(raiz);
        }
        else
        {
            int primeiro = compararPalavras(portugues, raiz->portugues, 0);
            if (primeiro == 1)
                raiz->esquerda = deletarPalavraPortuguesEmArvore(raiz->esquerda, portugues, encontrei);
            else
                raiz->direita = deletarPalavraPortuguesEmArvore(raiz->direita, portugues, encontrei);
            if (abs(fatorBalanceamento(raiz)) > 1)
            {
                raiz = balancear(raiz);
                calcularAlturaCadaElementoGalho(raiz);
            }
        }
    }
    return raiz;
}

/*Busca o conteudo da string 'portugues' em todas as unidades da lista'.
Se encontrar, retorna a arvore, tal qual arvore->portugues for igual ao conteudo da string.
Se não, retorna NULL*/
Arvore *buscarPalavraPortuguesEmDicionario(Unidade *dicionario, char portugues[MAX])
{
    Unidade *aux = dicionario;
    Arvore *no = NULL;
    while (aux != NULL && no == NULL)
    {
        no = buscarPalavraPortuguesEmArvore(aux->raiz, portugues);
        aux = aux->prox;
    }
    return no;
}

/*Imprime a lista de palavras inglês*/
void imprimirListaIngles(Lista *lista)
{
    Lista *aux = lista;
    if (aux == NULL)
        printf("lista vazia\n");
    else
    {
        printf("Ingles: ");
        while (aux != NULL)
        {
            if (aux != lista)
            {
                printf(", ");
            }
            printf("%s", aux->palavra);
            aux = aux->prox;
        }
        printf("\n");
    }
}

/*Imprime as informações de um nó da arvore.
Recebe o nó*/
void imprimirNo(Arvore *raiz)
{
    printf("\nPortugues: %s\n", raiz->portugues);
    imprimirListaIngles(raiz->ingles);
}

/*Imprime todos os nós da arvore*/
void imprimirArvorePortuguesIngles(Arvore *raiz)
{
    if (raiz != NULL)
    {
        imprimirNo(raiz);
        imprimirArvorePortuguesIngles(raiz->esquerda);
        imprimirArvorePortuguesIngles(raiz->direita);
    }
}

/*Imprime todas as informações de uma unidade.
Inclusive, todos nós da sua arvore*/
void imprimirUnidade(Unidade *unidade)
{
    printf("---UNIDADE %d:  %s\n", unidade->id, unidade->nome);
    imprimirArvorePortuguesIngles(unidade->raiz);
}

/*Imprime todas as unidades da lista dicionario*/
void imprimirDicionario(Unidade *dicionario)
{
    Unidade *aux = dicionario;
    while (aux != NULL)
    {
        printf("\n");
        imprimirUnidade(aux);
        aux = aux->prox;
    }
}

/*Imprime o nome e o id de todas as unidades na lista dicionario*/
void imprimirNomeUnidades(Unidade *dicionario)
{
    Unidade *aux = dicionario;
    while (aux != NULL)
    {
        printf("\n");
        printf("---UNIDADE %d:  %s\n", aux->id, aux->nome);
        aux = aux->prox;
    }
}

/*le um arquivo no formato proposto e armazena as informações nas structs.
Retorna 1 se não é possível ler o arquivo dicionario.txt 
Retorna 0 se não houve erro*/
int lerArquivo(Unidade **dicionario)
{
    int erro = 1;
    FILE *arquivo = fopen("dicionario.txt", "r");
    if (arquivo != NULL)
    {
        erro = 0;
        char *palavra;
        int id = 0;
        char *ingles;
        while (!feof(arquivo))
        {
            Unidade *unidade;
            char frase[MAX];
            fgets(frase, MAX, arquivo);
            if (frase[0] == '%')
            {
                id++;
                palavra = strtok(frase + 1, "\n");
                unidade = criarUnidade(palavra, id);
                inserirUnidadeNoDicionario(dicionario, unidade);
            }
            else
            {
                ingles = strtok(frase, ":");
                palavra = strtok(NULL, ",\n");
                while (palavra)
                {
                    Arvore *arvore = buscarPalavraPortuguesEmArvore(unidade->raiz, palavra);
                    if (arvore == NULL)
                    {
                        arvore = criarArvore(palavra);
                        inserirArvoreNaRaizDaUnidade(&(unidade->raiz), arvore);
                    }
                    Lista *listaIngles = criarPalavraIngles(ingles);
                    inserirPalavraIngles(&(arvore->ingles), listaIngles);
                    palavra = strtok(NULL, ",\n");
                }
            }
        }
    }
    return erro;
}

/*Pede ao usuario para digitar o id de uma unidade, e lê*/
void lerID(int *id)
{
    printf("Digite o id da unidade: ");
    scanf("%d", id);
}

/*Pede ao usuario para digitar uma palavra em português e lê*/
void lerPalavraPortugues(char palavra[MAX])
{
    printf("Digite a palavra em portugues: ");
    scanf("%s", palavra);
}

/*Menu com as opções. Retorna a opção escolhida pelo usuario*/
int menu()
{
    printf("\n***********MENU************\n");
    printf("1 - Mostrar unidades\n");
    printf("2 - Mostrar dicionario\n");
    printf("3 - Pesquisar unidade especifica\n");
    printf("4 - Pesquisar palavra portugues\n");
    printf("5 - Deletar palavra\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção:\n");
    int op;
    scanf("%d", &op);
    return op;
}

int main()
{
    Unidade *dicionario = NULL;
    int op, id, encontrei;
    Unidade *unidade;
    Arvore *arvore;
    char palavra[MAX];

    int erro = lerArquivo(&dicionario);
    if (erro)
    {
        printf("arquivo dicionario.txt não encontrado\n");
    }
    else
    {
        do
        {
            op = menu();
            switch (op)
            {
            case 1:
                imprimirNomeUnidades(dicionario);
                break;
            case 2:
                imprimirDicionario(dicionario);
                break;
            case 3:
                lerID(&id);
                unidade = buscarUnidade(dicionario, id);
                if (unidade == NULL)
                {
                    printf("unidade não encontrada\n");
                }
                else
                {
                    imprimirUnidade(unidade);
                }
                break;
            case 4:
                lerPalavraPortugues(palavra);
                arvore = buscarPalavraPortuguesEmDicionario(dicionario, palavra);
                if (arvore == NULL)
                {
                    printf("Palavra não encontrada\n");
                }
                else
                {
                    imprimirNo(arvore);
                }
                break;
            case 5:
                lerID(&id);
                unidade = buscarUnidade(dicionario, id);
                if (unidade == NULL)
                {
                    printf("unidade não encontrada\n");
                }
                else
                {
                    encontrei = 0;
                    char palavra[MAX];
                    lerPalavraPortugues(palavra);
                    unidade->raiz = deletarPalavraPortuguesEmArvore(unidade->raiz, palavra, &encontrei);
                    if (encontrei)
                    {
                        printf("Deletado!\n");
                    }
                    else
                    {
                        printf("Palavra não encontrada\n");
                    }
                    break;
                }
            }
        } while (op != 0);
    }
    return 0;
}