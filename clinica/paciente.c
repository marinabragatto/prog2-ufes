#include "utils.h"

tPaciente lePaciente(){
    tPaciente paciente;
    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", paciente.nome);
    paciente.nascimento = leData();
    scanf("%*[^0-9]");
    scanf("%[^\n]", paciente.cartaoSUS);
    scanf("%*[^FMO]");
    scanf("%c", &paciente.genero);
    paciente.qtdLesoesPaciente = 0;
    return paciente;
}

void imprimeDadosPaciente(tPaciente paciente){
    printf("nome: (%s)\ncpf: (%s)\ngenero: %c\n",paciente.nome, paciente.cartaoSUS, paciente.genero);
    printf("data nascimento: ");
    imprimeData(paciente.nascimento);
    if(paciente.qtdLesoesPaciente > 0){
        imprimeLesao(paciente.lesoes[0]);
    }

    return;
}

int pacientePossuiEsseCartao(tPaciente paciente, char cartaoosusdesejado[]){
    return ((strcmp(paciente.cartaoSUS, cartaoosusdesejado) ==0) ? 1 : 0);
}

tPaciente pacienteRecebeLesao(tPaciente paciente, tLesao lesao){
    paciente.lesoes[paciente.qtdLesoesPaciente] = lesao;
    paciente.qtdLesoesPaciente++;
    return paciente;
}

float retornaSomaIdadePacientes(tPaciente pacientes[], int qtdPacientes){ 
    int i = 0, soma = 0;
    for(i = 0; i < qtdPacientes; i++){
        soma += retornaIdade(pacientes[i].nascimento);
    }
    return (float)soma;
}

void imprimePaciente(tPaciente paciente){
    int i = 0;
    printf("- %s -", paciente.nome);
    for(i = 0 ; i < paciente.qtdLesoesPaciente; i++){
        printf(" %s", paciente.lesoes[i].idetificadorUnico);
    }
    //printf("\n");
    return;
}

int mediaIdadePacientes(tPaciente pacientes[], int qtdPacientes){
    float media = 0;

    media = retornaSomaIdadePacientes(pacientes, qtdPacientes);

    if(qtdPacientes > 0){
        media = round(media/qtdPacientes);
    }
    else{
        media = 0;
    }
    
    return (int)media;
}

void imprimevVetorPacientes(tPaciente pacientes[], int qtdPacientes){
    int i = 0;
    printf("LISTA DE PACIENTES:");

    for(i = 0; i < qtdPacientes;i++){
        if(pacientes[i].qtdLesoesPaciente > 0 ){
            printf("\n");
            imprimePaciente(pacientes[i]);
        }
        
    }
    return;
}

int retornaIdxPacienteDesejado(tPaciente pacientes[], char cartaosusdesejado[], int qtd){
    int i = 0;
    for(i = 0; i < qtd; i++){
        if(pacientePossuiEsseCartao(pacientes[i], cartaosusdesejado)){
            return i;
        }
    }
    return -1;
}