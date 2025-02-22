#include "botao.h"
#include <string.h>

void converteParaMai(char * texto);

//#define MAX_TAM_TEXTO 30 
//#define CLICK 1 
//#define LONGO_CLICK 2 
//#define HOVER 3

//typedef struct {
    //char texto[MAX_TAM_TEXTO];
    //int tamFonte;
    //char corHex[7];
    //int tipo;
  //  void (*executa)(void); // ponteiro para função que irá executar um evento quando o botão for clicado
//} Botao;

/**
 * @brief Define o texto exibido no botão especificado se o novo texto for menor do que o tamanho máximo permitido.
 * se o novo texto for maior do que o tamanho máximo permitido, o programa é encerrado.
 * 
 * @param b Ponteiro para o botão que terá o texto definido.
 * @param novoTexto Novo texto a ser exibido no botão.
 */
void SetarTexto(Botao *b, char *novoTexto){
    if(strlen(novoTexto) < MAX_TAM_TEXTO){
        strcpy(b->texto, novoTexto);
    }
    else{
        printf("!!!tamanho maior q o permitido!!!\n");
        exit(1);
    }
    
}

/**
 * @brief Define o tamanho da fonte do texto exibido no botão especificado se o novo tamanho for maior do que zero.
 * se o novo tamanho for menor ou igual a zero, o programa é encerrado.
 * 
 * @param b Ponteiro para o botão que terá o tamanho da fonte definido.
 * @param novoTamFonte Novo tamanho da fonte a ser definido.
 */
void SetarTamFonte(Botao *b, int novoTamFonte){
    b->tamFonte = novoTamFonte;
    return;
}

/**
 * @brief Define a cor do botão especificado.
 * 
 * @param b Ponteiro para o botão que terá a cor definida.
 * @param novaCor Nova cor a ser definida em formato hexadecimal.
 */
void SetarCor(Botao *b, char *novaCor){
    strcpy(b->corHex, novaCor);
    return;    
}

/**
 * @brief Define o tipo de evento que o botão especificado pode receber se o novo tipo for válido.
 * 
 * @param b Ponteiro para o botão que terá o tipo de evento definido.
 * @param novoTipo Novo tipo de evento a ser definido.
 */
void SetarTipo(Botao *b, int novoTipo){
    b->tipo = novoTipo;
    return;
}
/**
 * @brief Cria um novo botão com as características especificadas.
 * 
 * @param texto Texto a ser exibido no botão.
 * @param tamFonte Tamanho da fonte do texto exibido no botão.
 * @param cor Cor do botão em formato hexadecimal.
 * @param tipo Tipo de evento que o botão pode receber.
 * @param executa Função que será executada quando o botão for clicado.
 * @return Botao Retorna o botão criado.
 */
Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)){
    Botao b;

    SetarCor(&b, cor);
    SetarTamFonte(&b, tamFonte);
    SetarTexto(&b, texto);
    SetarTipo(&b, tipo);
    b.executa = executa;
    return b;
}

/**
 * @brief Executa a função associada ao botão especificado de acordo com o tipo de evento que o botão pode receber.
 * Se o tipo de evento for inválido, o programa é encerrado.
 * 
 * @param b Botão que terá sua função executada.
 */
void ExecutaBotao(Botao b){
    if(b.tipo == 1){
        printf("- Executando o botao com evento de click\n");
        //- Botao de SALVAR dados ativado!);
    }
    else if(b.tipo == 2){
        printf("- Executando o botao com evento de longo click\n");
        //printf("-------------\n- Botao [%d]:\n(Excluir ", idx);
    } else if(b.tipo  == 3){
        printf("- Executando o botao com evento de longo hoover\n");
        //printf("-------------\n- Botao [%d]:\n(Opcoes ", idx);
    }

    /*
    converteParaMai(b.texto);
    if(!strcmp("OPCOES", b.texto)){
         printf("- Botao de %s ativado!\n", b.texto);
    }
    else{
        printf("- Botao de %s dados ativado!\n", b.texto);
    }
    */
    
//#define CLICK 1 
//#define LONGO_CLICK 2 
//#define HOVER 3
   b.executa();
    return;
}

/**
 * @brief Desenha o botão especificado na posição especificada na tela.
 * 
 * @param b Botão a ser desenhado.
 * @param idx Índice do botão na tela em que será desenhado.
 */
void DesenhaBotao(Botao b, int idx){
    if(idx == 0){
        printf("-------------\n- Botao [%d]:\n(Salvar ", idx);
    }
    else if(idx == 1){
        printf("-------------\n- Botao [%d]:\n(Excluir ", idx);
    } else if(idx  == 2){
        printf("-------------\n- Botao [%d]:\n(Opcoes ", idx);
    }
    
    printf("| %s | %d | %d)\n-------------\n", b.corHex, b.tamFonte, b.tipo);
    return;
}

void converteParaMai(char * texto){
    int i = 0;
    for(i = 0; texto[i]; i++){

        if(texto[i] >= 'A' && texto[i] <= 'Z'){
            continue;
        }
        else if(texto[i] >= 'a' && texto[i] <= 'z'){
            texto[i] -= 32;
        }
        //toupper(texto[i]) 
    }

}