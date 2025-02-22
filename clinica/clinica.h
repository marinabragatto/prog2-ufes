#ifndef clinica_h
#define clinica_h

#define MAX_PACIENTES 100
#define MAX_LESOES 100


#include "paciente.h"
#include "lesao.h"

typedef struct {
    tPaciente pacientes[MAX_PACIENTES];
    tLesao lesoes[MAX_LESOES];
    int qtdLesoes;
    int qtdPacientes;
}tClinica;

tClinica inicializarClinica();
int getPacientesAtual(tClinica clinica);
int getLesoesAtual(tClinica clinica);
tClinica adicionaLesaoNoSistema(tClinica clinica, tLesao lesao);
int buscaSeLesaoJaExiste(tClinica clinica, char identificadorUnico[], int numeroLesoes);
void imprimeLesoesPacientes(tClinica clinica);
tClinica  recebePaciente(tClinica clinica, tPaciente paciente);
tClinica clinicaRecebeLesao(tClinica clinica, tLesao lesao, int idx);

#endif

