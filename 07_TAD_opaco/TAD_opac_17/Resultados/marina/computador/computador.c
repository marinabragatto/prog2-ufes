#include "computador.h"

struct Computador{
    int ganhou;
    int jogou;
    tJogo * jogo;
}; 

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tComputador
 * 
 * @return A variável do tipo Computador inicializada.
 */
tComputador* CriaComputador(){
    tComputador * comp;
    comp = (tComputador*)malloc(sizeof(tComputador));
    comp->ganhou = comp->jogou = 0;
    return comp;
}

/**
 * @brief Libera toda a memória alocada para uma variável do tipo computador.
 * 
 * @param comp - A variável do tipo Computador que terá sua memória liberada
 */
void DestroiComputador(tComputador* comp){
    if(comp){
        if(comp->jogo){
            DestroiJogo(comp->jogo);
        }
        free(comp);

    }
}

/**
 * @brief Função que gerencia o jogo. Recebe os dados da entrada padrão, os processa e "lida" com as funções necessárias de jogo.
 * 
 * @param computador - Variável computador que salvará o "log" das jogadas, para mostrar o relatório final (apresentado no roteiro)
 */
void GerenciaJogo(tComputador *computador){
    int n = 0, in = 0, fim = 0;
    printf("Jogo de adivinhação");
    while(1){

        while (1) {
            printf("Forneca um numero no intervalo entre 1 e 10000: \n");
            scanf("%d", &n);
            //printf("\n%d\n",n);
            if(n >= 1 && n <= 10000){
                break;
            }
        }
        
        computador->jogo = CriaJogo();
        
        

        
        while (1){
            printf("Forneca um intervalo de numeros naturais: ");
            scanf("%d %d\n", &in, &fim);
            
            if(1){
                break;
            }

        }
        
      //  printf("%d %d\n", in, fim);
        DefineMaximo(computador->jogo, fim);
        DefineMinimo(computador->jogo, in);
        CalculaNumeroTentativas(computador->jogo);
        CalculaValorASerAdivinhado(computador->jogo, n);
        //printf("%d");
        if(ProcessaTentativas(computador->jogo) == 1){
            computador->ganhou++;
            computador->jogou++;
        }
        else{
            computador->jogou++;
        }
        printf("\nDeseja continuar a jogar (s/n): \n");
        DestroiJogo(computador->jogo);
        break;
        
    }
    
}

/**
 * @brief Imprime o relatório "da rodada", mostrado quandoDefine o valor máximo do intervalo que o jogo deve considerar o jogador não deseja jogar novamente, como mostra o roteiro.
 * 
 * @param computador - A variável do tipo computador que terá seus dados apresentados em tela.
 */
void ImprimeRelatorio (tComputador* computador){

}