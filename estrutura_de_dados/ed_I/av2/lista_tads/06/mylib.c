#include "mylib.h"

struct livro{
    char titulo[50]; char autor[30]; char genero[10]; int ano;
};

Livro *livro_cria(char titulo[], char autor[], char genero[], int ano){
    Livro *livro = (Livro *) malloc(sizeof(Livro));
    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);
    strcpy(livro->genero, genero);
    livro->ano = ano;
    return livro;
}

char *genero(Livro *livro){
    return livro->genero;
}

char *autor(Livro *livro){
    return livro->autor;
}

char *titulo(Livro *livro){
    return livro->titulo;
}

int ano(Livro *livro){
    return livro->ano;
}

int livro_verifica(Livro *livro){
    if (livro->ano < 1930) return -1;
    else if (livro->ano <= 1945) return 0;
    return 1;
}
