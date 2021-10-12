// Crie um programa que implemente o jogo “Bingo de Prog II”.Nesse jogo, o jogador
// deve selecionar a quantidade de números que ele gostaria de apostar (entre 1 e 20), e
// em seguida, informar os números escolhidos (valores entre 0 e 100). Após receber a
// aposta, o computador sorteia 20 números (entre 0 e 100) e compara os números
// sorteados com os números apostados, informando ao apostador a quantidade de
// acertos e os números que ele acertou.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lerAposta(int *aposta, int *size){
  int i;
  int apostaAtual;
  for (i = 0; i < *size; i++){
    printf("Numero %d: ", i + 1);
    scanf("%d", &apostaAtual);
    if (apostaAtual >= 0 && apostaAtual <= 100)
      aposta[i] = apostaAtual;
    else
      i--;
  }
}

void sorteiaValores(int *sorteio, int n){
  int i;
  srand(time(NULL));

  int numeros[100];
  for ( i = 0; i < 100; i++)
    numeros[i] = i + 1;

  for ( i = 0; i < 100; i++){
    int posicaoAleatoria = rand() % 100;
    int aux = numeros[i];
    numeros[i] = numeros[posicaoAleatoria];
    numeros[posicaoAleatoria] = aux;
  }
  for ( i = 0; i < n; i++)
    sorteio[i] = numeros[i];
}

int *comparaAposta(int *aposta, int *sorteio, int *qtdAcertos, int size){
  int i, j;
  int *acertos;
  for (i = 0; i < size; i++){
    for (j = 0; j < size; j++){
      if (aposta[i] == sorteio[j]){
        printf("%d ", aposta[i]);
        *qtdAcertos += 1;
        if(*qtdAcertos == 1)
          acertos = (int *) calloc(*qtdAcertos, sizeof(int));
        else if(*qtdAcertos > 1)
          acertos = (int *) realloc(acertos, *qtdAcertos * sizeof(int));
        acertos[*qtdAcertos - 1] = aposta[i];
        break;
      }
    }
  }
    printf("\n");
  return acertos;
}

void main()
{
  int *aposta, *sorteio, *acertos;
  int sizeAposta, qtdAcerto = 0, i;
  
  printf("Quantidade de numeros na aposta: ");
  scanf("%d", &sizeAposta);

  aposta = (int *) calloc(sizeAposta, sizeof(int));
  lerAposta(aposta, &sizeAposta);
  sorteio = (int *) calloc(sizeAposta, sizeof(int));
  sorteia_valores(sorteio, sizeAposta);
  
  printf("Aposta: ");
  for (i = 0; i < sizeAposta; i++)
    printf("%d ", aposta[i]);
  printf("\nSorteio: ");
  for (i = 0; i < sizeAposta; i++)
    printf("%d ", sorteio[i]);
  printf("\n");

  acertos = comparaAposta(aposta, sorteio, &qtdAcerto, sizeAposta);
  
  printf("Acertos: ");
  for (i = 0; i < qtdAcerto; i++)
    printf("%d ", acertos[i]);
  printf("\nTotal de acertos: %d", qtdAcerto);
}
