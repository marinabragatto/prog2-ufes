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


//void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)
void * SomaInteiros(void * a, void * b);
void * SomaFloat(void * a, void * b);
void * SomaDouble(void * a, void * b);
void * SomaChar(void * a, void * b);
void * SomaNumComplexo(void * a, void * b);

void * MultiplicaInteiros(void * a, void * b);
void * MultiplicaFloat(void * a, void * b);
void * MultiplicaDouble(void * a, void * b);
void * MultiplicaChar(void * a, void * b);
void * MultiplicaNumComplexo(void * a, void * b);

void * converteInteiroComplexo(void * elemento);
void * converteFloatComplexo(void * elemento);
void * converteDoubleComplexo(void * elemento);
void * converteCharComplexo(void * elemento);

void escolheTipoMatrizImprime(tMatrizGenerica * mat, int tipo);
tMatrizGenerica * SelecionaMultiplicacaoMat(tMatrizGenerica * mat, tMatrizGenerica * trans, int tipo);


int main(){
    int colunas = 0, linhas = 0, tipo = 0;
    int op = 0;

    while(1){
        printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): \n");
        scanf("%d %d %d\n", &linhas, &colunas, &tipo);

        tMatrizGenerica * mat;
        
        if(tipo == 0){
            printf("oi");
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
        else {
            continue;
        }

        

        printf("Digite a operação desejada\n\t1 - Apenas imprimir a matriz\n\t2 - Converter para o tipo complexo e imprimir\n\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");
        scanf("%*[^0-9]");
        scanf("%d", &op);

        if(op == 1){
            escolheTipoMatrizImprime(mat, tipo);
        }
        else if(op == 2){
            tMatrizGenerica * convertida;
            if(tipo != 4){
                if(tipo == 0){
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteInteiroComplexo);
                    //escolheTipoMatrizImprime(c, tipo);
        
                }else if(tipo == 1){
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteFloatComplexo);
                }
                else if(tipo == 2){
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteDoubleComplexo);
                }
                else if(tipo == 3){
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteCharComplexo);
                }
            }
            else{
                convertida = mat;
            }
            ImprimirMatrizGenerica(convertida, ImprimeNumeroComplexo);
            DestroiMatrizGenerica(convertida);

            //convertida  = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), );
        }
        else if(op == 3){
            escolheTipoMatrizImprime(mat, tipo);

            tMatrizGenerica * convertida;
            if(tipo != 4){
                if(tipo == 0){
                    printf("\n\nheyy\n\n");
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteInteiroComplexo);
                    
                    //escolheTipoMatrizImprime(c, tipo);
        
                }else if(tipo == 1){
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteFloatComplexo);
                }
                else if(tipo == 2){
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteDoubleComplexo);
                }
                else if(tipo == 3){
                    convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteCharComplexo);
                }
            }
            ImprimirMatrizGenerica(convertida, ImprimeNumeroComplexo);
            tMatrizGenerica * trans ;
            convertida = mat;
            trans = MatrizTransposta(convertida);
            tMatrizGenerica * mult;
            mult = SelecionaMultiplicacaoMat(convertida, trans, 4);
            ImprimirMatrizGenerica(mult, ImprimeNumeroComplexo);
            DestroiMatrizGenerica(mult);
            DestroiMatrizGenerica(trans);
            DestroiMatrizGenerica(convertida);

        }
        DestroiMatrizGenerica(mat);
        printf("Digite a operação desejada\n\t1 - Entrar com uma nova matriz\n\t2 - Encerrar o Programa");
        scanf("%*[^0-9-]");
        int finalizar = -1;
        scanf("%d\n", &finalizar);
        if(finalizar == 2){
            break;
        }

    }

    return 0;
}

tMatrizGenerica * LeMatrizInteiros(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(linhas, colunas, sizeof(int));
    
    int i = 0, j = 0;
    void * elem;
    int inteiro = -1;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            elem = (int*)malloc(sizeof(int));
            scanf("%*[^0-9]");
            scanf("%d", &inteiro);
            //printf("%d ", inteiro);
            *((int *)elem) = inteiro;
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
        }
    }
    //ImprimirMatrizGenerica(mat, imprime_elementoInteiro);

    return mat;

}
tMatrizGenerica * LeMatrizChar(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(linhas, colunas, sizeof(char));
    
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
    mat = CriaMatrizGenerica(linhas, colunas, sizeof(double));
    
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
    mat = CriaMatrizGenerica(linhas, colunas, sizeof(float));
    
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
    printf("%d", *((int*)elem));
}

void imprime_elementoFloat(void * elem){
    printf("%f", *((float*)elem));
}

void imprime_elementoDouble(void * elem){
    printf("%lf", *((double*)elem));
}

void imprime_elementoChar(void * elem){
    printf("%c", *((char*)elem));
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

tMatrizGenerica * SelecionaMultiplicacaoMat(tMatrizGenerica * mat, tMatrizGenerica * trans, int tipo){
    tMatrizGenerica * mult;
    if(tipo == 0){
        mult = MultiplicaMatrizes(mat, trans, sizeof(int),SomaInteiros , MultiplicaInteiros);

    }else if(tipo == 1){
        mult = MultiplicaMatrizes(mat, trans, sizeof(float),SomaFloat , MultiplicaFloat );
    }
    else if(tipo == 2){
        mult = MultiplicaMatrizes(mat, trans, sizeof(double),SomaDouble , MultiplicaDouble);
    }
    else if(tipo == 3){
        mult = MultiplicaMatrizes(mat, trans, sizeof(char), SomaChar, MultiplicaChar);
    }
    else if(tipo == 4){
        printf("\nopaaa\n");
        mult = MultiplicaMatrizes(mat, trans, RetornaNumBytesComplexo(),MultiplicaNumComplexo, SomaNumComplexo);
        ImprimirMatrizGenerica(mult, ImprimeNumeroComplexo);
    }

    // void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)
    return mult;

}

void * SomaInteiros(void * a, void * b){
    void * ponteiro;
    ponteiro = (int*)malloc(sizeof(int));

    *((int*)ponteiro) = *((int*)a) + *((int*)b);

    return ponteiro;
}

void * SomaFloat(void * a, void * b){
    void * ponteiro;
    ponteiro = (float*)malloc(sizeof(float));

    *((float*)ponteiro) = *((float*)a) + *((float*)b);

    return ponteiro;

}
void * SomaDouble(void * a, void * b){
    void * ponteiro;
    ponteiro = (double*)malloc(sizeof(double));

    *((double*)ponteiro) = *((double*)a) + *((double*)b);

    return ponteiro;
}
void * SomaChar(void * a, void * b){
    void * ponteiro;
    ponteiro = (char*)malloc(sizeof(char));

    *((char*)ponteiro) = *((char*)a) + *((char*)b);

    return ponteiro;
}
void * SomaNumComplexo(void * a, void * b){
    void * ponteiro;
    ponteiro = SomaComplexos(((tNumComplexo*)a) , ((tNumComplexo*)b));
    return ponteiro;
}

void * MultiplicaInteiros(void * a, void * b){
    void * ponteiro;
    ponteiro = (int*)malloc(sizeof(int));

    *((int*)ponteiro) = (*((int*)a)) * (*((int*)b));

    return ponteiro;
}
void * MultiplicaFloat(void * a, void * b){
    void * ponteiro;
    ponteiro = (float*)malloc(sizeof(float));

    *((float*)ponteiro) = (*((float*)a)) * (*((float*)b));

    return ponteiro;

}
void * MultiplicaDouble(void * a, void * b){
    void * ponteiro;
    ponteiro = (double*)malloc(sizeof(double));

    *((double*)ponteiro) = (*((double*)a)) * (*((double*)b));

    return ponteiro;
}
void * MultiplicaChar(void * a, void * b){
    void * ponteiro;
    ponteiro = (char*)malloc(sizeof(char));

    *((char*)ponteiro) = (*((char*)a)) * (*((char*)b));

    return ponteiro;
}
void * MultiplicaNumComplexo(void * a, void * b){
    void * ponteiro;
    ponteiro = MultComplexos(((tNumComplexo*)a) , ((tNumComplexo*)b));
    return ponteiro;
}

void * converteInteiroComplexo(void * elemento){
    void * conv;
    conv = CriaNumComplexo((*(int*)elemento), 0);
    return conv;
}


void * converteFloatComplexo(void * elemento){
    void * conv;
    conv = CriaNumComplexo((*(float*)elemento), 0);
    return conv;

}
void * converteDoubleComplexo(void * elemento){
    void * conv;
    conv = CriaNumComplexo((*(double*)elemento), 0);
    return conv;
}
void * converteCharComplexo(void * elemento){
    void * conv;
    conv = CriaNumComplexo((*(char*)elemento), 0);
    return conv;
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