#include "biblioteca.h"
#include <string.h>

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca(){
    tBiblioteca *biblioteca;
    biblioteca = (tBiblioteca*)malloc(sizeof(tBiblioteca));
    biblioteca->tamanho = 0;
    int i = 0;


    for(i = 0; i < MAX_LIVROS; i++){
        biblioteca->livros[i] = NULL;
    }

    return biblioteca;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca){
    int i = 0;
    if(biblioteca){
        for(i = 0; i < biblioteca->tamanho; i++){
            if(biblioteca->livros[i]){
                ApagaLivro(biblioteca->livros[i]);
            }   
        }  
        free(biblioteca);
    }
    else{
        printf("tentou liberar vetor nulo\n");
    }
}
/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){
    if(biblioteca->tamanho < 10){
        (biblioteca->livros[biblioteca->tamanho]) = livro;
        biblioteca->tamanho++;
        printf("Livro adicionado com sucesso!\n");
    }
    else{
       printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n"); 
        ApagaLivro(livro);
    }

}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){
    int i = 0, j = 0, aux = - 1;
    for(i = 0; i < biblioteca->tamanho; i++){
        if(VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo) == 0){
            aux = 2;
            break;
        }
    }
    if(aux != -1){
        ApagaLivro(biblioteca->livros[i]);
        for(j = i; j < biblioteca->tamanho - 1; j++){
                biblioteca->livros[j] = biblioteca->livros[j+1];
        }
        biblioteca->tamanho--;
        printf("Livro removido com sucesso!\n");
    }
    else{
        printf("Livro nao encontrado na biblioteca.\n");
    }

}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
    return strcmp(livro->titulo, titulo);
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
    int i = 0;
    if(biblioteca->tamanho > 0){
        printf("\nLista de Livros na Biblioteca:\n");
            for(i = 0; i < biblioteca->tamanho; i++){
                ImprimeLivro(biblioteca->livros[i]); 
            }
    }
    else{
        printf("A biblioteca esta vazia!\n");
    }
}