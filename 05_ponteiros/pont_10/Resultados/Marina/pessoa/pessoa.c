#include "pessoa.h"

//typedef struct Pessoa tPessoa;

//struct Pessoa{
//    char nome[100];
 //   tPessoa *pai;
  //  tPessoa *mae;
   // tPessoa *irmao;
//};

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.irmao = 0;
    pessoa.mae = 0;
    pessoa.pai = 0;
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
    if(pessoa->mae != 0 || pessoa->pai != 0){
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
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai != 0){
            printf("PAI: %s\n", pessoa->pai);
        }
        else{
            printf("PAI: NAO INFORMADO\n");
        }

        if(pessoa->mae != 0){
            printf("MAE: %s\n", pessoa->mae);
        }
        else{
            printf("MAE: NAO INFORMADO\n");
        }

        if(pessoa->irmao != 0){
            printf("IRMAO: %s\n\n", pessoa->irmao);
        }
        else{
            printf("IRMAO: NAO INFORMADO\n\n");
        }
    }
    return;
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai){
        return 1;
    }
    else {
        return 0;
    }
}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
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

    int j = 0;
    
    for(i = 0; i < numPessoas - 1; i++){
        for(j = 0; j < numPessoas; j++){
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) && &pessoas[i] != &pessoas[j]){
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }   
    }

}
