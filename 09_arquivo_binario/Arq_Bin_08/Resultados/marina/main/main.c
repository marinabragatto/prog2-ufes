#include <stdio.h>
#include "lista_contato.h"
#include "vector.h"

int main(){
    char nomeArq[40];

    scanf("%s\n", nomeArq);


    
    

    int op = 0;
    tListaContato * lista;
    lista = CriarListaContato();
    CarregarListaContato(lista,nomeArq);

    while(1){
        printf("1 - Cadastrar contato\n2 - Remover contato\n3 - Realizar busca\n4 - Exibir todos os contatos\n0 - Sair da lista de contatos\n");
        

        scanf("%d\n", &op);
        if(op == 0){
            printf("Opcao escolhida: \n");
            break;
        }
        else if(op == 1){
            printf("Opcao escolhida: \n");
            tContato * contato;
            contato = LeContato();
            AdicionarContatoListaContato(lista, contato);
        }
        else if(op == 2){
            printf("Opcao escolhida: \n");
            RemoverContatoListaContato(lista);
        }
        else if(op == 3){
            int qtd = 0;
            printf("Opcao escolhida: \n");
            printf("\n1 - Buscar pelo nome\n2 - Buscar pelo numero de telefone\n");
            scanf("%d\n", &qtd);
            printf("Opcao escolhida: \n");
            if(qtd== 1){
                BuscarPorNomeListaContato(lista);
            }
            else if(qtd == 2){
                
                BuscarPorNumeroTelefoneListaContato(lista);
            }
            
            
        }
        else if(op == 4){
           printf("Opcao escolhida: \n");
            ImprimirListaContato(lista);
        }
    }
    char caminho2[40];
    scanf("%s", caminho2);
    SalvarListaContato(lista, caminho2);
    

    DestruirListaContato(lista);
    /*
    
1 - Cadastrar contato
2 - Remover contato
3 - Realizar busca
4 - Exibir todos os contatos
0 - Sair da lista de contatos
Opcao escolhida: 
    */
    
    return 0;
}