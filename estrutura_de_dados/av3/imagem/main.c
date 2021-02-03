#include "imagem.h"

int menu()
{
    int opcao;
    printf("\n\t\t\t\tMenu\n");
    printf("\t\t\t(1) - criar uma imagem\n");
    printf("\t\t\t(2) - carregar imagem\n");
    printf("\t\t\t(3) - salvar imagem\n");
    printf("\t\t\t(4) - copiar imagem e salvar\n");
    printf("\t\t\t(5) - maximo valor\n");
    printf("\t\t\t(6) - minimo valor\n");
    printf("\t\t\t(7) - distancia euclidiana\n");
    printf("\t\t\t(8) - distancia manhattan\n");
    printf("\t\t\t(9) - Local Binary Pattern (LBP)\n");
    printf("\t\t\t(10) - Matriz de Coocorrência(GLCM)\n");
    printf("\t\t\t(11) - Filtro da média\n");
    printf("\t\t\t(12) - Filtro da mediana\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    if (opcao < 1 || opcao > 12)
    {
        return menu();
    }
    return opcao;
}

char* lerNomeArquivo()
{
    char *nomeArquivo = (char*) calloc(20, sizeof(char));
    printf("Digite o nome do arquivo (ex: arquivo.txt): ");
    scanf("%s", nomeArquivo);
    return nomeArquivo;
}

void main()
{
    Imagem *imagem;
    int linha, coluna, maior, menor;
    int linhaPixel1, linhaPixel2, colunaPixel1, colunaPixel2;
    srand(time(NULL));
    while (1)
    {
        switch (menu())
        {
        case 1:
            imagem = criarImagem();
            break;
        case 2:
            imagem = carregarImagem(lerNomeArquivo());
            break;
        case 3:
            salvarImagem(imagem, lerNomeArquivo());
            break;
        case 4:
            printf("Arquivo que deseja copiar\n");
            imagem = carregarImagem(lerNomeArquivo());
            printf("Copia\n");
            salvarImagem(imagem, lerNomeArquivo());
            break;
        case 5:
            imagem = carregarImagem(lerNomeArquivo());
            maximoValor(imagem, &linha, &coluna, &maior);
            break;
        case 6:
            imagem = carregarImagem(lerNomeArquivo());
            minimoValor(imagem, &linha, &coluna, &menor);
            break;
        case 7:
            printf("Digite o valor da linha e da coluna do primeiro pixel:\n");
            scanf("%d %d", &linhaPixel1, &colunaPixel1);
            printf("Digite o valor da linha e da coluna do segundo pixel:\n");
            scanf("%d %d", &linhaPixel2, &colunaPixel2);
            printf("%d",distanciaEuclidiana(linhaPixel1, colunaPixel1, linhaPixel2, colunaPixel2));
            break;
        case 8:
            printf("Digite o valor da linha e da coluna do primeiro pixel:\n");
            scanf("%d %d", &linhaPixel1, &colunaPixel1);
            printf("Digite o valor da linha e da coluna do segundo pixel:\n");
            scanf("%d %d", &linhaPixel2, &colunaPixel2);
            printf("%d",distanciaManhattan(linhaPixel1, colunaPixel1, linhaPixel2, colunaPixel2));
            break;
        case 9:
            imagem = carregarImagem(lerNomeArquivo());
            imagem = LBP(imagem);
            printf("Nova imagem LBP\n");
            salvarImagem(imagem, lerNomeArquivo());
            break;

        case 10:
            imagem = carregarImagem(lerNomeArquivo());
            imagem = GLCM(imagem);
            printf("Nova imagem GLCM\n");
            salvarImagem(imagem, lerNomeArquivo());
            break;

        case 11:
            imagem = carregarImagem(lerNomeArquivo());
            imagem = Media(imagem);
            printf("Nova imagem\n");
            salvarImagem(imagem, lerNomeArquivo());
            break;
        case 12:
            imagem = carregarImagem(lerNomeArquivo());
            imagem = Mediana(imagem);
            printf("Nova imagem\n");
            salvarImagem(imagem, lerNomeArquivo());
            break;
        }
    }
}