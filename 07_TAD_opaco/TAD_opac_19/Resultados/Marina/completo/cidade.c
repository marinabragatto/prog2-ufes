#include <stdlib.h>
#include "cidade.h"
#include "missil.h"
#include "defesa.h"

#define NEUTRO 1
#define PARCIAL_NEUTRO 2
#define ATIVO 3

/**
 * @brief Estrutura que representa uma cidade.
 * 
 * A estrutura tCidade contém o nome da cidade, a quantidade de mísseis e defesas, e as listas de mísseis e defesas.
 * 
 */
struct cidade{
    float x, y;
    char nome[MAX_NOME];
    int qtdDefesas;
    int qtdMisseis;
    float possivelDano;
    float dano;
    tDefesa * defesas;
    tMissil * misseis;
}; 


float RetornaPossivelDano(tMissil * missis, int qtd){
    int i  = 0; 
    float somador = 0;
   // printf("olha a quantidade!");
    for(i = 0; i < qtd; i++){
        somador += GetMissilPoder(missis[i]);

    }
    return somador;
}

int VerificaSeraMissilNeutralizado(tDefesa defesa, tMissil missil){
    float xMis, yMis;
    xMis = GetMissilX(missil);
    yMis = GetMissilY(missil);


    if(VerificaSeDentroArea(defesa , xMis, yMis) && PodeDefender(defesa)){
        if(GetDefesaPoder(defesa) < GetMissilPoder(missil)) {
            return PARCIAL_NEUTRO;
        }
        return NEUTRO;
    }

    return ATIVO;
}

float retornaModuloNumero(float numero){
    if(numero<0){
        return -numero;
    }
    return numero;
}


/**
 * @brief Cria uma nova cidade.
 * 
 * @return tCidade Ponteiro para a cidade criada.
 */
tCidade CriaCidade(){
    tCidade cidade;
    cidade = (tCidade)malloc(sizeof(struct cidade));
    
    cidade->possivelDano = 0;
    cidade->dano = 0;
    cidade->qtdMisseis = 0;
    cidade->qtdDefesas = 0;

    cidade->defesas =  (tDefesa*)malloc(sizeof(tDefesa)*QTD_DEF);
    cidade->misseis = (tMissil*)malloc(sizeof(tMissil)*QTD_MIS);
    
    return cidade;
}

/**
 * @brief Lê a entrada do usuário e preenche a cidade com as informações lidas.
 * 
 * @param cidade Ponteiro para a cidade que será preenchida.
 * @return tCidade Ponteiro para a cidade preenchida.
 */
tCidade LeEntrada(tCidade cidade){
    int x = 0, y  = 0;
    char op = 'a';

   cidade->possivelDano = 0;
   cidade->dano = 0;
   cidade->qtdMisseis = 0;
   cidade->qtdDefesas = 0;

    scanf("C %f %f\n", &cidade->x, &cidade->y);

    
    while(1){
        scanf("%*[^MFD]");
        scanf("%c", &op);

        if(op == ENCERRAR){
            break;
        }
        else if(op == MISSIL){
            cidade->misseis[cidade->qtdMisseis] = LeMissil();
            cidade->qtdMisseis++;         
        }
        else if(op == DEFESA){
            cidade->defesas[cidade->qtdDefesas] = LeDefesa();
            cidade->qtdDefesas++;
        }
    }
    cidade->possivelDano = RetornaPossivelDano(cidade->misseis, cidade->qtdMisseis);

    return cidade;
}

/**
 * @brief Imprime as informações da cidade.
 * 
 * @param cidade Ponteiro para a cidade que será impressa.
 */
void ImprimeCidade(tCidade cidade){

}

/**
 * @brief Libera a memória alocada para a cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void LiberaCidade(tCidade cidade){
    if(cidade){
        int i = 0;
        if(cidade->defesas){
            for(i = 0; i < cidade->qtdDefesas; i++){
                if(cidade->defesas[i]){
                    LiberaDefesa(cidade->defesas[i]);
                }
                
            }
            free(cidade->defesas);
        }
        if(cidade->misseis){
            for(i = 0; i < cidade->qtdMisseis; i++){
                if(cidade->misseis[i]){
                    LiberaMissil(cidade->misseis[i]);
                }
            }
            free(cidade->misseis);
        }

        free(cidade);
    }

}

/**
 * @brief Processa os ataques na cidade.
 * 
 * @param cidade Ponteiro para a cidade que será atacada.
 */
void ProcessaAtaques(tCidade cidade){
    int i = 0, j = 0;
    
    int caso = -1;

    for(i = 0 ; i < cidade->qtdMisseis; i ++){
        for(j = 0; j < cidade->qtdDefesas; j++){

            caso = VerificaSeraMissilNeutralizado(cidade->defesas[j], cidade->misseis[i]);

            if(caso == NEUTRO){
                UsaDefesa(cidade->defesas[j]);
                cidade->dano += GetMissilPoder(cidade->misseis[i]);

                ReduzPoder(cidade->misseis[i],GetMissilPoder(cidade->misseis[i]));
                
            }else if(caso == PARCIAL_NEUTRO){
                float valor;
                UsaDefesa(cidade->defesas[j]);
                cidade->dano += GetDefesaPoder(cidade->defesas[j]);
                ReduzPoder(cidade->misseis[i], GetDefesaPoder(cidade->defesas[j])); 
                
            }
            else if(caso == ATIVO){
                if(cidade->x >= GetMissilX(cidade->misseis[i]) && cidade->y >= GetMissilY(cidade->misseis[i])){
                  //  cidade.
                }
                
            }
            
        }
    }
}


/**
 * @brief Imprime os dados finais da cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void ImprimeDados(tCidade cidade){
    int i = 0;

    for(i = 0; i < cidade->qtdDefesas; i++){
        ImprimeDefesa(cidade->defesas[i]);
    }
    
    for(i = 0; i < cidade->qtdMisseis;i++){
        ImprimeMissil(cidade->misseis[i]);
    }

    float efetividade = 0;

    efetividade = (cidade->dano/cidade->possivelDano)*100;
    printf("Efetividade: %.2f%%", efetividade);

    
}

