#ifndef paciente_h
#define paciente_h

#define feminino 'F'
#define masculino 'M'

#include "lesao.h"

typedef struct{
    char nome[100];
    tData nascimento;
    char cartaoSUS[19];
    char genero;
    tLesao lesoes[10];
    int qtdLesoesPaciente;
}tPaciente;

tPaciente lePaciente();
void imprimeDadosPaciente(tPaciente paciente);
void imprimePaciente(tPaciente paciente);
int pacientePossuiEsseCartao(tPaciente paciente, char cartaosusdesejado[]);
tPaciente pacienteRecebeLesao(tPaciente paciente, tLesao lesao);
float retornaSomaIdadePacientes(tPaciente pacientes[], int qtdPacientes);
int mediaIdadePacientes(tPaciente pacientes[], int qtdPacientes);
void imprimevVetorPacientes(tPaciente pacientes[], int qtdPacientes);
int retornaIdxPacienteDesejado(tPaciente pacientes[], char cartaosusdesejado[], int qtd);

#endif