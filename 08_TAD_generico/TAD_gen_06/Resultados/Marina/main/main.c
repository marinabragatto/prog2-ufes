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


void * SomaNumComplexo(void * a, void * b);


void * MultiplicaNumComplexo(void * a, void * b);

void * converteInteiroComplexo(void * elemento);
void * converteFloatComplexo(void * elemento);
void * converteDoubleComplexo(void * elemento);
void * converteCharComplexo(void * elemento);

void escolheTipoMatrizImprime(tMatrizGenerica * mat, int tipo);
tMatrizGenerica * escolheTipoMatrizLe(tMatrizGenerica * mat, int tipo, int linhas, int colunas);
tMatrizGenerica * escolheTipoMatrizConverteComp(tMatrizGenerica * mat, int tipo);
tMatrizGenerica * multiplicaMatrizComplexa(tMatrizGenerica * mat, tMatrizGenerica * trans);



int main(){
    int colunas = 0, linhas = 0, tipo = 0;
    int op = 0;

    while(1){
        while (1){
            printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): ");
            scanf("%d %d %d\n", &linhas, &colunas, &tipo);
            if(tipo >= 0 && tipo <= 4){
                printf("\n");
                break;
            }
        }

        tMatrizGenerica * mat;
        
        mat = escolheTipoMatrizLe(mat, tipo, linhas, colunas);

        
        
        while(1){
            printf("Digite a operação desejada\n\t1 - Apenas imprimir a matriz\n\t2 - Converter para o tipo complexo e imprimir\n\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");
            scanf("%*[^0-9]");
            scanf("%d", &op);
            if(op >= 1 && op <= 3){
                break;
            }
        }
        
        if(op == 1){
            escolheTipoMatrizImprime(mat, tipo);
        }
        else if(op == 2){
            tMatrizGenerica * convertida;
            convertida = escolheTipoMatrizConverteComp(mat,tipo);
            
            ImprimirMatrizGenerica(convertida, ImprimeNumeroComplexo);
            printf("\n");
            
            if(convertida != mat){
                DestroiMatrizGenerica(convertida);
            }
        }
        else if(op == 3){
            tMatrizGenerica * convertida;
            convertida = escolheTipoMatrizConverteComp(mat, tipo);
            
            tMatrizGenerica * trans ;
            trans = MatrizTransposta(convertida);

            tMatrizGenerica * mult;
            mult = multiplicaMatrizComplexa(convertida, trans);

            ImprimirMatrizGenerica(mult, ImprimeNumeroComplexo);
            printf("\n");

            DestroiMatrizGenerica(mult);
            DestroiMatrizGenerica(trans);

            if(convertida != mat){
                DestroiMatrizGenerica(convertida);
            }
        }
        int finalizar = -1;
        DestroiMatrizGenerica(mat);
        while(1){
            printf("Digite a operação desejada\n\t1 - Entrar com uma nova matriz\n\t2 - Encerrar o Programa\n");
            scanf("%*[^0-9-]");
            
            scanf("%d\n", &finalizar);
            if(finalizar == 1 || finalizar == 2){
                break;
            }
            
        }
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
            *((int *)elem) = inteiro;
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
            free(elem);
        }
    }

    return mat;

}
tMatrizGenerica * LeMatrizChar(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(linhas, colunas, sizeof(char));
    
    int i = 0, j = 0;
    void * elem;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            elem = (char*)malloc(sizeof(char));
            scanf("%*[^0-9-]");
            scanf("%c", &*((char*)elem));
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
            free(elem);
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
            free(elem);
        }
    }

    return mat;
}
tMatrizGenerica * LeMatrizNumComplexo(int colunas, int linhas){
    tMatrizGenerica * mat;
    mat = CriaMatrizGenerica(linhas, colunas, RetornaNumBytesComplexo());
    
    int i = 0, j = 0;
    void * elem;
    float n1, n2;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%*[^(]");
            scanf("(%f,%f)", &n1, &n2);
            elem = CriaNumComplexo(n1, n2);
            AtribuiElementoMatrizGenerica(mat, i , j, elem);
            free(elem);
        }
    }

    return mat;
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
            free(elem);
        }
    }

    return mat;
}

void imprime_elementoInteiro(void * elem){
    printf("%d", *((int*)elem));
}

void imprime_elementoFloat(void * elem){
    printf("%.2f", *((float*)elem));
}

void imprime_elementoDouble(void * elem){
    printf("%.2lf", *((double*)elem));
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

tMatrizGenerica * multiplicaMatrizComplexa(tMatrizGenerica * mat, tMatrizGenerica * trans){
    tMatrizGenerica * mult;
   
    mult = MultiplicaMatrizes(mat, trans, RetornaNumBytesComplexo(),MultiplicaNumComplexo, SomaNumComplexo);

    return mult;

}


void * SomaNumComplexo(void * a, void * b){
    void * ponteiro;
    ponteiro = SomaComplexos(((tNumComplexo*)a) , ((tNumComplexo*)b));
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
    float num= 0;
    if((*(char*)elemento) == '1'){
        num = 1;
    } 
    if((*(char*)elemento) == '2'){
        num = 2;
    }
    if((*(char*)elemento) == '3'){
        num = 3;
    }
    if((*(char*)elemento) == '4'){
        num = 4;
    }
    if((*(char*)elemento) == '5'){
        num = 5;
        
    }if((*(char*)elemento) == '6'){
        num = 6;
    }
    if((*(char*)elemento) == '7'){
        num = 7;
    }
    if((*(char*)elemento) == '8'){
        num = 8;
    }
    if((*(char*)elemento) == '9'){
        num = 9;
    }
    conv = CriaNumComplexo(num, 0);
    return conv;
}

tMatrizGenerica * escolheTipoMatrizLe(tMatrizGenerica * mat, int tipo, int linhas, int colunas){
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
    else {
        return NULL;
    }
    return mat;
}

tMatrizGenerica * escolheTipoMatrizConverteComp(tMatrizGenerica * mat, int tipo){
    tMatrizGenerica * convertida;

    if(tipo == 0){
        convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteInteiroComplexo);

    }else if(tipo == 1){
        convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteFloatComplexo);
    }
    else if(tipo == 2){
        convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteDoubleComplexo);
    }
    else if(tipo == 3){
        convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), converteCharComplexo);
    }
    else if(tipo == 4){
        convertida = mat;
    }

    return convertida;

}
