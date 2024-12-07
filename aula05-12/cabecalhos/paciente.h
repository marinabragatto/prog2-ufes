
#ifndef _PACIENTE_H
#define _PACIENTE_H

#include "lesao.h"
#include "data.h"
#include "constantes.h"

typedef struct {
    char nome[MAX_TAM_NOME];
    Data dataNasc;
    char cartaoSus[SUS_TAM];
    char genero;
    Lesao lesoes[MAX_TAM_LES];
    int qntLesao;
} Paciente;

Paciente lerPaciente();
void printPaciente(Paciente p);
void obtemCartaoSusPaciente(Paciente p, char cartaoSus[]);
Paciente insereLesaoPaciente(Paciente p, Lesao les);

#endif