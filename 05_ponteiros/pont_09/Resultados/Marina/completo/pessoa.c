#include "pessoa.h"
#include <stdio.h>


/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0]= '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa){
    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", pessoa->nome);
    //scanf("%*[^a-zA-Z]");
    return;
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->mae || pessoa->pai){
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa){

    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n",pessoa->nome);

        if(pessoa->pai != 0){
            printf("PAI: %s\n", pessoa->pai);
        }
        else {
            printf("PAI: NAO INFORMADO\n");
        }

        if(pessoa->mae != 0){
            printf("MAE: %s\n", pessoa->mae);
            
        }
        else{
            printf("MAE: NAO INFORMADO\n");
        }
        printf("\n");
    }
        
    
    
   
    return;
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int qtd = 0, i = 0, idxMae = 0, idxPai = 0, idxFilho = 0;
    scanf("%*[^0-9-]");
    scanf("%d", &qtd);
   // printf("%d", qtd);

    for(i = 0; i < qtd; i++){
        //printf("passei aqui");
        scanf("%*[^0-9-]");
        scanf("%d", &idxMae);
        scanf("%*[^0-9-]");
        scanf("%d", &idxPai);
        scanf("%*[^0-9-]");
        scanf("%d", &idxFilho);
        if(idxMae != -1){
            pessoas[idxFilho].mae = &pessoas[idxMae];
        }
        if(idxPai != -1){
            pessoas[idxFilho].pai = &pessoas[idxPai];
        }
        
    }
}

