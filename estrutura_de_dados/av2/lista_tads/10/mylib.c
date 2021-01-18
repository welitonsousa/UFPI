#include "mylib.h"

int comprimento(char * str){
    int count = 0;
    while (str[count] != '\0')
        count ++;
    return count;
}

void copia(char* dest, char* orig){
    int size_orig = comprimento(orig);
    dest = (char *) calloc(size_orig, sizeof(char *));
    for(int i = 0; i < size_orig; i++){
        dest[i] = orig[i];
    }
}

void concatena (char* dest, char* orig){
    int size_dest = comprimento(dest);
    int size_orig = comprimento(orig);

    dest = (char *) realloc(dest, (size_orig + size_dest) * sizeof(char *));
    int count = 0;
    for (int i = size_dest; i < size_orig; i++){
        dest[i] = orig[count];
        count ++;
    }
}