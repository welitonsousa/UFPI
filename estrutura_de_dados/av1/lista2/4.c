#include <stdio.h>

void calc(int * soma, int * produto, int a, int b, int c){
    *soma = a + b + c;
    *produto = a * b * c;
}

void main(){
    int a, b, c;
    int soma, produto;
    
    printf("Informe tres valores: ");
    scanf("%d %d %d", &a, &b, &c);
    calc(&soma, &produto, a, b, c);
    printf("SOMA: %d\nPRODUTO: %d\n", soma, produto);
}

