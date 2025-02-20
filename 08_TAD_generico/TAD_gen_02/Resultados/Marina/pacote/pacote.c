#include "pacote.h"

//typedef enum {
//    INT = 1,
//    CHAR = 2
//} Type;

struct pacote {
    void * mensagem;
    int tamanho;
    Type type;
    int soma;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote * pacote;
    pacote = (tPacote*)malloc(sizeof(tPacote));

    if(type == INT){
        pacote->mensagem = (int*)malloc(sizeof(int)*(numElem));
    }
    else if(type == CHAR){  
        pacote->mensagem = (char*)malloc(sizeof(char)*(numElem+1));
        ((char*)pacote->mensagem)[numElem] = '\0';
        
    }
    pacote->tamanho = numElem;
    pacote->type = type;
    pacote->soma = 0;

    return pacote;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    if(pac){
        if(pac->mensagem){
            free(pac->mensagem);
        }

        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    int i = 0;

    printf("\nDigite o conteúdo do vetor/mensagem: ");
    if(pac->type == CHAR){
        scanf("%*[^a-zA-Z]");
        for(i = 0; i < pac->tamanho; i++){
            scanf("%[^\n]", ((char*)pac->mensagem));
        }
        scanf("%*[\n]");
    }
    else if (pac->type == INT){
        for(i = 0; i < pac->tamanho; i++){
            scanf("%d", &((int*)pac->mensagem)[i]);

        }
    }

}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    
    CalculaSomaVerificacaoPacote(pac);

    if(pac->type == CHAR){
        printf("%d %s\n", pac->soma, ((char*)pac->mensagem));

    }
    if(pac->type == INT){
            int i = 0;
            printf("%d ", pac->soma);
            for(i = 0; i < pac->tamanho; i++){
                if(i != pac->tamanho -1){
                    printf("%d ", ((int*)pac->mensagem)[i]);
                }
                else{
                    printf("%d ", ((int*)pac->mensagem)[i]);
                }
                
            }
            printf("\n");
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    int i = 0;

    for(i = 0; i < pac->tamanho; i++){
        if(pac->type == CHAR){
            pac->soma += ((char*)pac->mensagem)[i];
        }
        else if(pac->type == INT){
            pac->soma += ((int*)pac->mensagem)[i];
        }
    }
    
}