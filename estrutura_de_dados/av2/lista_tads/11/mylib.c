#include "mylib.h"

struct TConjunto{
    int *elementos, quantidade_elementos;
};

TConjunto * criar_conjunto(){
    TConjunto * conjunto;
    conjunto = (TConjunto *) malloc(sizeof(TConjunto *));
    conjunto->quantidade_elementos = 0;
    return conjunto;
}

void ler_conjunto(TConjunto * conjunto){
    int quantidade_termos = 0;
    printf("numero de termos que deseja inserir:\n");
    conjunto->elementos = (int *) calloc(quantidade_termos, sizeof(int *));

    scanf("%d", &quantidade_termos);
    for (int i = 0; i < quantidade_termos; i++){
        int termo;
        scanf("%d", &termo);
        conjunto->elementos[conjunto->quantidade_elementos] = termo;
        conjunto->quantidade_elementos += 1;
    }
}

int conjunto_igual(TConjunto * conjunto1, TConjunto * conjunto2){
    if (conjunto1->quantidade_elementos != conjunto2->quantidade_elementos) return 0;
    else{
        for(int i = 0; i < conjunto1->quantidade_elementos; i++)
            if (conjunto1->elementos[i] != conjunto2->elementos[i]) return 0;
    }
    return 1;
}

void uniao(TConjunto * conjunto1, TConjunto * conjunto2){
    int size1 = conjunto1->quantidade_elementos;
    int size2 = conjunto2->quantidade_elementos;
    if (size1 > size2){
        for(int i = 0; i < size2; i++){
            for(int j = 0; j < size1; j++){
                if(conjunto1->elementos[j] == conjunto2->elementos[i]){
                    printf("%d ", conjunto2->elementos[i]);
                    break;
                }
            }
        }
    }
}


void intersecao(TConjunto * conjunto1, TConjunto * conjunto2){
    int size1 = conjunto1->quantidade_elementos;
    int size2 = conjunto2->quantidade_elementos;
    if (size1 > size2){
        for(int i = 0; i < size2; i++){
            printf("%d ", conjunto1->elementos[i]);
        }

        for(int i = 0; i < size2; i++){
            int flag = 0;
            for(int j = 0; j < size1; j++)
                if (conjunto1->elementos[j] == conjunto2->elementos[i]) flag = 1;
            if (flag == 0) printf("%d ", conjunto1->elementos[i]);
        }
    }
}


void imprimir(TConjunto * conjunto){
    for(int i = 0; i< conjunto->quantidade_elementos; i++){
        printf("%d ", conjunto->elementos[i]);
    }
}