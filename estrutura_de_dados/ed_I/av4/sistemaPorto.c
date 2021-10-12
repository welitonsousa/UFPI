#include "sistemaPorto.h"

struct navio
{
    int capacidade;
    int perecivel;
    int corrosivo;
    Container *containers;
    Navio *proximo;
};

struct container
{
    int tamanho;
    char tipoProduto[50];
    int perecivel;
    int corrosivo;
    Container *proximo;
};

Navio *cadastrarNavio(Navio *navios)
{
    Navio *novo = (Navio *)calloc(1, sizeof(Navio));
    novo->capacidade = rand() % 101 + 25;

    printf("Suporta perecível? (0-nao, 1-sim)");
    scanf("%d", &novo->perecivel);
    printf("Suporta corrosivo? (0-não, 1-sim)");
    scanf("%d", &novo->corrosivo);

    novo->containers = NULL;
    Navio *aux = navios;

    if (aux == NULL)
    {
        novo->proximo = NULL;
        return novo;
    }

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    aux->proximo = novo;
    novo->proximo = NULL;
    return navios;
}

Container *cadastrarContainer(Container *containers)
{
    Container *novo = (Container *)calloc(1, sizeof(Container));
    do
    {
        printf("\nDigite o tamanho do container(80, 50 ou 35): ");
        scanf("%d", &novo->tamanho);
    } while (novo->tamanho != 80 && novo->tamanho != 50 && novo->tamanho != 35);

    printf("Digite o tipo do produto: ");
    scanf("%s", novo->tipoProduto);

    printf("É perecível? (0-nao, 1-sim)");
    scanf("%d", &novo->perecivel);
    if (novo->perecivel)
    {
        novo->corrosivo = 0;
    }
    else
    {
        printf("É corrosivo? (0-não, 1-sim)");
        scanf("%d", &novo->corrosivo);
    }
    novo->proximo = containers;
    return novo;
}

void imprimirContainers(Container *containers)
{
    if (containers == NULL)
    {
        printf("Nenhum container cadastrado\n");
        return;
    }
    printf("\nContainers:\n");
    Container *aux = containers;
    while (aux != NULL)
    {
        printf("\ntamanho: %d", aux->tamanho);
        printf("\ntipo: %s", aux->tipoProduto);
        printf("\nperecivel? %d", aux->perecivel);
        printf("\ncorrosivo? %d", aux->corrosivo);
        aux = aux->proximo;
    }
}

void imprimirNavios(Navio *navios)
{
    if (navios == NULL)
    {
        printf("Nenhum navio cadastrado\n");
        return;
    }
    printf("\nNavios:\n");
    Navio *aux = navios;
    while (aux != NULL)
    {
        printf("\ncapacidade: %d", aux->capacidade);
        printf("\nperecivel? %d", aux->perecivel);
        printf("\ncorrosivo? %d\n", aux->corrosivo);
        aux = aux->proximo;
    }
}

void imprimirNavio(Navio *navios)
{
    if (navios->containers != NULL)
    {
        printf("Navio carregado pronto para partir:\n");
        printf("\ncapacidade: %d", navios->capacidade);
        printf("\nperecivel? %d", navios->perecivel);
        printf("\ncorrosivo? %d\n", navios->corrosivo);

        Navio *navioAux = navios;
        printf("\nCargas:\n");
        while (navioAux->containers != NULL)
        {
            printf("\ntamanho: %d", navioAux->containers->tamanho);
            printf("\ntipo: %s", navioAux->containers->tipoProduto);
            printf("\nperecivel? %d", navioAux->containers->perecivel);
            printf("\ncorrosivo? %d\n", navioAux->containers->corrosivo);
            navioAux->containers = navioAux->containers->proximo;
        }
    }
}

Container *removerContainer(Container *container, Container *containerProximo, Container *containersLista)
{
    Container *anterior;
    if (containersLista == container)
    {
        return containerProximo;
    }
    else
    {
        Container *aux = containersLista;
        while (aux->proximo != container)
        {
            aux = aux->proximo;
        }
        anterior = aux;
        anterior->proximo = containerProximo;
        return containersLista;
    }
}

Navio *adicionarContainerNoNavio(Container *container, Navio *navio)
{
    Container *novo = container;
    novo->proximo = navio->containers;
    navio->containers = novo;
    return navio;
}

int verificaSeAlgumNavioCarregaAlgumContainer(Container *containers, Navio *navios)
{
    if (navios == NULL || containers == NULL)
    {
        return 0;
    }
    Container *containerAux = containers;
    Navio *navioAux = navios;
    while (navioAux != NULL)
    {
        if (navios->perecivel)
        {
            while (containerAux != NULL)
            {
                Container *containerProximo = containerAux->proximo;
                if (!containerAux->corrosivo && containerAux->tamanho <= navios->capacidade)
                {
                    return 1;
                }
                containerAux = containerProximo;
            }
        }
        if (navios->corrosivo)
        {
            while (containerAux != NULL)
            {
                Container *containerProximo = containerAux->proximo;
                if (!containerAux->perecivel && containerAux->tamanho <= navios->capacidade)
                {
                    return 1;
                }
                containerAux = containerProximo;
            }
        }
        else if (!navios->perecivel && !navios->corrosivo && containerAux->tamanho <= navios->capacidade)
        {
            while (containerAux != NULL)
            {
                Container *containerProximo = containerAux->proximo;
                if (!containerAux->corrosivo && !containerAux->perecivel)
                {
                    return 1;
                }
                containerAux = containerProximo;
            }
        }
        navioAux = navioAux->proximo;
    }
    return 0;
}

Container *carregarNavio(Container *containers, Navio *navios, float *pontos)
{

    Container *containerAux = containers;
    int espacoOcupadoNoNavio = 0;
    if (navios->perecivel)
    {
        while (containerAux != NULL)
        {
            Container *containerProximo = containerAux->proximo;
            if (!containerAux->corrosivo)
            {
                if (espacoOcupadoNoNavio + containerAux->tamanho > navios->capacidade)
                {
                    break;
                }
                navios = adicionarContainerNoNavio(containerAux, navios);
                espacoOcupadoNoNavio += containerAux->tamanho;
                containers = removerContainer(containerAux, containerProximo, containers);
                *pontos += 2;
            }
            else
            {
                if (containerProximo != NULL)
                {
                    if (!containerProximo->corrosivo && espacoOcupadoNoNavio + containerProximo->tamanho <= navios->capacidade)
                    {
                        printf("Foi necessário desempilhar os containers\n");
                        *pontos -= 0.05 * containerAux->tamanho;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            containerAux = containerProximo;
        }
    }
    else if (navios->corrosivo)
    {
        while (containerAux != NULL)
        {
            Container *containerProximo = containerAux->proximo;
            if (!containerAux->perecivel)
            {
                if (espacoOcupadoNoNavio + containerAux->tamanho > navios->capacidade)
                {
                    break;
                }
                navios = adicionarContainerNoNavio(containerAux, navios);
                espacoOcupadoNoNavio += containerAux->tamanho;
                containers = removerContainer(containerAux, containerProximo, containers);
                *pontos += 2;
            }
            else
            {
                if (containerProximo != NULL)
                {
                    if (!containerProximo->perecivel && espacoOcupadoNoNavio + containerProximo->tamanho <= navios->capacidade)
                    {
                        printf("Foi necessário desempilhar os containers\n");
                        *pontos -= 0.05 * containerAux->tamanho;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            containerAux = containerProximo;
        }
    }
    else if (!navios->perecivel && !navios->corrosivo)
    {
        while (containerAux != NULL)
        {
            Container *containerProximo = containerAux->proximo;
            if (!containerAux->corrosivo && !containerAux->perecivel)
            {
                if (espacoOcupadoNoNavio + containerAux->tamanho > navios->capacidade)
                {
                    break;
                }
                navios = adicionarContainerNoNavio(containerAux, navios);
                espacoOcupadoNoNavio += containerAux->tamanho;
                containers = removerContainer(containerAux, containerProximo, containers);
                *pontos += 2;
            }
            else
            {
                if (containerProximo != NULL)
                {
                    if (!containerProximo->corrosivo && !containerProximo->perecivel && espacoOcupadoNoNavio + containerProximo->tamanho <= navios->capacidade)
                    {
                        printf("Foi necessário desempilhar os containers\n");
                        *pontos -= 0.05 * containerAux->tamanho;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            containerAux = containerProximo;
        }
    }
    if (navios->containers != NULL && espacoOcupadoNoNavio != navios->capacidade)
    {
        *pontos -= 0.5;
    }

    return containers;
}

Navio *partidaNavio(Navio *navios, float *pontos)
{
    if (navios->containers != NULL)
    {
        imprimirNavio(navios);
        Navio *proximoNavio = navios->proximo;
        free(navios);
        printf("\nO navio partiu\n");
        return proximoNavio;
    }
    else
    {
        printf("navio nao foi carregado:\n");
        imprimirNavio(navios);
        Navio *aux = navios;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = navios;
        Navio *proximoNavio = navios->proximo;
        navios->proximo = NULL;
        *pontos -= 0.05 * navios->capacidade;
        return proximoNavio;
    }
}

void menu(int *op)
{
    do
    {
        printf("\n\nEscolha uma opção:\n");
        printf("1-cadastro\n");
        printf("2-impressão\n");
        printf("3-carregamento\n");
        printf("4-score\n");
        printf("5-liberar memória\n");
        scanf("%d", &(*op));
    } while ((*op) < 1 || (*op) > 5);
}

void score(float pontos)
{
    printf("\nScore: %f\n", pontos);
}

void liberarMemoria(Navio *navios, Container *containers)
{
    if (navios != NULL)
    {
        Navio *auxNavio;
        auxNavio = navios;
        do
        {
            Navio *t;
            t = auxNavio->proximo;
            free(auxNavio);
            auxNavio = t;
        } while (auxNavio != NULL);
    }

    if (containers != NULL)
    {
        Container *auxContainers;
        auxContainers = containers;
        do
        {
            Container *t;
            t = auxContainers->proximo;
            free(auxContainers);
            auxContainers = t;
        } while (auxContainers != NULL);
    }
}
