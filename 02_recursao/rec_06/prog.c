#include <stdio.h>

int fibonacci(int n);

int main(int argc, char * argv[]){
    FILE * arquivoEnt;
    FILE * arquivoSai;
    
    char caminhoEnt[1020] = {'t', 'e', 's', 't', 'e'};
    char caminhoSai[1020] = {'t', 'e', 's', 't', 'e'};

    sprintf(caminhoEnt, "input/%s", argv[1]);
    sprintf(caminhoSai, "outprog/%s", argv[1]);

    arquivoEnt = fopen (caminhoEnt, "r");
    arquivoSai = fopen(caminhoSai, "w");

    int num = 0;
    fscanf(arquivoEnt,"%d", &num);
    

    fprintf(arquivoSai,"%d\n", fibonacci(num));


    return 0;
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci (n - 2);
    }
}