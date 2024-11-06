#include <stdio.h>

void ImprimeInvertido(char* string); 
int retornaTam(char* string);

int main(){
    
    char word[1000];
    int ret = 1;

    ret = scanf("%s", word);

    while (ret != -1 && ret != 0){
        ImprimeInvertido(word);
        printf(" ");
        ret = scanf("%s", word);
    }
    

    return 0;
}

void ImprimeInvertido(char* string){
    int tam = 0;

    tam = retornaTam(string);

    if(tam == 1){
        printf("%c", string[0]);
        return;
    }
    else {
        ImprimeInvertido(string+1);
        printf("%c", string[0]);
    }
}

int retornaTam(char* string){
    int i = 0;
    for(i = 0; string[i] ;i++);
    return i;
}

/*(REC_01) Problema: Implemente uma função, utilizando o conceito de recursão, que 
receba uma string como parâmetro e a imprima de trás para frente.  
Cabeçalho: void ImprimeInvertido(char* string); 
Utilizando a função anterior, faça um programa que leia palavras de um texto 
(considere palavras como uma sequência de caracteres diferentes de espaço) e as 
imprime de trás para frente. 
Definição dos formatos de entrada e saída: 
• Entrada: um texto contendo palavras com no máximo 1000 caracteres cada. 
• Saída: o texto com as palavras impressas de trás para frente. 
Ver exemplos de formato de entrada e saída nos arquivos fornecidos com a questão.  */