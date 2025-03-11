#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_contato.h"
#include "vector.h"

struct ListaContato {
    Vector * contatos;
    int jainiciou;
};

int BuscaTelefone(unsigned long int num, Vector * contatos){
    int i = 0;
    int qtd = 0;

    qtd=VectorSize(contatos);
    

    for(i = 0; i < qtd; i++){
        tContato * analisados;
        analisados = VectorGet(contatos, i);
        if(num == GetTelefoneContato(analisados)){
            //ImprimirContato(contato);
            return i;
        }
    }
    return -1;
}

int BuscaContatoNomeOuTelefone(tContato * buscado, Vector * contatos){
    int i = 0;
    int qtd = 0;

    qtd=VectorSize(contatos);
    

    for(i = 0; i < qtd; i++){
        tContato * analisados;
        analisados = VectorGet(contatos, i);
        if(GetTelefoneContato(buscado) == GetTelefoneContato(analisados)){
            //ImprimirContato(contato);
            return i;
        }
        if(strcmp(GetNomeContato(buscado), GetNomeContato(analisados)) ==0 ){
            return i;
        }
    }
    return -1;
}
/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato(){
    tListaContato * lista;
    lista = (tListaContato*)malloc(sizeof(tListaContato));
    lista->contatos = VectorConstruct();
    lista->jainiciou = 2217;
    return lista;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l){
    if(l){
        if(l->contatos){
            VectorDestroy(l->contatos, DestruirContato);
        }
        free(l);
    }
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato){
//    Ja existe um contato com esse nome e/ou numero de telefone
    if(BuscaContatoNomeOuTelefone(contato, l->contatos) != -1){
        printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
        DestruirContato(contato);
    }
    else{
        VectorPushBack(l->contatos, contato);
    }
    
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo){
    FILE * arquivo;

    arquivo = fopen(nomeArquivo, "rb");
    if(arquivo==NULL){
        return;
    }
    
    int qtd;
    fread(&qtd, sizeof(int), 1, arquivo);

    int i = 0;

    for(i = 0; i < qtd; i++){
        tContato * contato;
        //memset(contato, 0, sizeof(cont))
        contato = CarregarContato(arquivo);
        AdicionarContatoListaContato(l, contato);
        //VectorPushBack(l->contatos, contato);
    }
    
    fclose(arquivo);
}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo){
    FILE * arquivo;

    arquivo=fopen(nomeArquivo, "wb");
    if(arquivo==NULL){
        return;
    }
    
    int qtd;
    qtd = VectorSize(l->contatos);
    //printf("aquiii(%d)", qtd);

    fwrite(&qtd, sizeof(int), 1, arquivo);
    int i = 0;
    for(i = 0; i < qtd; i++){
        tContato * contato;
        contato = VectorGet(l->contatos, i);
        SalvarContato(contato,arquivo);
    }
    
    fclose(arquivo);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l){
    int i = 0;
    int qtd = 0;
    qtd=VectorSize(l->contatos);
    unsigned long int num;
    scanf("%lu", &num);
    int achou = 0;
    for(i = 0; i < qtd; i++){
        tContato * contato;
        contato = VectorGet(l->contatos, i);
        if(GetTelefoneContato(contato) == num){
            ImprimirContato(contato);
            achou =1;
        }
    }
    if(achou == 0){
        printf("\nContato nao encontrado\n");
    }
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l){
    int i = 0;
    int qtd = 0;
    qtd=VectorSize(l->contatos);
    char nome[100];
    scanf("%s\n", nome);
    int achou =0;
    for(i = 0; i < qtd; i++){
        tContato * contato;
        contato = VectorGet(l->contatos, i);
        if(strcmp(GetNomeContato(contato), nome) ==0 ){
            ImprimirContato(contato);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("\nContato nao encontrado\n");
    }
}


/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l){
    int i = 0;
    int qtd = 0;
    qtd = VectorSize(l->contatos);
    printf("\nLista de contatos cadastrados\n");
    for(i = 0; i < qtd; i++){
        tContato *contato;
        contato = VectorGet(l->contatos, i);
        ImprimirContato(contato);
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l){
    unsigned long int num=0;
    scanf("%d\n", &num);
    int idx;
    idx = BuscaTelefone(num, l->contatos);
    
    if(idx != -1){
        DestruirContato(VectorGet(l->contatos,idx));
        VectorRemove(l->contatos, idx);

        
        printf("\nContato removido com sucesso\n");
    }
    else{
        printf("\nNao existe um contato cadastrado com esse numero de telefone\n");
    }
}