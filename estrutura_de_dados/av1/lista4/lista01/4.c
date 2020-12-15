/*
Faça um programa em C que leia um conjunto de DVDs, onde cada um dos
DVDs possui as seguintes informações: Código, Título, Diretor, ano. Faça
uma opção onde permita aio usuáro ver todos os DVDs de um determinado
ano, outra que informe quais DVDs possuem título que iniciam com vogal
*/
#include <stdlib.h>
#include <stdio.h>

struct Dvd{
  int code, year;
  char title[20];
  char director[20];

};typedef struct Dvd Dvd;

void showRangeVowel(Dvd *dvds, int size){
  char vower;
  int i;
  setbuf(stdin, NULL);
  printf("Vogal: ");
  scanf("%c",&vower);
  
  for (i = 0; i < size; i++){
    if(dvds[i].title[0] == vower){
      printf("Titulo: %s\n", dvds[i].title);
      printf("Diretor: %s\n", dvds[i].director);
      printf("Codigo: %d\n", dvds[i].code);
      printf("Ano: %d\n", dvds[i].year);
      printf("------------\n");
    }
  }
}

void showRangeYear(Dvd *dvds, int size){
  int year, i;
  printf("Ano: ");
  scanf("%d",&year);
  for (i = 0; i < size; i++){
    if(dvds[i].year == year){
      printf("Titulo: %s\n", dvds[i].title);
      printf("Diretor: %s\n", dvds[i].director);
      printf("Codigo: %d\n", dvds[i].code);
      printf("Ano: %d\n", dvds[i].year);
      printf("------------\n");
    }
  }
}

void main(){
  Dvd *dvds;
  int countDvds, i;
  printf("Quantidade de DVDs: ");
  scanf("%d", &countDvds);
  
  dvds  = (Dvd *) calloc(countDvds, sizeof(Dvd));
  for (i = 0; i < countDvds; i++){
    printf("DVD %d\n", i + 1);
    printf("Titulo: ");
    scanf("%s", dvds[i].title);

    printf("Diretor: ");
    scanf("%s", dvds[i].director);

    printf("Codigo: ");
    scanf("%d", &dvds[i].code);

    printf("Ano: ");
    scanf("%d", &dvds[i].year);
  }

  while (1){
    int option;
    printf("1 - Pesquisar por ano\n");
    printf("2 - Pesquisar por vogal\n");
    scanf("%d", &option);
    if(option == 1)
      showRangeYear(dvds, countDvds);
    else if (option == 2)
      showRangeVowel(dvds, countDvds);
    else
      break;
  }
}