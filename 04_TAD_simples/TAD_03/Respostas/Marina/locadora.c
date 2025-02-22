#include "locadora.h"
#include <string.h>
#include <stdio.h>
#include "filme.h"

int buscaMenor(tFilme filmes[], int inicio, int fim);
void deslocaVetor(tFilme filmes[], int idxMenor, int i);
int buscaFilmeCodigo(tLocadora locadora, int codigo);

tLocadora criarLocadora (){
    //printf("passei aqui1");
    tLocadora locadora;
    locadora.lucro = 0;
    locadora.numFilmes = 0;
    char acao[100];
    
    scanf("%[a-zA-Z]", acao);
    
    locadora = lerCadastroLocadora(locadora);
    
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i = 0, sim = 0;
    
    for (i = 0; i < locadora.numFilmes; i++){
        if(locadora.filme[i].codigo == codigo){
            sim = 1;
            break;
        }
    }

    if(sim == 1){
        return 1;
    }
    else {
        return 0;
    }
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    //printf("passei aqui3");
    int codigo = 0;

    codigo = obterCodigoFilme(filme);
    //printf("\nnumero filmes%d\n", locadora.numFilmes);
    if(!verificarFilmeCadastrado (locadora, codigo)){
        locadora.filme[locadora.numFilmes] = filme;
        printf("Filme cadastrado %d - ", locadora.filme[locadora.numFilmes].codigo);
        imprimirNomeFilme(locadora.filme[locadora.numFilmes]);
        printf("\n");
        locadora.numFilmes++;
    }
    else {
        printf("Filme ja cadastrado no estoque\n");
    }

   
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora){
    //printf("passei aqui4");
    int i = 0, codigo = 0, ret = 0;
    

    tFilme filme;
    
    while(1){
        ret = scanf("%d,", &codigo);
        if(ret == 0 || ret == -1){
            break;
        }
        filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora (locadora, filme);
    }
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i = 0, idxFilme = 0, valor = 0, aluguel_efetivado = 0, lucro = 0;

    for(i = 0; i < quantidadeCodigos; i++){
        idxFilme = buscaFilmeCodigo(locadora, codigos[i]);
        if(idxFilme == -1){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
            continue;
        }
        if(locadora.filme[idxFilme].qtdEstoque > 0){
            locadora.filme[idxFilme] = alugarFilme(locadora.filme[idxFilme]);
            valor = obterValorFilme(locadora.filme[idxFilme]);
            lucro += valor;
            aluguel_efetivado++;
        }
        else {
            printf("Filme %d - ", codigos[i]);
            imprimirNomeFilme(locadora.filme[idxFilme]);
            printf(" nao disponivel no estoque. Volte mais tarde.\n");
        }
        
    }
    if(aluguel_efetivado > 0){
        printf("Total de filmes alugados: %d com custo de R$%d\n", aluguel_efetivado, lucro);
    }
    
    
    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora){
    int codigos[100], ret = 0, qtd = 0, cod = 0;

    while(1){
        ret = scanf("%d", &cod);
        if(ret == 0 || ret == -1){
            break;
        }
        codigos[qtd] = cod;
        qtd++;
    }

    locadora =  alugarFilmesLocadora (locadora, codigos, qtd);
    
    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i = 0, idxFilme = 0, valor = 0, lucro = 0, cod = 0;
    for(i = 0; i < quantidadeCodigos; i++){
        idxFilme = buscaFilmeCodigo(locadora, codigos[i]);
        if(idxFilme == -1){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
            continue;
        }
        if(locadora.filme[idxFilme].qtdAlugada > 0){
            locadora.filme[idxFilme] = devolverFilme(locadora.filme[idxFilme]);
            valor = obterValorFilme(locadora.filme[idxFilme]);
            lucro += valor;
            cod = obterCodigoFilme(locadora.filme[idxFilme]);
            printf("Filme %d - ", cod);
            imprimirNomeFilme(locadora.filme[idxFilme]);
            printf(" Devolvido!\n");
        }
        else {
            printf("Nao e possivel devolver o filme %d - ", codigos[i]);
            imprimirNomeFilme(locadora.filme[idxFilme]);
            printf(".\n");
    
        }
        
    }      
    locadora.lucro += lucro;
    return locadora;  
}

tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int codigo = 0, idxFilme = 0, i = 0, qtd = 0, ret = 0;
    int codigos[100];

    while(1){
        ret = scanf("%d\n", &codigo);
        if(ret == 0 || ret == -1){
            break;
        }
        codigos[qtd] = codigo;
        qtd++;
       
    }
    locadora = devolverFilmesLocadora(locadora, codigos, qtd);

    
    return locadora;
}

tLocadora ordenarFilmesLocadora(tLocadora locadora){
    //printf("passei aqui9");
    int i = 0, idxMenor = 0;
    // vc começa no idx 0 e busca o menor e compara esse menor com o pos 0

    for(i = 0; i < locadora.numFilmes - 1; i++){
        idxMenor = buscaMenor(locadora.filme, i + 1, locadora.numFilmes);
        if(strcmp(locadora.filme[i].nome, locadora.filme[idxMenor].nome) > 0){
            deslocaVetor(locadora.filme, idxMenor, i);
        }
    }
    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora){
    locadora = ordenarFilmesLocadora(locadora);
    printf("~ESTOQUE~\n");
    int i = 0, fitas = 0, cod = 0;
    for(i = 0; i < locadora.numFilmes; i++){
        cod = obterCodigoFilme(locadora.filme[i]);
        printf("%d - ", cod);
        imprimirNomeFilme(locadora.filme[i]);
        fitas = obterQtdEstoqueFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", fitas);
    }
    return;
}

void consultarLucroLocadora(tLocadora locadora){
    if(locadora.lucro != 0){
        printf("\nLucro total R$%d\n",locadora.lucro);
    }
    
    return;
}

int buscaMenor(tFilme filmes[], int inicio, int fim){
    int i = inicio;
    char menor[20];

    strcpy(menor, filmes[i].nome);
    int idxMenor = inicio;

    for(i = inicio + 1; i < fim; i++){
        if(strcmp(menor, filmes[i].nome) > 0){
            strcpy(menor, filmes[i].nome);
            idxMenor = i;
        }
    }
    return idxMenor;
}

void deslocaVetor(tFilme filmes[], int idxMenor, int i){
    tFilme filmeAux;
    filmeAux = filmes[i];
    filmes[i] = filmes[idxMenor];
    filmes[idxMenor] = filmeAux;
    return;
}

int buscaFilmeCodigo(tLocadora locadora, int codigo){
    int i = 0, idxCod = -1;

    for (i = 0 ; i < locadora.numFilmes; i++){
        if(ehMesmoCodigoFilme (locadora.filme[i], codigo)){
            idxCod = i;
            break;
        }
    }
    
    return idxCod;
}