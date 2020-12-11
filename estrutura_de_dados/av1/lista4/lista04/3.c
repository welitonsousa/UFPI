/*
Faça um programa em C que leia um conjunto de livros, onde cada um dos
livros possui as seguintes informações: Título, Autor, Editora, ano de edição e
números de exemplares. O usuário poderá inserir quantos livros desejar
desde que não ultrapasse o limite máximo do conjunto. Faça uma opção onde
o usuário digite a Editora e o programa mostre todos os livros cadastrados
daquela editora e repita o mesmo para Autor
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Book{
  char title[20];
  char author[20];
  char publishingCompany[20];
  int publishYear;
  int NumberCopies;
};typedef struct Book Book;

Book * search(char AorE ,Book * books, int size, int * sizeResult){
  Book *result;
  int i;
  char keyWord[20];
  *sizeResult = 0;
  printf("Pesquisar: ");
  scanf("%s", keyWord);
  for(i = 0; i < size; i++){
    if(AorE == 'E'){
      if(!strcmp(books[i].publishingCompany , keyWord)){
        *sizeResult += 1;
        if(*sizeResult == 1)
          result = (Book *) calloc(*sizeResult, sizeof(Book));
        else
          result = (Book *) realloc(result, (*sizeResult) * sizeof(Book));
        result[*sizeResult - 1] = books[i];
      }
    }else{
      if(!strcmp(books[i].author , keyWord)){
        *sizeResult += 1;
        if(*sizeResult == 1)
          result = (Book *) calloc(*sizeResult, sizeof(Book));
        else
          result = (Book *) realloc(result, (*sizeResult) * sizeof(Book));
        result[*sizeResult - 1] = books[i];
      }
    }
  }
  return result;
}

void main(){
  int numberBooks = 2, i, j;
  Book *books = (Book*) calloc(numberBooks, sizeof(Book));
  
  printf("Cadastre os livros\n");
  for(i = 0; i < numberBooks; i++){
    printf("Livro %d\n", i + 1);
    printf("Titulo: ");
    scanf("%s", books[i].title);

    printf("Autor: ");
    scanf("%s", books[i].author);

    printf("Editora: ");
    scanf("%s", books[i].publishingCompany);

    printf("Ano de edicao: ");
    scanf("%d", &books[i].publishYear);

    printf("Numero de copias: ");
    scanf("%d", &books[i].NumberCopies);
  }

  while (1){
    int option, sizeResult, i;
    Book * result;
    printf("1 - Pesquisar por editora\n");
    printf("2 - Pesquisar por autor\n");
    printf("Opcao: ");
    scanf("%d", &option);
    if (option == 1)
      result = search('E', books, numberBooks, &sizeResult);
    if (option == 2)
      result = search('A', books, numberBooks, &sizeResult);
    else
      break;
    for(i = 0; i < sizeResult; i++){
      printf("Titulo: %s\n",result[i].title);
      printf("Autor: %s\n",result[i].author);
      printf("Editora: %s\n",result[i].publishingCompany);
      printf("Ano de edicao: %d\n",result[i].publishYear);
      printf("Numero de copias: %d\n",result[i].NumberCopies);
      printf("------------\n");
    }
  }
  

}