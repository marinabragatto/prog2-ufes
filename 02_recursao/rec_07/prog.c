#include <stdio.h>
#include <math.h>

int somaDigitos(int n);
int contaAlgarismos(int n);

int main(int argc, char * argv[]){
    FILE * arquivoEnt;
    FILE * arquivoSai;

    char caminhoEnt[1020];
    char caminhoSai[1020];

    sprintf(caminhoEnt, "input/%s",argv[1]);
    sprintf(caminhoSai, "outprog/%s", argv[1]);

    arquivoEnt = fopen (caminhoEnt, "r");
    arquivoSai = fopen (caminhoSai, "w");

    int num = 0;

    fscanf(arquivoEnt, "%d", &num);

    fprintf(arquivoSai,"%d\n", somaDigitos(num));

    return 0;
}

int somaDigitos(int n){
    int tam = 0;
    tam = contaAlgarismos(n);
    if(tam == 1){
        return n;
    }
    else{
        int alg, prox, div;
        alg = n/pow(10, tam - 1);
        div = pow(10,tam-1);
        prox = (n%div);
        return alg + somaDigitos(prox);
    }
    
}

int contaAlgarismos(int n){
    int i = 0, t = 0;
    int aux = n;
    for(i = 1, t = 0; aux; i = i*10, t++){
        aux = n/i;
    }
    
    return t-1;
}