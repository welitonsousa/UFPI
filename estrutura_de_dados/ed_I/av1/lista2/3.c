#include <stdio.h>

void main(){
    int notas[3], i;
    float media = 0, * ptMedia = &media;
    for(i = 0; i < 3; i++){

        printf("Forneca a nota de indice %d: ", i);
        scanf("%d", &notas[i]);
        
        *ptMedia += notas[i]; 
    }
    *ptMedia /=  3;
    printf("MEDIA: %f\n", *ptMedia);

    if(*ptMedia < 4) printf("Reprovado\n");
    else if(*ptMedia < 7) printf("Reculperacao\n");
    else printf("Aprovado\n");

}