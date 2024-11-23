#include <stdio.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;
    candidato.cargo = cargo;
    candidato.id = id;
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.votos = 0;
     return candidato;
}


tCandidato LeCandidato(){
    tCandidato candidato;

    char nome[50], partido[50];

    scanf("%*[^a-zA-Z]");
    scanf("%[^,]", nome);
    scanf("%*[^a-zA-Z]");
    scanf("%[^,]", partido);
    scanf("%*[^PG]");
    
    char cargo = 'a';
    scanf("%c", &cargo);
    scanf("%*[^0-9]");
    
    int id = 0;
    scanf("%d", &id);

    candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;
}


int VerificaIdCandidato(tCandidato candidato, int id){
    if (candidato.id == id){
        return 1;
    }
    else {
        return 0;
    }
}


int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    if(candidato1.id == candidato2.id){
        return 1;
    }
    else {
        return 0;
    }
}


char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}


tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}


float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    return ((float)candidato.votos/totalVotos)*100;
}


void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos,  percentualVotos);
}



