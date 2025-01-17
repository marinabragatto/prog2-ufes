/*(PONT_11) Problema: Faça uma calculadora usando o conceito de callback. A função 
float Calcular(float num1, float num2, CalculatoraCallback operacao); recebe dois 
números e a função que irá realizar a operação. É importante salientar que as 
funções que realizarão as operações deverão ser criadas no arquivo main.c. 
• Entrada: um caractere que poderá ser ‘a’ para adição, ‘s’ para subtração, ‘m’ para 
multiplicação, ‘d’ para divisão ou ‘f’ para encerrar o programa. Para cada 
operação, serão lidos 2 números.  
• Saída: O resultado de cada operação solicitada, com precisão de 2 casas 
decimais. 
Ver exemplos de formato de entrada e saída nos arquivos fornecidos com a questão.*/
#include "calculadora.h"
#include <stdio.h>
float adicao(float n1, float n2);
float subtracao(float n1, float n2);
float divisao(float n1, float n2);
float multiplicacao(float n1, float n2);

int main(){
    char op = 'w';
    float n1=0, n2=0, res = 0;

    while(1){
        scanf("%*[^asmdf]");
        scanf("%c", &op);
        
        CalculatoraCallback operacao;

        if(op != 'f'){
            scanf("%f %f", &n1, &n2);
            if(op =='a'){
                operacao = &adicao;
                res = Calcular(n1,n2,operacao);
                //res = Calcular(n1,n2,&adicao);
                printf("%.2f + %.2f = %.2f\n", n1, n2, res);
            }
            else if(op == 's'){
                operacao = &subtracao;
                res = Calcular(n1,n2,operacao);
                //res = Calcular(n1,n2,&subtracao);
                printf("%.2f - %.2f = %.2f\n", n1, n2, res);
            }
            else if(op == 'm'){
                operacao = &multiplicacao;
                res = Calcular(n1,n2,operacao);
                //res=Calcular(n1,n2,&multiplicacao);
                printf("%.2f x %.2f = %.2f\n", n1, n2, res);
            }
            else if(op == 'd'){
                operacao = &divisao;
                res = Calcular(n1,n2,operacao);
                //res=Calcular(n1,n2,&divisao);
                printf("%.2f / %.2f = %.2f\n", n1, n2, res);
            }
            

        }
        else {
            break;
        }
    }

 //   10.00 + 59.00 = 69.00
//59.00 - 10.00 = 49.00
//15.00 x 12.00 = 180.00
//68.00 + 156.00 = 224.00
//12.00 / 6.00 = 2.00
    return 0;
}

float adicao(float n1, float n2){
    return n1 + n2;
}
float subtracao(float n1, float n2){
    return n1 - n2;
}
float divisao(float n1, float n2){
    return n1/n2;
}
float multiplicacao(float n1, float n2){
    return n1*n2;
}