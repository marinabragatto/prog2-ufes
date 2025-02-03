#include "biblioteca.h"

int main(){
    int qtd = 0, operacao = 0; 

    scanf("%d\n", &qtd);
    
    tBiblioteca *biblioteca;
    biblioteca = InicializarBiblioteca();

    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    
    int i = 0;
    for(i = 0; i < qtd; i++){
       // printf("\n");
        scanf("%*[^0-9]");
        scanf("%d\n", &operacao);
        if(operacao == 1){
            tLivros *livro;      
            livro = CriaLivro();
            LerLivro(livro);
            AdicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if(operacao == 2){
            char nome[100];
            scanf("%s\n", nome);
            //printf("\n%s\n!!!");
            RemoverLivroDaBiblioteca(biblioteca, nome);
        }
        else if (operacao == 3){
            ListarLivrosDaBiblioteca(biblioteca);
        }
        else{
            printf("Operacao invalida!\n");
            break;
        }
        
    }

    ApagaBiblioteca(biblioteca);

    return 0;
}