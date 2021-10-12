#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main(){
    int m = 3, n = 3;
    int matriz[m][n];
    int raio;
    
    if(m < n) raio = m/2;
    else raio = n/2;

    for(int index = 0; index < m; index++){
        for(int indexTwo = 0; indexTwo < n; indexTwo++){
            matriz[index][indexTwo] = 0;
        }
    }
    for(int index = 1; index <= m; index++){
        for(int indexTwo = 1; indexTwo <= n; indexTwo++){
            if((index == raio && index < raio) || indexTwo == raio){
                matriz[index - 1][indexTwo - 1] = 1;
            }
            printf("%d ",matriz[index - 1][indexTwo - 1]);
        }
        printf("\n");
    }

}
