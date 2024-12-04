#include "livro.h"
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"


/**
 * Inicializa uma biblioteca vazia.
 *
 * @return A biblioteca inicializada.
 */
tBiblioteca inicializarBiblioteca(){
    tBiblioteca biblioteca;
    biblioteca.tamanho = 0;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    if(biblioteca.tamanho < MAX_LIVROS){
        biblioteca.livros[biblioteca.tamanho] = livro;
        printf("Livro adicionado com sucesso!\n");
        biblioteca.tamanho++;
    }else {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }
    return biblioteca;
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    int i = 0, livroEstaNaBiblioteca = 0, j = 0;;

    for(i = 0; i < biblioteca.tamanho; i++){
        livroEstaNaBiblioteca = verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo);
        if(livroEstaNaBiblioteca){
            break;
        }
    }
    

    if(livroEstaNaBiblioteca == 1){
        for(j = i; j < biblioteca.tamanho - 1; j++){
            biblioteca.livros[j] = biblioteca.livros[j+1];
        }
        printf("Livro removido com sucesso!\n");
        biblioteca.tamanho--;
    }
    else {
        printf("Livro nao encontrado na biblioteca.\n");
    }

    return biblioteca;
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return (strcmp(titulo, livro.titulo) == 0) ? 1 : 0;
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca A biblioteca cujos livros serão listados.
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    int i = 0;
    if(biblioteca.tamanho == 0){
        printf("A biblioteca esta vazia!\n");
    }
    else {
        printf("\nLista de Livros na Biblioteca:\n");
        for(i = 0; i < biblioteca.tamanho; i++){
            imprimeLivro(biblioteca.livros[i]);
        }
    }

    
    return;
}

