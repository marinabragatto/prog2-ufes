#include "utils.h"

void imprimeSaida(tClinica clinica);

int main(){
    //inicializar clinica
    char operacao = 'a';
    tClinica clinica;
    clinica = inicializarClinica();
    int pacientesCadastrados = 0, ret = 0;
    

    while(1){
        //limpa buffer
        scanf("%*[^PFL]");
        ret = scanf("%c", &operacao);

        if(ret == -1){
            break;
        }
        else if(operacao == 'P'){
            tPaciente paciente;
            paciente = lePaciente();    
            clinica = recebePaciente(clinica, paciente);
            pacientesCadastrados++;

        }
        else if(operacao == 'L'){
            char cartaosusdesejado[19];
            int idxP = 0;
            scanf("%*[^0-9]");
            scanf("%s", cartaosusdesejado);
            idxP = retornaIdxPacienteDesejado(clinica.pacientes, cartaosusdesejado, pacientesCadastrados);

            if(idxP == -1){
                tPaciente pacienteFantasma;
                tLesao lesao;
                lesao = leLesao();
                pacienteFantasma = pacienteRecebeLesao(pacienteFantasma, lesao);
            }
            else {
                tLesao lesao;
                lesao = leLesao();
                clinica = clinicaRecebeLesao(clinica, lesao, idxP);
            }
        }
        else if(operacao == 'F'){
            //break;
        }
    }
    imprimeSaida(clinica);    
    
    return 0;
}

void imprimeSaida(tClinica clinica){
    int qtdPacientes = 0, qtdLesoes = 0, i = 0, cirurgias = 0;

    qtdPacientes = getPacientesAtual(clinica);
    qtdLesoes = getLesoesAtual(clinica);
    cirurgias = retornaQtdLesoesCirurgicas(clinica.lesoes, qtdLesoes);

    printf("TOTAL PACIENTES: %d\n", qtdPacientes);
    printf("MEDIA IDADE (ANOS): %d\n", mediaIdadePacientes(clinica.pacientes, qtdPacientes));    
    printf("TOTAL LESOES: %d\n", qtdLesoes);    
    printf("TOTAL CIRURGIAS: %d\n", cirurgias);
    imprimevVetorPacientes(clinica.pacientes, qtdPacientes);
    
    return;
}