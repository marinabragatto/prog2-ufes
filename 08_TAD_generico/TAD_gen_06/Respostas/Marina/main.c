#include <stdio.h>
#include <stdlib.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"

tMatrizGenerica * LeMatrizInteiros(int colunas, int linhas);
tMatrizGenerica * LeMatrizChar(int colunas, int linhas);
tMatrizGenerica * LeMatrizDouble(int colunas, int linhas);
tMatrizGenerica * LeMatrizFloat(int colunas, int linhas);
tMatrizGenerica * LeMatrizNumComplexo(int colunas, int linhas);

void imprime_elementoInteiro(void * elem);
void imprime_elementoFloat(void * elem);
void imprime_elementoDouble(void * elem);
void imprime_elementoChar(void * elem);

int somaInteiros(int a, int b);
void escolheTipoMatrizImprime(tMatrizGenerica * mat, int tipo);


int main(){
    int colunas = 0, linhas = 0, tipo = 0;
    int op = 0;

    while(1){
        printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): \n");
        scanf("%d %d %d\n", &linhas, &colunas, &tipo);

        tMatrizGenerica * mat;
        
        if(tipo == 0){
            mat = LeMatrizInteiros(colunas, linhas);

        }else if(tipo == 1){
            mat = LeMatrizFloat(colunas, linhas);
        }
        else if(tipo == 2){
            mat = LeMatrizDouble(colunas, linhas);
        }
        else if(tipo == 3){
            mat = LeMatrizChar(colunas, linhas);
        }
        else if(tipo == 4){
            mat = LeMatrizNumComplexo(colunas, linhas);
        }

        

        printf("Digite a operação desejada\n\t1 - Apenas imprimir a matriz\n\t2 - Converter para o tipo complexo e imprimir\n\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");
        scanf("%*[^0-9]");
        scanf("%d", &op);

        if(op == 1){
            escolheTipoMatrizImprime(mat, tipo);

        }
        else if(op == 1){

        }
        else if(op == 3){
            tMatrizGenerica * trans ;
            trans = MatrizTransposta(mat);
            tMatrizGenerica * mult;
          // mult = MultiplicaMatrizes(mat, trans, ,);

        }

    }

    return 0;
}

tMatrizGenerica * LeMatrizInteiros(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(colunas, linhas, sizeof(int));
    
    int i = 0, j = 0;
    void * elem;
    int inteiro = -1;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            elem = (int*)malloc(sizeof(int));
            scanf("%*[^0-9]");
            scanf("%d", &inteiro);
            *((int *)elem) = inteiro;
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
        }
    }

    return mat;

}
tMatrizGenerica * LeMatrizChar(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(colunas, linhas, sizeof(char));
    
    int i = 0, j = 0;
    void * elem;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            elem = (int*)malloc(sizeof(int));
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
        }
    }

    return mat;
}
tMatrizGenerica * LeMatrizDouble(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(colunas, linhas, sizeof(double));
    
    int i = 0, j = 0;
    void * elem;
    double racional = -1;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            elem = (double*)malloc(sizeof(double));
            scanf("%*[^0-9]");
            scanf("%lf", &racional);
            *((double *)elem) = racional;
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
        }
    }

    return mat;
}
tMatrizGenerica * LeMatrizNumComplexo(int colunas, int linhas){


}

tMatrizGenerica * LeMatrizFloat(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(colunas, linhas, sizeof(float));
    
    int i = 0, j = 0;
    void * elem;
    float racional = -1;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            elem = (float*)malloc(sizeof(float));
            scanf("%*[^0-9]");
            scanf("%f", &racional);
            *((float *)elem) = racional;
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
        }
    }

    return mat;
}

void imprime_elementoInteiro(void * elem){
    printf("%d", ((int*)elem));
}

void imprime_elementoFloat(void * elem){
    printf("%f", ((float*)elem));
}

void imprime_elementoDouble(void * elem){
    printf("%lf", ((double*)elem));
}

void imprime_elementoChar(void * elem){
    printf("%c", ((char*)elem));
}

void escolheTipoMatrizImprime(tMatrizGenerica * mat, int tipo){
    if(tipo == 0){
        ImprimirMatrizGenerica(mat, imprime_elementoInteiro);

    }else if(tipo == 1){
        ImprimirMatrizGenerica(mat, imprime_elementoFloat);
    }
    else if(tipo == 2){
        ImprimirMatrizGenerica(mat, imprime_elementoDouble);
    }
    else if(tipo == 3){
        ImprimirMatrizGenerica(mat, imprime_elementoChar);
    }
    else if(tipo == 4){
        ImprimirMatrizGenerica(mat, ImprimeNumeroComplexo);
    }
    return ;
}
/*
2 2 0
1 2
3 4
3
2*/
/*
Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): 
Digite a operação desejada
	1 - Apenas imprimir a matriz
	2 - Converter para o tipo complexo e imprimir
	3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.
5.00 + i0.00 11.00 + i0.00 
11.00 + i0.00 25.00 + i0.00 

Digite a operação desejada
	1 - Entrar com uma nova matriz
	2 - Encerrar o Programa*/