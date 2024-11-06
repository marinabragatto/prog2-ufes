#include<stdio.h>
#include <math.h>

int somaPesos(int resultado[], int tam){
    int i = 0, k = 0, soma = 0;

    for(k = 1, i = 0; i < tam; i++, k = k*10){
        soma = resultado[i]*k + soma;
    }
    return soma;
}

int decimalParaOctal(int num){
    int resto = 1, valor = 0, resultado[1000], result = 0, tam = 0, j = 0;
    valor = num;
   
    for(j = 0; valor != 0; j++, tam++){
        resto = valor%8;
        resultado[j] = resto;
        valor = valor/8;
    }
   // printf("tam === %d\n \n", tam);
    result = somaPesos(resultado, tam);
    return result;
    
}


int main(){
    int num = 0, octal = 0;

    scanf("%d", &num);

    octal = decimalParaOctal(num);

    printf("%d", octal);

    return 0;
}