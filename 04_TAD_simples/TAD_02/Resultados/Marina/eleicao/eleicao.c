#include "candidato.h"
#include "eleicao.h"
#include "eleitor.h"
#include <stdio.h>

tEleicao InicializaEleicao(){
    tEleicao eleicao;
    int i = 0, qtd = 0;

    scanf("%d", &qtd);
    
    tCandidato canditados;
    int p = 0, g = 0;

    for(i = 0, p = 0, g = 0; i < qtd; i++){
        canditados = LeCandidato();
        if(ObtemCargo(canditados) == 'P' && p < 3){
            eleicao.presidentes[p] = canditados;
            //ImprimeCandidato(eleicao.presidentes[p], 0);
            p++;
            
        }
        else if(ObtemCargo(canditados) == 'G' && g < 3){
            eleicao.governadores[g] = canditados;
            //ImprimeCandidato(eleicao.governadores[g] , 0);
            g++;
        }
    }
    eleicao.totalPresidentes = p;

    eleicao.totalGovernadores = g;

    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    int qtd = 0;
    scanf("%*[^0-9]");
    scanf("%d", &qtd);

    tEleitor eleitor;
    int i = 0, qtdEleitoresValidos = 0, j = 0;
    int eleitor_analise = 0;



    for(i = 0; i < qtd; i++){
        eleitor = LeEleitor();

        // vamos analisar se ele já votou antes!
        if(qtdEleitoresValidos > 0){
            for(eleitor_analise = 0; eleitor_analise < qtdEleitoresValidos; eleitor_analise++){
                if (EhMesmoEleitor(eleicao.eleitores[eleitor_analise], eleitor)){
                    eleicao.totalEleitores = qtdEleitoresValidos + 1;
                    //printf("veja = (%d)", eleicao.totalEleitores);
                    //qtdEleitoresValidos++; 
                    // atribui e retorna uma eleicao ja anulada
                    if(eleitor_analise != 9){
                        eleicao.eleitores[eleitor_analise+1] = eleitor;
                        return eleicao;
                    }
                    else {
                        eleicao.eleitores[eleitor_analise-1] = eleitor;
                        return eleicao;
                    }
                }
            }
        }
        
        if(qtdEleitoresValidos < 10){
            eleicao.eleitores[qtdEleitoresValidos] = eleitor;
        }
        else{
            // finaliza a eleicao caso tenha mais de 10
            eleicao.totalEleitores = 11;
            return eleicao;
        }
        qtdEleitoresValidos++; 
    }
    eleicao.totalEleitores = qtdEleitoresValidos;
    if(eleicao.totalEleitores > 10){
        return eleicao;
    }
    
    //printf("veja dos eleitores de cada = (%d)\n", eleicao.totalEleitores);

    // agora vamos fazer a contagem de votos
    

    for(i = 0; i < eleicao.totalEleitores; i++){
        // vamos apurar os presidentes primeiro

        int votoP = 0, votoApurado = 0;
        votoP = ObtemVotoPresidente(eleicao.eleitores[i]);

        //pegamos o numero do voto e vamos passar pelo vetor candidato agora
        for(j = 0, votoApurado = 0; j < eleicao.totalPresidentes; j++){
            if(votoP == 0){
                eleicao.votosBrancosPresidente++;
                votoApurado = 1;
                break;
            }
            else if(votoP == eleicao.presidentes[j].id){
                eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                votoApurado = 1;
                break;
            } 
            
        }

        if(votoApurado == 0){
            eleicao.votosNulosPresidente++;
        }
        
            
        // governadores agora
        int votoG = 0;
        votoG = ObtemVotoGovernador(eleicao.eleitores[i]);
        //pegamos o numero do voto e vamos passar pelo vetor candidato agora
        for(j = 0, votoApurado = 0; j < eleicao.totalGovernadores; j++){
            if(votoG == 0){
                eleicao.votosBrancosGovernador++;
                votoApurado = 1;
                break;
            }
            if(votoG == eleicao.governadores[j].id){
                eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                votoApurado = 1;
                break;
            }
        }
        if(votoApurado == 0){
            eleicao.votosNulosGovernador++;
        }
        
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    int i = 0, j = 0, anulada = 0;

    for(i = 0; i < eleicao.totalEleitores;i++){
        for(j = 0; j < eleicao.totalEleitores;j++){
            if((EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])) && j != i){
                anulada = 1;
                break;
            }
        }
    }

    if(eleicao.totalEleitores == 11 || anulada == 1){
        printf("ELEICAO ANULADA\n");
        return;
    }

    int total = 0, k = 0, vencedorP = 0, empate = 0;
    float percentual = 0, maiorPercentual = 0;

    for(i = 0, k = 0, empate = 0, maiorPercentual = 0; i < eleicao.totalPresidentes; i++){
        total = eleicao.totalEleitores;
        percentual = CalculaPercentualVotos(eleicao.presidentes[i], total);
        if(percentual > maiorPercentual || k == 0){
                    k++;
                    maiorPercentual = percentual;
                    vencedorP = i;
                    empate = 0;
        }
        else if(percentual == maiorPercentual){
            empate = 1;
        }
    }

    printf("- PRESIDENTE ELEITO: ");
    if(empate == 1){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(eleicao.presidentes[vencedorP].votos < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)){
        printf("SEM DECISAO\n");
    }
    else {
        ImprimeCandidato(eleicao.presidentes[vencedorP], maiorPercentual);
    }
    

    int vencedorG = 0;

    for(i = 0, k = 0, maiorPercentual = 0, empate = 0; i < eleicao.totalGovernadores; i++){
        total = eleicao.totalEleitores;
        percentual = CalculaPercentualVotos(eleicao.governadores[i], total);
        if(percentual > maiorPercentual || k == 0){
                    k++;
                    maiorPercentual = percentual;
                    vencedorG = i;
                    empate = 0;
        }
        else if(percentual == maiorPercentual){
            empate = 1;
        }
    }

    printf("- GOVERNADOR ELEITO: ");
    if(empate == 1){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(eleicao.governadores[vencedorG].votos < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)){
        printf("SEM DECISAO\n");
    }
    else {
        ImprimeCandidato(eleicao.governadores[vencedorG], maiorPercentual);
    }
    
    
    int nulos = 0, brancos = 0;
    
    nulos = eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;
    brancos = eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente;

    printf("- NULOS E BRANCOS: %d, %d", nulos, brancos);

    return;

}
