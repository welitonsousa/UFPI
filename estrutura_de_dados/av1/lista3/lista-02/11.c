/*
Crie uma struct que represente alunos, com nome, matrícula e um vetor com 3 notas. Construa
um programa para auxiliar um professor na atribuição de notas e separação entre aprovados(média
de notas >= 7) e reprovados. Seu programa deve receber, em tempo de execução, a quantidade de
alunos da disciplina para que seja alocado um espaço adequado. Em seguida, disponibilize ao
professor as opções de cadastrar alunos, atribuir nota, imprimir aprovados e/ou reprovados.
*/
#include "11-funcoes.h"

void main(){
  struct Aluno *alunos;
  int size = 0;

  while (1){
    alunos = menu(alunos, &size);
  }
}