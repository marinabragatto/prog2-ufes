#include "biblioteca.h"
#include "livro.h"

void imprimeMenu();

int main(){
    int qtdOperacoes = 0, i = 0, operacao = 0;
    scanf("%d", &qtdOperacoes);


    tBiblioteca biblioteca;
    biblioteca = inicializarBiblioteca();
    int z = 1;
    imprimeMenu();
    while(qtdOperacoes){

        if(z != 1){
            printf("\n");
        }

        
        scanf("%d", &operacao);
        if(operacao == 1){
            tLivros livro;
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if(operacao == 2){
            char titulo[100];
            scanf("%*[^a-zA-Z]");
            scanf("%[^\n]", titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
        }
        else if(operacao == 3){
            listarLivrosDaBiblioteca(biblioteca);
        }
        else{
            printf("Operacao invalida!\n");
            break;
        }
        z++;
        qtdOperacoes--;
    }
}

void imprimeMenu(){

    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    return;
}