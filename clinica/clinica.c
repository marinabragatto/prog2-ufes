#include "utils.h"

tClinica inicializarClinica(){
    tClinica clinica;
    clinica.qtdLesoes = 0;
    clinica.qtdPacientes = 0;
    return clinica;
}

int getPacientesAtual(tClinica clinica){
    return clinica.qtdPacientes;
}

int getLesoesAtual(tClinica clinica){
    return clinica.qtdLesoes;
}

tClinica adicionaLesaoNoSistema(tClinica clinica, tLesao lesao){
    int numeroLesoes = 0;
    numeroLesoes = getLesoesAtual(clinica);

    if(!(buscaSeLesaoJaExiste(clinica,lesao.idetificadorUnico, numeroLesoes))){
        clinica.lesoes[numeroLesoes] = lesao;
        clinica.qtdLesoes++;
    }

    
    return clinica;
}

int buscaSeLesaoJaExiste(tClinica clinica, char identificadorUnico[], int numeroLesoes){
    int i = 0;
    for(i = 0; i < numeroLesoes; i++){
        if(lesaoPossuiEsseID(clinica.lesoes[i] , identificadorUnico)){
            return 1;
        }
    }
    return 0;
}

void imprimeLesoesPacientes(tClinica clinica){
    int i = 0, numeroLesoes = 0, numeroPacientes = 0;

    numeroLesoes =  getLesoesAtual(clinica);
    printf("Relatorio de todas doencas cadastradas:\n");
    for(i = 0; i < numeroLesoes; i++){
        printf("Lesao %d\n", i+1);
        imprimeLesao(clinica.lesoes[i]);
        printf("\n");
    }

    numeroPacientes =  getPacientesAtual(clinica);
    printf("Relatorio de todos pacientes cadastrados:\n");
    for(i = 0; i < numeroPacientes; i++){
        printf("Paciente %d\n", i+1);
        imprimeDadosPaciente(clinica.pacientes[i]);
        printf("\n");
    }
    
    return;
}

tClinica  recebePaciente(tClinica clinica, tPaciente paciente){
    int qtdPacientes = 0;
    qtdPacientes = getPacientesAtual(clinica);
    clinica.pacientes[qtdPacientes] = paciente;
    clinica.qtdPacientes++;
    return clinica;
}

tClinica clinicaRecebeLesao(tClinica clinica, tLesao lesao, int idx){
    clinica.pacientes[idx] = pacienteRecebeLesao(clinica.pacientes[idx], lesao);
    clinica = adicionaLesaoNoSistema(clinica, lesao);
    return clinica;
}