
#ifndef _LESAO_H
#define _LESAO_H

#include "constantes.h"

typedef struct {
    char id[MAX_TAM_ID];
    char diagnostico[MAX_TAM_DIAG];
    char regiao[MAX_TAM_REGIAO];
    char cartaoSus[SUS_TAM];
    int chanceMalig;    
} Lesao;

Lesao lerLesao();
void printLesao(Lesao les);
void obtemCartaoSusLesao(Lesao les, char cartaoSus[]);


#endif