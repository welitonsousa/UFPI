#include <stdio.h>
#include <stdlib.h>

struct Aluno{
  char nome[10];
  int matricula;
  int notas[3];
};

void showAllStudants(struct Aluno *listAlunos, int size){
  int i, j;
  if(size > 0){
    for(i = 0; i < size; i++){
      printf("%d - ",i+1);
      for(j = 0; listAlunos[i].nome[j]!= '\0'; j++){
        printf("%c", listAlunos[i].nome[j]);
      }
      printf("\tMatricula: %d\n", listAlunos[i].matricula);
    }
  }else{
    printf("Nenhum aluno cadastrado\n");
  }
}

void showStudantsFailed(struct Aluno *alunos, int *size){
  int i, j;
  if(*size > 0){
    for(i = 0; i < *size; i++){
      int media = 0;
      if(alunos[i].notas[0] >= 0){
        media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
        if(media < 7){
          printf("%d - ",i+1);
          for(j = 0; alunos[i].nome[j]!= '\0'; j++){
            printf("%c", alunos[i].nome[j]);
          }
          printf("\tMatricula: %d\n", alunos[i].matricula);
        }
      }
    }
  }
}
void showStudantsApproved(struct Aluno *alunos, int *size){
  int i, j;
  if(*size > 0){
    for(i = 0; i < *size; i++){
      int media = 0;
      if(alunos[i].notas[0] >= 0){
        media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
        if(media >= 7){
          printf("%d - ",i+1);
          for(j = 0; alunos[i].nome[j]!= '\0'; j++){
            printf("%c", alunos[i].nome[j]);
          }
          printf("\tMatricula: %d\n", alunos[i].matricula);
        }
      }
    }
  }
}


struct Aluno * addStudant(struct Aluno *list, int *size){
  *size += 1;
  if(*size == 1)
    list = (struct Aluno *)malloc(*size * sizeof(struct Aluno));
  else
    list = (struct Aluno *)realloc(list, *size * sizeof(struct Aluno));
  
  printf("Nome: ");
  scanf("%s", list[*size - 1].nome);
  setbuf(stdin, NULL);

  printf("Matricula: ");
  scanf("%d", &list[*size - 1].matricula);
  list[*size - 1].notas[0] = -1;
  list[*size - 1].notas[1] = -1;
  list[*size - 1].notas[2] = -1;
  return list;
}

struct Aluno * addNote(struct Aluno *listAlunos, int *size){
  showAllStudants(listAlunos, *size);

  printf("\nSelecione a posicao do aluno: ");
  int position = -1;
  scanf("%d", &position);

  if(position > 0 && position <= *size){
    position -= 1;
    printf("Digite as 3 notas separadas por um espaco\nNotas: ");
    scanf("%d %d %d", &listAlunos[position].notas[0], &listAlunos[position].notas[1], &listAlunos[position].notas[2]);
  }else{
    printf("Esta posicao nao existe\n");
  }
  return listAlunos;
}


struct Aluno * menu(struct Aluno *alunos, int *size){
  int opcao = 0;
  printf("MENU\n");
  printf("1 - Cadastrar aluno\n");
  printf("2 - Atribuir nota\n");
  printf("3 - Imprimir aprovados\n");
  printf("4 - Imprimir reprovados\n");
  printf("5 - Imprimir Alunos\n");
  printf("Valor: ");
  
  scanf("%d", &opcao);
  printf("||||||||||||||||||||||\n");
  switch (opcao){
  case 1:
    alunos = addStudant(alunos, size);
    break;
  case 2:
    alunos = addNote(alunos, size);
    break;
  case 3:
    showStudantsApproved(alunos, size);
    break;
  case 4:
    showStudantsFailed(alunos, size);
    break;
  case 5:
    showAllStudants(alunos, *size);
    break;
  default:
    printf("\nFim");
    exit(0);
    break;
  }
  printf("||||||||||||||||||||||\n");
  return alunos;
}
