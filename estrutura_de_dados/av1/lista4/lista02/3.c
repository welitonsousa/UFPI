/*
Escreva uma estrutura para conter três membros do tipo int chamados hora, min e
seg. Atribua o nome tempo a essa estrutura.
Escreva outra estrutura para armazenar os dados de um estacionamento. Ela deve ser
capaz de armazenar os dados da placa do carro, a marca, a hora de entrada e a hora de
saída do estacionamento. Utilize dois membros do tipo tempo, definidos anteriormente
para as horas de entrada e saída.
Na função principal crie um vetor de ponteiros para a estrutura estacionamento,
preencha esse vetor e em seguida imprima as informações contida nele.
*/

#include <stdio.h>
#include <stdlib.h>

struct Tempo{
  int hora, min, seg;
};
typedef struct Tempo Tempo;

struct Estacionamento{
  char placa[10];
  char marca[20];
  Tempo entrada;
  Tempo saida;
};
typedef struct Estacionamento Estacionamento;

void main(){

  Estacionamento *estacionamento;
  estacionamento = (Estacionamento*) calloc(1, sizeof(Estacionamento));
  
  printf("Placa: ");
  scanf("%s", estacionamento[0].placa);
  printf("Marca: ");
  scanf("%s", estacionamento[0].marca);
  printf("Hora da entrada: ");
  scanf("%d%d%d", &estacionamento[0].entrada.hora, &estacionamento[0].entrada.min, &estacionamento[0].entrada.seg);
  printf("Hora da saida: ");
  scanf("%d%d%d", &estacionamento[0].saida.hora, &estacionamento[0].saida.min, &estacionamento[0].saida.seg);

  printf("\nPlaca: %s\n", estacionamento[0].placa);
  printf("Marca: %s\n", estacionamento[0].marca);
  printf("Hora da entrada: %d:%d:%d", estacionamento[0].entrada.hora, estacionamento[0].entrada.min, estacionamento[0].entrada.seg);
  printf("Hora da saida: %d:%d:%d", estacionamento[0].saida.hora, estacionamento[0].saida.min, estacionamento[0].saida.seg);
}