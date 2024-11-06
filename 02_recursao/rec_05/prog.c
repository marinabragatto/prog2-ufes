#include <stdio.h>

int fatorial(int n); 

int main(int argc, char * argv[]){
    FILE * arquivoEnt;
    FILE * arquivoSai;

	char caminhoArqEnt [1020] = {'t', 'e', 's', 't', 'e'};
    char caminhoArqSai [1020] = {'t', 'e', 's', 't', 'e'};
    
	sprintf(caminhoArqEnt, "input/%s", argv[1]);
    sprintf(caminhoArqSai, "outprog/%s", argv[1]);
	
    arquivoEnt = fopen(caminhoArqEnt, "r");
    arquivoSai = fopen(caminhoArqSai, "w");

    int num = 0;
    fscanf(arquivoEnt, "%d", &num);
    fprintf(arquivoSai, "%d\n", fatorial(num));

    return 0;
}

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n*fatorial(n-1);
    }
} 

/*    arquivo = fopen ("oi.txt","r");
    char palavra[200];
    fscanf(arquivo, "%s", palavra);
    printf("essa foi a palavra tirada do arquivo: (%s)\n", palavra);
*/