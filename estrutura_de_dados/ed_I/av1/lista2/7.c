#include <stdio.h>

void capturar(int n, float *x){
    int i = 0;
    for(i = 0; i< n; i++){
        x[i] = i;
    }
}

float media(int n, float *x){
    int i = 0, media = 0;
    for(i = 0; i< n; i++){
        media  += x[i];
    }
    return media/n;
}

float varianvia(int n, float *x, float m){
    int i = 0, soma = 0;
    for(i = 0; i< n; i++){
        soma += (x[i] - m) * (x[i] - m);
    }
    soma /= n;
    return soma;
}

void main(){
    float vet[10], vMedia, variancia;
    int i = 0, n = 10;

    capturar(n, vet);
    for(i = 0; i< 10; i++){
        printf("%.0f\n", vet[i]);
    }
    
    vMedia = media(n, vet);
    variancia = varianvia(n, vet, vMedia);
    printf("Meida: %.2f ", vMedia); 
    printf("Variancia: %.2f ", variancia); 
}