/*
Escreva uma estrutura para conter três membros do tipo int chamados hora, min e
seg. Atribua o nome Time a essa estrutura.
Escreva outra estrutura para armazenar os dados de um estacionamento. Ela deve ser
capaz de armazenar os dados da placa do carro, a marca, a hora de entrada e a hora de
saída do estacionamento. Utilize dois membros do tipo tempo, definidos anteriormente
para as horas de entrada e saída.
Na função principal crie um vetor de ponteiros para a estrutura estacionamento,
preencha esse vetor e em seguida imprima as informações contida nele.
*/

#include <stdio.h>
#include <stdlib.h>

struct Time{
  int hour, minutes, seconds;
};
typedef struct Time Time;

struct Parking{
  char board[10];
  char brand[20];
  Time input;
  Time exit;
};
typedef struct Parking Parking;

void main(){

  Parking *parking;
  parking = (Parking*) calloc(1, sizeof(Parking));
  
  printf("Placa: ");
  scanf("%s", parking[0].board);
  printf("Marca: ");
  scanf("%s", parking[0].brand);
  printf("Hora da entrada: ");
  scanf("%d:%d:%d", &parking[0].input.hour, &parking[0].input.minutes, &parking[0].input.seconds);
  printf("Hora da saida: ");
  scanf("%d:%d:%d", &parking[0].exit.hour, &parking[0].exit.minutes, &parking[0].exit.seconds);

  printf("Placa: %s\n", parking[0].board);
  printf("Marca: %s\n", parking[0].brand);
  printf("Hora da entrada: %d:%d:%d\n", parking[0].input.hour, parking[0].input.minutes, parking[0].input.seconds);
  printf("Hora da saida: %d:%d:%d", parking[0].exit.hour, parking[0].exit.minutes, parking[0].exit.seconds);
}