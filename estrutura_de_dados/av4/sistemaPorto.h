#ifndef sistemaPorto_h
#define sistemaPorto_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct container Container;
typedef struct navio Navio;

Navio *cadastrarNavio(Navio *navios);
Container *cadastrarContainer(Container *containers);
void imprimirContainers(Container *containers);
void imprimirNavios(Navio *navios);
void imprimirNavio(Navio *navios);
Container *removerContainer(Container *container, Container *containerProximo, Container *containersLista);
Navio *adicionarContainerNoNavio(Container *container, Navio *navio);
int verificaSeAlgumNavioCarregaAlgumContainer(Container *containers, Navio *navios);
Container *carregarNavio(Container *containers, Navio *navios, float *pontos);
Navio *partidaNavio(Navio *navios, float *pontos);
void menu(int *op);
void score(float pontos);
void liberarMemoria(Navio *navios, Container *containers);

#endif