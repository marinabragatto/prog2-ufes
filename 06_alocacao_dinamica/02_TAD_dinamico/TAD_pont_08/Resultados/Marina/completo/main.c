#include "departamento.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_MIN 20

void LeDepartamento(tDepartamento *depto);
char *LeString(char * string);
char *AumentaTamanhoString(char * string, int * tamanho);

int main(){
    int qtd = 0;
    scanf("%d\n", &qtd);

    tDepartamento *deptos[qtd];
    int i = 0;

    for(i = 0; i < qtd; i++){
        deptos[i] = CriaDepartamento();
        LeDepartamento(deptos[i]);
    }

    OrdenaPorMediaDepartamentos(deptos, qtd);

    for(i = 0; i < qtd; i++){
        ImprimeAtributosDepartamento(deptos[i]);
        LiberaMemoriaDepartamento(deptos[i]);
    }
    //printf("hello");

    return 0;
}

void LeDepartamento(tDepartamento *depto){
    char *c1, *c2, *c3, *nome, *diretor;
    int m1, m2, m3; 

    nome = LeString(nome);
    diretor = LeString(diretor);
    c1 = LeString(c1);
    c2 = LeString(c2);
    c3 = LeString(c3);
    scanf("%d %d %d\n", &m1, &m2, &m3);
    
    PreencheDadosDepartamento(depto, c1, c2, c3, nome, m1, m2, m3, diretor);
    
    free(c1);
    free(c2);
    free(c3);
    free(nome);
    free(diretor);
    return;
}

char *LeString(char * string){
    char letraAtual = 'a';
    int tamanho = 0, idx = 0;

    string = NULL;
    
    while(1){
        scanf("%c", &letraAtual);

        if(letraAtual == '\n'){
            string[idx] = '\0';
            break;
        }
        else{
            if(idx >= tamanho || idx == 0){
                string = AumentaTamanhoString(string, &tamanho);
            }
            string[idx] = letraAtual;
            idx++;
        }
    }
    return string;
}

char *AumentaTamanhoString(char * string, int * tamanho){
    int length = (*tamanho)+1+TAM_MIN;
    string = (char*)realloc(string, sizeof(char)*(length));
    (*tamanho) = (*tamanho)+TAM_MIN;    
    string[*tamanho] = '\0';
    return string;
}

/*3
CT
Luiz
EngComputacao
EngProducao
EngEletrica
9 7 6
CCJE
Joana
Direito
Administracao
Economia
5 8 4
CCE
Helio
Matematica
Fisica
Estatistica
6 5 7
*/
