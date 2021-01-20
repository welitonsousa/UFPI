#include "mylib.h"

void main(){
    int op;
    float p_num1 = 0, p_num2 = 0, resultado = 0;
    do{
        menu(&op);
        numeros(&p_num1, &p_num2);
        
        if (op == 1) soma(p_num1, p_num2, &resultado); 
        else if (op == 2) subtrair(p_num1, p_num2, &resultado);
        else if (op == 3) multiplicar(p_num1, p_num2, &resultado);
        else if (op == 4) dividir(p_num1, p_num2, &resultado);
        if (op >= 1 && op <= 4) printf("Resuldado: %f\n", resultado);
    }while(op != 5);
}