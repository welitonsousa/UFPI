#include<stdlib.h>

addItemList(int *list, int item, int *size){
    *size += 1;
    list = (int *)realloc(list, *size * sizeof(int));
    list[*size - 1] = item;
}