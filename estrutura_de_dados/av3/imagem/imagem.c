#include "imagem.h"

struct pixel
{
    int pixel_value; //variar de 0 ate 255 usar rand();
};

struct imagem
{
    int altura, largura;
    Pixel *pixels_imagem;
};


Imagem *criarImagem()
{
    int altura, largura, i;
    printf("Digite a altura: ");
    scanf("%d", &altura);
    printf("Digite a largura: ");
    scanf("%d", &largura);

    Imagem *imagem = (Imagem *)calloc(1, sizeof(Imagem));
    imagem->pixels_imagem = (Pixel *)calloc(altura * largura, sizeof(Pixel));

    imagem->altura = altura;
    imagem->largura = largura;

    for (i = 0; i < altura * largura; i++)
    {
        imagem->pixels_imagem[i].pixel_value = rand() % 256;
    }
    return imagem;
}

Imagem *carregarImagem(char nomeArquivo[])
{
    Imagem *imagem = (Imagem *)calloc(1, sizeof(Imagem));
    FILE *file;
    file = fopen(nomeArquivo, "r");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        exit(0);
    }

    int altura, largura, i;

    fscanf(file, "%d %d", &altura, &largura);

    imagem->altura = altura;
    imagem->largura = largura;

    imagem->pixels_imagem = (Pixel *)calloc(altura * largura, sizeof(Pixel));

    for (i = 0; i < imagem->altura * imagem->largura; i++)
    {
        fscanf(file, "%d", &imagem->pixels_imagem[i].pixel_value);
    }

    fclose(file);
    printf("Arquivo lido com sucesso!\n");
    return imagem;
}

void salvarImagem(Imagem *imagem, char nomeArquivo[])
{
    int i;
    FILE *file;
    file = fopen(nomeArquivo, "w");
    int altura = imagem->altura;
    int largura = imagem->largura;
    fprintf(file, "%d %d\n", altura, largura);
    for (i = 0; i < altura * largura; i++)
    {
        fprintf(file, "%d ", imagem->pixels_imagem[i].pixel_value);
    }
    fclose(file);
    printf("Imagem salva com sucesso!\n");
}

void imprimirImagem(Imagem *imagem)
{
    int i;
    int altura = imagem->altura;
    int largura = imagem->largura;
    for (i = 0; i < altura * largura; i++)
    {

        printf("%d ", imagem->pixels_imagem[i].pixel_value);
    }
    printf("\n");
}

void maximoValor(Imagem *imagem, int *linha, int *coluna, int *maior)
{
    int altura = imagem->altura;
    int largura = imagem->largura;
    int maximo = imagem->pixels_imagem[0].pixel_value;
    int posicao = 0, i;
    for (i = 0; i < altura * largura; i++)
    {
        if (imagem->pixels_imagem[i].pixel_value > maximo)
        {
            maximo = imagem->pixels_imagem[i].pixel_value;
            posicao = i;
        }
    }
    *linha = posicao / largura;
    *coluna = posicao % largura;
    *maior = maximo;
    printf("Maior valor: %d | Linha: %d | Coluna: %d\n", maximo, *linha, *coluna);
}

void minimoValor(Imagem *imagem, int *linha, int *coluna, int *menor)
{
    int altura = imagem->altura;
    int largura = imagem->largura;
    int minimo = imagem->pixels_imagem[0].pixel_value;
    int posicao = 0, i;
    for (i = 0; i < altura * largura; i++)
    {
        if (imagem->pixels_imagem[i].pixel_value < minimo)
        {
            minimo = imagem->pixels_imagem[i].pixel_value;
            posicao = i;
        }
    }
    *linha = posicao / largura;
    *coluna = posicao % largura;
    *menor = minimo;
    printf("Menor valor: %d | Linha: %d | Coluna: %d\n", minimo, *linha, *coluna);
}

int distanciaEuclidiana(int linhaPixel1, int colunaPixel1, int linhaPixel2, int colunaPixel2)
{
    return (int)sqrt(pow(linhaPixel1 - linhaPixel2, 2) + pow(colunaPixel1 - colunaPixel2, 2));
}

int distanciaManhattan(int linhaPixel1, int colunaPixel1, int linhaPixel2, int colunaPixel2)
{
    return abs(linhaPixel1 - linhaPixel2) + abs(colunaPixel1 - colunaPixel2);
}

Imagem *LBP(Imagem *imagem)
{
    int i, j, k;
    int altura = imagem->altura;
    int largura = imagem->largura;
    if (altura < 3 || largura < 3)
    {
        printf("Dime insuficientes\n");
        return NULL;
    }

    //transformar Imagem em matriz
    int matriz[altura][largura];
    int cont = 0;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            matriz[i][j] = imagem->pixels_imagem[cont].pixel_value;
            cont++;
        }
    }

    Imagem *novaImagem = (Imagem *)calloc(1, sizeof(Imagem));
    novaImagem->pixels_imagem = (Pixel *)calloc((altura - 2) * (largura - 2), sizeof(Pixel));
    novaImagem->altura = altura - 2;
    novaImagem->largura = largura - 2;

    cont = 0;
    for (i = 1; i + 1 < altura; i++)
    {
        for (j = 1; j + 1 < largura; j++)
        {
            int centro = matriz[i][j];
            int valores[8];
            if (centro > matriz[i - 1][j - 1])
                valores[7] = 0;
            else
                valores[7] = 1;
            if (centro > matriz[i - 1][j])
                valores[6] = 0;
            else
                valores[6] = 1;
            if (centro > matriz[i - 1][j + 1])
                valores[5] = 0;
            else
                valores[5] = 1;
            if (centro > matriz[i][j - 1])
                valores[0] = 0;
            else
                valores[0] = 1;
            if (centro > matriz[i][j + 1])
                valores[4] = 0;
            else
                valores[4] = 1;
            if (centro > matriz[i + 1][j - 1])
                valores[1] = 0;
            else
                valores[1] = 1;
            if (centro > matriz[i + 1][j])
                valores[2] = 0;
            else
                valores[2] = 1;
            if (centro > matriz[i + 1][j + 1])
                valores[3] = 0;
            else
                valores[3] = 1;
            int novoValor = 0;
            for (k = 0; k < 8; k++)
            {
                novoValor += valores[k] * pow(2, k);
                // printf("valores[%d]=%d\n", k, valores[k]);
            }
            novaImagem->pixels_imagem[cont].pixel_value = novoValor;
            cont++;
        }
    }
    printf("Nova imagem gerada com sucesso!\n");
    return novaImagem;
}

Imagem *GLCM(Imagem *imagem)
{
    int altura = imagem->altura, i, j;
    int largura = imagem->largura;
    //transformar imagem em matriz
    int matriz[altura][largura];
    int cont = 0;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            matriz[i][j] = imagem->pixels_imagem[cont].pixel_value;
            cont++;
        }
    }

    cont = 0;
    int novaMatriz[256][256];
    for (i = 0; i < 256; i++)
    {
        for (j = 0; j < 256; j++)
        {
            novaMatriz[i][j] = 0;
            cont++;
        }
    }

    printf("Digite um dos seguintes valores: 0, 45, 90 ou 135: ");
    int angulo;
    scanf("%d", &angulo);

    if (angulo == 0)
    {
        for (i = 0; i < altura; i++)
        {
            for (j = 0; j + 1 < largura; j++)
            {
                novaMatriz[matriz[i][j]][matriz[i][j + 1]]++;
            }
        }
    }

    if (angulo == 45)
    {
        for (i = 0; i + 1 < altura; i++)
        {
            for (j = 0; j + 1 < largura; j++)
            {
                novaMatriz[matriz[i][j]][matriz[i + 1][j + 1]]++;
            }
        }
    }

    if (angulo == 90)
    {
        for (i = 0; i + 1 < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                novaMatriz[matriz[i][j]][matriz[i + 1][j]]++;
            }
        }
    }
    if (angulo == 135)
    {
        for (i = 1; i < altura; i++)
        {
            for (j = 0; j + 1 < largura; j++)
            {
                novaMatriz[matriz[i][j]][matriz[i - 1][j + 1]]++;
            }
        }
    }

    Imagem *novaImagem = (Imagem *)calloc(1, sizeof(Imagem));
    novaImagem->pixels_imagem = (Pixel *)calloc(256 * 256, sizeof(Pixel));

    novaImagem->altura = 256;
    novaImagem->largura = 256;
    cont = 0;
    for (i = 0; i < 256; i++)
    {
        for (j = 0; j < 256; j++)
        {
            novaImagem->pixels_imagem[cont].pixel_value = novaMatriz[i][j];
            cont++;
        }
    }
    printf("Nova imagem gerada com sucesso!\n");
    return novaImagem;
}

Imagem *Media(Imagem *imagem)
{
    int i, j, k, soma, x;
    int altura = imagem->altura;
    int largura = imagem->largura;

    //transformar Imagem em matriz
    int matriz[altura][largura];
    int cont = 0;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            matriz[i][j] = imagem->pixels_imagem[cont].pixel_value;
            cont++;
        }
    }

    Imagem *novaImagem = (Imagem *)calloc(1, sizeof(Imagem));
    novaImagem->pixels_imagem = (Pixel *)calloc((altura - 2) * (largura - 2), sizeof(Pixel));
    novaImagem->altura = altura - 2;
    novaImagem->largura = largura - 2;
    cont = 0;
    for (i = 1; i + 1 < altura; i++)
    {
        for (j = 1; j + 1 < largura; j++)
        {
            soma = matriz[i - 1][j - 1] + matriz[i - 1][j] + matriz[i - 1][j + 1] + matriz[i][j - 1] + matriz[i][j + 1] + matriz[i + 1][j - 1] + matriz[i + 1][j] + matriz[i + 1][j + 1] + matriz[i][j];
            soma /= 9;
            novaImagem->pixels_imagem[cont].pixel_value = soma;
            cont++;
        }
    }
    return novaImagem;
}

Imagem *Mediana(Imagem *imagem)
{
    int i, j, k, soma, x, aux;
    int altura = imagem->altura;
    int largura = imagem->largura;
    int vet[altura * largura];
    //transformar Imagem em matriz
    int matriz[altura][largura];
    int cont = 0;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            matriz[i][j] = imagem->pixels_imagem[cont].pixel_value;
            cont++;
        }
    }

    Imagem *novaImagem = (Imagem *)calloc(1, sizeof(Imagem));
    novaImagem->pixels_imagem = (Pixel *)calloc((altura - 2) * (largura - 2), sizeof(Pixel));
    novaImagem->altura = altura - 2;
    novaImagem->largura = largura - 2;

    for (k = 0; k < altura - 2; k++)
    {
        for (x = 0; x < largura - 2; x++)
        {
            //pega os valores da matriz 3x3 e coloca em uma posição do vetor
            for (i = k; i < k + 3; i++)
            {
                for (j = x; j < x + 3; j++)
                {
                    vet[k + x] = matriz[i][j];
                }
            }
            //aqui ordena o vetor com os valores da matriz
            for (i = 0; i < 9; i++)
            {
                for (j = 0; j < 9; j++)
                {
                    if (vet[i] < vet[j])
                    {
                        aux = vet[i];
                        vet[i] = vet[j];
                        vet[j] = aux;
                    }
                }
            }
            novaImagem->pixels_imagem[x + k].pixel_value = vet[5];
        }
    }
    return novaImagem;
}