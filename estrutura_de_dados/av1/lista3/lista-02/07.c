/*
Utilizando alocação dinâmica, refaça o exercício abaixo(da lista anterior),
acrescentando as funções para alocar e liberar espaço de memória às estruturas
manipuladas (Ou seja, a quantidade de jogadores e reservas deve ser apresentada
em tempo de execução).
*/
/*
(UFPR) Crie uma struct para armazenar os dados (nome, idade, posição,
numero_camisa) dos jogadores de vôlei de um time. Crie duas estruturas
para armazenar os jogadores principais e os reservas. Desenvolva um
programa que o usuário consiga entrar com os jogadores principais(seis)
e reservas(4) e mostre-os na tela. Para Facilitar a entrada de dados,
utilize um menu. 
*/

#include <stdio.h>
#include <stdlib.h>

struct jogador *allocVet(int *size){
  struct jogador *vet = (struct jogador *)malloc(*size * sizeof(struct jogador *));
  return vet;
}

void freeMemory(struct jogador *vet){
  free(vet);
}

struct jogador{
  int camisa;
  char nome[100];
  int idade;
  char posicao[100];
};

void main(){
  struct jogador *jogadores; 
  int numeroJogadores = 5, i;

  jogadores = allocVet(&numeroJogadores);
  
  printf("Jogadores principais:\n");
  for(i = 0; i < numeroJogadores; i++){
    printf("Jogador N%d\n", i+1);
    
    printf("Nome: ");
    scanf("%[^\n]s", jogadores[i].nome);
    setbuf(stdin, NULL);
    
    printf("Idade: ");
    scanf("%d", &jogadores[i].idade);

    printf("Camasa: ");
    scanf("%d", &jogadores[i].camisa);

    printf("Posicao: ");
    scanf("%s", jogadores[i].posicao);
    setbuf(stdin, NULL);
    
    if(i == 6)
      printf("Jogadores reservas:\n");
  }
  
  for(i = 0; i < numeroJogadores - 4; i++){
    printf("Jogador N%d\n", i+1);
    printf("Nome: %s\n", jogadores[i].nome);
    printf("Idade: %d\n", jogadores[i].idade);
    printf("Camisa: %d\n", jogadores[i].camisa);
    printf("Posicao: %s\n", jogadores[i].posicao);
    
    printf("\n");
    if(i == 6)
      printf("Jogadores reservas:\n");
  }
  freeMemory(jogadores);
}