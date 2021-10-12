#include <stdio.h>
#include "arquivo.h"
#include <stdlib.h>

void main(){
    int *array, i;
    int sizeList = 10;

    array = (int *) calloc(sizeList, sizeof(int));
    for(i = 0; i<sizeList; i++ ){
        array[i] = i;
    }
    for(i = 0; i<sizeList; i++ ){
        printf("%d ",array[i]);
    }
    addItemList(array, 900, &sizeList);
    printf("\n");
    for(i = 0; i<sizeList; i++ ){
        printf("%d ",array[i]);
    }
    
}