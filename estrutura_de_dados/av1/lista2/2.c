#include <stdio.h>

void inverte(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void main(){
    int a, b;
    printf("Informe dois valores: ");
    
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
    
    inverte(&a, &b);
    printf("%d %d\n", a, b);
}