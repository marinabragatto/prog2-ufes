#include "filme.h"
#include <string.h>
#include <stdio.h>


tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme filme;
    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    return filme;
}

/**
 * @brief Lê um filme.
 * @param codigo Código do filme.
 * @return Filme lido.
*/
tFilme leFilme(int codigo){
    int valor = 0, fitas = 0;
    char nome[20];
 
    scanf("%*[^a-zA-Z]");
    scanf("%[^,]", nome);
    scanf("%*[,]");
    scanf("%d",&valor);
    scanf("%*[,]");
    scanf("%d", &fitas);
    
    tFilme filme;

    filme = criarFilme(nome,codigo,valor,fitas);

    return filme;
}

int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}


void imprimirNomeFilme(tFilme filme){
    printf("%s", filme.nome);
    return;
}


int obterValorFilme (tFilme filme){
    return filme.valor;
}


int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}


int ehMesmoCodigoFilme (tFilme filme, int codigo){
    if(filme.codigo == codigo){
        return 1;
    }
    else {
        return 0;
    }
}


tFilme alugarFilme (tFilme filme){
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}
 
tFilme devolverFilme(tFilme filme){
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

/**
 * @brief Compara os nomes de dois filmes.
 * @param filme1 Primeiro filme a ser comparado.
 * @param filme2 Segundo filme a ser comparado.
 * @return 0 se os nomes são iguais, um valor negativo se o nome do primeiro filme é menor que o do segundo, um valor positivo caso contrário.
 */

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    if(strcmp(filme1.nome, filme2.nome) == 0){
        return 0;
    }
    else if(strcmp(filme1.nome, filme2.nome) < 0){
        return -1;
    }
    else {
        return 1;
    }
}

