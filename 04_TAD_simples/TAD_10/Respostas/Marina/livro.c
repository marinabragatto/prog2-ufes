#include <stdio.h>
#include "livro.h"

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro(){
    tLivros livros;

    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", livros.titulo);
    scanf("%*[\n]");
    scanf("%[^\n]", livros.autor);
    scanf("%d", &livros.anoPublicacao);
    return livros;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro O livro cujos atributos serão impressos
*/
void imprimeLivro(tLivros livro){
    printf("Titulo: %s\n",livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
    return;
}