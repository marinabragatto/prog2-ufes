#include "locadora.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//typedef struct Locadora {
//    tFilme** filme; 
//    int numFilmes; 
//    int lucro; 
//} tLocadora;


int RetornaIdxFilme(tLocadora * locadora, int codigo);
/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora (){
    tLocadora * locadora;
    locadora = (tLocadora*)malloc(sizeof(tLocadora));
    locadora->filme = NULL;
    locadora->numFilmes = 0;
    locadora->lucro = 0;
    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora){
    int i = 0;

    if(locadora){
        for(i = 0; i < locadora->numFilmes; i++){
            if(locadora->filme[i]){
                DestruirFilme(locadora->filme[i]);
            }
        }
        if(locadora->filme){
            free(locadora->filme);
        }
        
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    int i  = 0;
    for(i = 0; i < locadora->numFilmes;i++){
        if(ObterCodigoFilme(locadora->filme[i]) == codigo){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    
    if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))){
        
        locadora->filme = realloc(locadora->filme, sizeof(tFilme*)*(locadora->numFilmes+1));
        locadora->filme[locadora->numFilmes] = CriarFilme(); 
        *(locadora->filme[locadora->numFilmes]) = *filme;
       
        printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora->filme[locadora->numFilmes]));
        ImprimirNomeFilme(locadora->filme[locadora->numFilmes]);
        printf("\n");
        locadora->numFilmes++;
    }
    
    return;
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora){
    tFilme * filme;
    int codigo = 0, ret = 0;
    filme = CriarFilme();

    while(1){
        ret = scanf("%d,", &codigo);
        if(ret != 1){
            break;
        }
        LeFilme(filme,codigo);
        CadastrarFilmeLocadora(Locadora, filme);
    }

    return;
}
/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i = 0, idx = 0;

    for(i=0; i < quantidadeCodigos; i ++){
        if(VerificarFilmeCadastrado(locadora, codigos[i])){
            idx = RetornaIdxFilme(locadora, codigos[i]);
            if(ObterQtdEstoqueFilme(locadora->filme[idx])>0){
                AlugarFilme(locadora->filme[idx]);
            }
          
        }
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora){
    int qtd = 0, i = 0, ret = 0;
    int *codigos;
    
    codigos=(int*)malloc(sizeof(int));

    
    while(1){
        ret = scanf("%d", &codigos[i]);
        if(ret != 1){
            break;
        }
        i++;
        codigos=realloc(codigos, sizeof(int)*(i+1));
    }
    AlugarFilmesLocadora(locadora, codigos, i+1);
    return;
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i = 0, idx = 0;
    for(i = 0; i < quantidadeCodigos; i ++){
        if(VerificarFilmeCadastrado(locadora, codigos[i])){
            idx = RetornaIdxFilme(locadora, codigos[i]);
            if(ObterQtdAlugadaFilme>0){
                DevolverFilme(locadora->filme[idx]);
            }
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora){
    int qtd = 0, i = 0, ret = 0;
    int *codigos;
    
    codigos=(int*)malloc(sizeof(int));

    while(1){
        ret = scanf("%d", &codigos[i]);
        if(ret != 1){
            break;
        }
        i++;
        codigos=realloc(codigos, sizeof(int)*(i+1));
    }
    free(codigos);
    AlugarFilmesLocadora(locadora, codigos, i+1);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora){
    int j = 0, i =0, idxMenor = 0;

    tFilme *filmeMenor;
    filmeMenor = CriarFilme();

    

    for(i = 0; i<locadora->numFilmes-1; i++){
        *filmeMenor = *(locadora->filme[i+1]);
        idxMenor = i+1;
        for(j = i+1; j <locadora->numFilmes; j++){
            if(CompararNomesFilmes(filmeMenor, locadora->filme[j]) > 0){
                *filmeMenor = *(locadora->filme[j]);
                idxMenor = j;
            }
        }
        if(CompararNomesFilmes(locadora->filme[i], locadora->filme[idxMenor])>0){
            tFilme *filmeAux;
            filmeAux = CriarFilme();       
            *(filmeAux) = *(locadora->filme[i]);
            *(locadora->filme[i]) = *(locadora->filme[idxMenor]);
            *(locadora->filme[idxMenor]) = *(filmeAux);
        }
    
    }

}
/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora){
    printf("~ESTOQUE~\n");
    int i = 0;
    for(i = 0; i<locadora->numFilmes;i++){
        if(ObterQtdEstoqueFilme(locadora->filme[i])>0){
            printf("%d - ", ObterCodigoFilme(locadora->filme[i])); 
            ImprimirNomeFilme(locadora->filme[i]);
            printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
        }        
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora){

}

int RetornaIdxFilme(tLocadora * locadora, int codigo){
    int j = 0;
    for(j = 0; j < locadora->numFilmes;j++){
        if(EhMesmoCodigoFilme(locadora->filme[j], codigo)){
            break;
        }
    }
    return j;
}