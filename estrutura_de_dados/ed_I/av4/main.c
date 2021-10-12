
#include "sistemaPorto.h"

void main()
{
    srand(time(NULL));
    int op;
    float pontos = 0;
    Navio *navios = (Navio *)calloc(1, sizeof(Navio *));
    navios = NULL;
    Container *containers = (Container *)calloc(1, sizeof(Container *));
    containers = NULL;

    do
    {
        menu(&op);
        switch (op)
        {
        case 1:
            do
            {
                printf("\nEscolha uma opção:\n");
                printf("1-cadastrar container\n");
                printf("2-cadastrar navio\n");
                scanf("%d", &(op));
            } while ((op) < 1 || (op) > 2);
            switch (op)
            {
            case 1:
                containers = cadastrarContainer(containers);
                break;
            case 2:
                navios = cadastrarNavio(navios);
                break;
            }
            break;
        case 2:
            do
            {
                printf("\nEscolha uma opção:\n");
                printf("1-imprimir containers\n");
                printf("2-imprimir navios\n");
                scanf("%d", &(op));
            } while ((op) < 1 || (op) > 2);
            switch (op)
            {
            case 1:
                imprimirContainers(containers);
                break;
            case 2:
                imprimirNavios(navios);
                break;
            }
            break;
        case 3:
            if(navios == NULL){
                printf("Cadastre um navio primeiro");
            }
            else if (verificaSeAlgumNavioCarregaAlgumContainer(containers, navios))
            {
                containers = carregarNavio(containers, navios, &pontos);
                navios = partidaNavio(navios, &pontos);
            }
            if(!verificaSeAlgumNavioCarregaAlgumContainer(containers, navios))
            {
                imprimirNavios(navios);
                imprimirContainers(containers);
                score(pontos);
                liberarMemoria(navios, containers);
                return;
            }

            break;
        case 4:
            score(pontos);
            break;
        case 5:
            liberarMemoria(navios, containers);
            break;
        }
    } while (op < 7);
}