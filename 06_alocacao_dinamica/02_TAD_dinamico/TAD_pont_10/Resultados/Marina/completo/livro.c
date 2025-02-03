#include "livro.h"

#define TAM_MIN 5

char *LeString(char* string);
char *AumentaTamanhoString(char * string, int * tamanho);
// Estrutura que representa um livro
//typedef struct {
//    char* titulo; // Título do livro
 //   char* autor;   // Autor do livro
  //  int anoPublicacao; // Ano de publicação do livro
//} tLivros;

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro(){
    tLivros *livro;
    livro = (tLivros*)malloc(sizeof(tLivros));
    livro->anoPublicacao = -1;
    livro->autor = NULL;
    livro->titulo = NULL;
    return livro;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro){
    scanf("%*[^a-zA-Z]");
    livro->titulo = LeString(livro->titulo);
    livro->autor =  LeString(livro->autor);

    scanf("%d", &livro->anoPublicacao);
    return;
    

}
/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro){
    printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\n", livro->titulo, livro->autor, livro->anoPublicacao);
    return;
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro){
    if(livro){
        if(livro->autor){
            free(livro->autor);
        }
        if(livro->titulo){
            free(livro->titulo);
        }
        free(livro);
    }
}

char * LeString(char* string){
    char letraAtual;
    int idx = 0, tamanho = 0;

    while(1){
        scanf("%c", &letraAtual);
        if(letraAtual == '\n'){
            string[idx] = '\0';
            break;
        }
        else{
            if(idx >= tamanho || idx == 0){
                string = AumentaTamanhoString(string,&tamanho);
            }
            string[idx] = letraAtual;
            idx++;
        }
    }
    return string;
}

char *AumentaTamanhoString(char * string, int * tamanho){
    int length = (*tamanho) + 1 + TAM_MIN;
    string = (char*)realloc(string, sizeof(char)*(length));
    (*tamanho) = *tamanho + TAM_MIN;
    string[*tamanho] = '\0';
    return string;
}