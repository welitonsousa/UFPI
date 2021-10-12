/*
Construa um programa que aloque em uma matriz, de maneira dinâmica, os itinerários, horários
e respectivos preços de passagens de uma determinada companhia de transportes. De modo que o
operador de transportes possa, em tempo de execução, definir a quantidade de cidades que sua
empresa trabalha. Escreva as funções que julgar necessária e realize testes no método main.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
  int qtdCidades, i;
  printf("Digite quantidade de cidades: ");
  scanf("%d", &qtdCidades);
  char **mat = (char **) calloc(qtdCidades, sizeof(char));

  for (i = 0; i < qtdCidades; i++){
    char itinerario[100], horario[10], preco[10];

    printf("Cidade %d:\n", i + 1);
    
    printf("Itinerario: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", itinerario);
    setbuf(stdin, NULL);
    
    printf("Horario: ");
    scanf("%s", horario);
    setbuf(stdin, NULL);

    printf("Preco: R$ ");
    scanf("%s", preco);

    int len = strlen(itinerario);
    len += strlen(horario);
    len += strlen(preco);

    char *stringFinal = (char *) calloc(len, sizeof(char));
    strcat(stringFinal, itinerario);
    strcat(stringFinal, " - ");
    strcat(stringFinal,  horario);
    strcat(stringFinal, " R$");
    strcat(stringFinal, preco);
    
    mat[i] = (char *) calloc(len, sizeof(char));
    strcpy(mat[i], stringFinal);
    printf("string = %s\n", mat[i]);
  }
}