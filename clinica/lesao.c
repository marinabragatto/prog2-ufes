#include "utils.h"

tLesao leLesao(){
    tLesao lesao;
    scanf("%*[^a-zA-Z0-9]");
    scanf("%[^\n]", lesao.idetificadorUnico);
    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", lesao.diagnostico);
    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", lesao.regiaoCorpo);
    scanf("%d", &lesao.porcentagemMalignidade);

    return lesao;
}


void imprimeLesao(tLesao lesao){
    printf("id: (%s)\ndiagnostico: (%s)\nregiao corpo: (%s)\nmalognidade: (%d)\n", lesao.idetificadorUnico, lesao.diagnostico, lesao.regiaoCorpo, lesao.porcentagemMalignidade);
    return;
}

int lesaoPossuiEsseID(tLesao lesao , char identificadorUnico[]){
    return ((strcmp(lesao.idetificadorUnico, identificadorUnico) == 0) ? 1 : 0);

}

int retornaQtdLesoesCirurgicas(tLesao lesoes[], int qtd){
    int i = 0, soma = 0;
    for (i  = 0; i < qtd; i++){
        if(ehCirurgica(lesoes[i])){
            soma++;
        }
    }
    return soma;
}

int ehCirurgica(tLesao lesao){
    return((lesao.porcentagemMalignidade > 50) ? 1 : 0);
}