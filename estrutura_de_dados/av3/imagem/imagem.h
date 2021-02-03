#ifndef sistemaPorto_h
#define sistemaPorto_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct pixel Pixel;
typedef struct imagem Imagem;

Imagem *criarImagem();
Imagem *carregarImagem();
void salvarImagem(Imagem *imagem, char nomeArquivo[]);
void imprimirImagem(Imagem *imagem);
void maximoValor(Imagem *imagem, int *linha, int *coluna, int *maior);
void minimoValor(Imagem *imagem, int *linha, int *coluna, int *menor);
int distanciaEuclidiana( int linhaPixel1, int colunaPixel1, int linhaPixel2, int colunaPixel2);
int distanciaManhattan( int linhaPixel1, int colunaPixel1, int linhaPixel2, int colunaPixel2);
Imagem *LBP(Imagem *imagem);
Imagem *GLCM(Imagem *imagem);
Imagem *Media(Imagem *imagem);
Imagem *Mediana(Imagem *imagem);



#endif