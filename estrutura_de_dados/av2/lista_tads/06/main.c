#include "mylib.h"

void main(){
    Livro * livro = livro_cria("aguas do deserto", "weliton", "terror", 1999);
    printf("%s\n", titulo(livro));
    printf("%s\n", autor(livro));
    printf("%s\n", genero(livro));
    printf("%d\n", ano(livro));
    printf("%d\n", livro_verifica(livro));
}