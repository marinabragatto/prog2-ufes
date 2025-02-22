#include "evento.h"

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){

    scanf("%*[^a-zA-Z0-9]");
    scanf("%s", eventos[*numEventos].nome);
    *(numEventos)++;
    scanf("%d %d %d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    printf("Evento cadastrado com sucesso!\n");

}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){
    printf("Eventos cadastrados:\n");
    int i = 0;
    for(i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    int idx = 0;

    scanf("%d", &idx);
    if(idx >= *numEventos){
        printf("Indice invalido!\n");
    }
    else {
        scanf("%d %d %d", &eventos[idx].dia, &eventos[idx].mes, &eventos[idx].ano);
        printf("Eventos trocados com sucesso!\n");
    }
    

}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    
    if(indiceA < *numEventos && indiceB < *numEventos){
        Evento aux;
        aux = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux;
        printf("Data modificada com sucesso!\n");
    }
    else{
        printf("Indice invalido!\n");
    }
    
}