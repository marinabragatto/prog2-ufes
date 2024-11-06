#include <stdio.h>

int palindromo(char *string, int tamanho); 
int retornaTam(char *string);
//int numeroCompNec(int comp);

int main (){
    char string[1000];

    int ret = 0, num = 0, comp = 0, retScan = 0;

    while(1){
        retScan = scanf("%s", string);

        if(retScan == -1 || retScan == 0){
            break;
        }

        comp = retornaTam(string);

        if(palindromo(string, comp)){
            printf("SIM");
            printf("\n");
        }
        else {
            printf("NAO");
            printf("\n");
        }
    }
    return 0;
}

int retornaTam(char *string){
    int i = 0;
    for(i = 0; string[i]; i++);
    return i;
}

int palindromo(char *string, int tamanho){
    if(tamanho == -1 || tamanho == 0){
        return 1;
    }
    else if(string[0] == string[tamanho - 1]){
        return palindromo(string+1, tamanho - 2);
    }
    else {
        return 0;
    }
}
/*
int numeroCompNec(int comp){
    if(comp % 2 != 0){
        return comp/2 + 1;
    }
    else{
        return comp/2;
    }
}*/