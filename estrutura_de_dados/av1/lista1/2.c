#include <stdio.h>

void main(){
    char word[10];
    scanf("%s", word);

    for (int index = 0; word[index] != '\0'; index++){
        for (int indexTwo = index + 1; word[indexTwo] != '\0'; indexTwo++){
            if(word[index]== word[indexTwo]){
                printf("%c ", word[index]);
                break;
            }
        }
    }
}