#include "locadora.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int RetornaValorTotal(tLocadora *locadora,int *codigos, int quantidadeCodigos);
int numeroAlugueis(tLocadora *locadora,int *codigos, int quantidadeCodigos);
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
    for(i = 0; i < locadora->numFilmes; i++){
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
        
        locadora->filme = (tFilme**)realloc(locadora->filme, sizeof(tFilme*)*(locadora->numFilmes+1));
        locadora->filme[locadora->numFilmes] = CriarFilme(); 
        *(locadora->filme[locadora->numFilmes]) = *filme;
       
        printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora->filme[locadora->numFilmes]));
        ImprimirNomeFilme(locadora->filme[locadora->numFilmes]);
        printf("\n");
        locadora->numFilmes++;
    } 
    else{
        printf("Filme ja cadastrado no estoque\n");
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
    DestruirFilme(filme);

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
        if(codigos[i]!= -1){
            idx = RetornaIdxFilme(locadora, codigos[i]);
            if(ObterQtdEstoqueFilme(locadora->filme[idx])>0){
                AlugarFilme(locadora->filme[idx]);
            }
            else{
                printf("Filme %d - ", codigos[i]);
                ImprimirNomeFilme(locadora->filme[idx]);
                printf(" nao disponivel no estoque. Volte mais tarde.\n");
                codigos[i] = -1;
            }

        }
    }
    return;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora){
    int qtd = 0, i = 0, ret = 0, valor = 0;
    int *codigos;
    
    codigos = NULL;


    int codigoAtual = 0;
    
    while(1){
        ret = scanf("%d", &codigoAtual);
        if(ret != 1){
            break;
        }
        else{
            codigos=(int*)realloc(codigos, sizeof(int)*(i+1));
            codigos[i] = codigoAtual;
            i++;
        }
    }
  

    int quantidadeCodigos = i;
    int j = 0, idx = 0;
    int filmesAlugados = 0;
    
    for(j=0; j < quantidadeCodigos; j++){
        if(!VerificarFilmeCadastrado(locadora, codigos[j])){
            printf("Filme %d nao cadastrado.\n", codigos[j]);
            codigos[j] = -1;
        }
    }



    AlugarFilmesLocadora(locadora, codigos, i);
    valor = RetornaValorTotal(locadora, codigos, quantidadeCodigos);
    filmesAlugados = numeroAlugueis(locadora, codigos, quantidadeCodigos);
    //valor = RetornaValorAlugado(locadora, codigos, i);
    free(codigos);
    if(filmesAlugados>0){
        printf("Total de filmes alugados: %d com custo de R$%d\n", filmesAlugados, valor);
    }
    
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
            if(ObterQtdAlugadaFilme(locadora->filme[idx])>0){
                DevolverFilme(locadora->filme[idx]);
                locadora->lucro +=  ObterValorFilme(locadora->filme[idx]);
                printf("Filme %d - ", ObterCodigoFilme(locadora->filme[idx]));
                ImprimirNomeFilme(locadora->filme[idx]);
                printf(" Devolvido!\n");                
            }
            else{
                printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                ImprimirNomeFilme(locadora->filme[idx]);
                printf(".\n");
            }
        }
        else{
            printf("Filme %d nao cadastrado.\n", codigos[i]);
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
    
    codigos=NULL;
    int codigoAtual = 0;
    //(int*)malloc(sizeof(int));

    while(1){
        ret = scanf("%d", &codigoAtual);
        if(ret != 1){
            break;
        }
        else{
            codigos=(int*)realloc(codigos, sizeof(int)*(i+1));
            codigos[i] = codigoAtual;
            i++;
        }
    }
    DevolverFilmesLocadora(locadora, codigos, i);
    free(codigos);
    

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
            DestruirFilme(filmeAux);
        }
    
    }
    DestruirFilme(filmeMenor);

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
        printf("%d - ", ObterCodigoFilme(locadora->filme[i])); 
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }
    //printf("\n");
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora){
    if(locadora->lucro>0){
        printf("Lucro total R$%d\n", locadora->lucro);
    }

    return;
//Total de filmes alugados: 1 com custo de R$5
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

int RetornaValorTotal(tLocadora *locadora,int *codigos, int quantidadeCodigos){
    int i = 0, idx  = 0, valor  = 0;
    for(i = 0; i < quantidadeCodigos;i++){
        if(codigos[i] != -1){
            idx = RetornaIdxFilme(locadora, codigos[i]);
            valor += ObterValorFilme(locadora->filme[idx]);
        }
    }
    return valor;
}
int numeroAlugueis(tLocadora * locadora, int *codigos, int quantidadeCodigos){
    int i = 0, idx  = 0, alugueis = 0;
    for(i = 0; i < quantidadeCodigos;i++){
        if(codigos[i] != -1){
            alugueis++;
        }
    }
    return alugueis;
}