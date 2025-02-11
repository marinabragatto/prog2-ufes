#include <stdio.h>
#include "defesa.h"
#include <math.h>


//#define QUADRADO 'Q' /**< Caractere que indica uma defesa do tipo quadrado. */
//#define CIRCULO 'C' /**< Caractere que indica uma defesa do tipo círculo. */
//#define MAX_TAM 100 /**< Tamanho máximo do nome da defesa. */

/**
 * @brief Estrutura que representa uma defesa.
 * 
 * A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho e o poder de defesa.
 * 
 */
struct defesa {
    char tipo;
    float xCentro, yCentro;
    float tamanho;
    float poder;
    char nome[MAX_TAM];
    int qtd;
};

tDefesa CriaDefesa(){
    tDefesa defesa;
    defesa = (tDefesa)malloc(sizeof(struct defesa));
    
    defesa->nome[0] = '\0';
    defesa->poder = -1;
    defesa->tamanho = -1;
    defesa->tipo = 'n';
    defesa->xCentro = -1;
    defesa->yCentro= -1;
    defesa->qtd = -1;

    return defesa;
}

float CalculaDistanciaEntreP1P2(float x1, float x2, float y1, float y2){
    float somatorio = 0;
    somatorio = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    return sqrt(somatorio);

}

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 * 
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa(){
    tDefesa defesa;
    defesa = CriaDefesa();
    scanf("%[^ ]", defesa->nome);
    scanf(" %f %f %c %f %f %d\n", &defesa->xCentro, &defesa->yCentro, &defesa->tipo, &defesa->tamanho, &defesa->poder, &defesa->qtd);
    
    //D-nome x y tipo tamanho poder quantidade 
    // D2 93.1 69.0 C 28.30 42.6 8
    return defesa;
}

/**
 * @brief Imprime as informações da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa){
    printf("D-%s: %d\n", defesa->nome, defesa->qtd);
}

/**
 * @brief Libera a memória alocada para a defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa){
    if(defesa){
        free(defesa);
    }
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y){
   // if(defesa->tipo == QUADRADO){
        //if(y >= defesa->yCentro - 3 && y <= defesa->yCentro + 3 && x >= defesa->xCentro - 3 && x <= defesa->xCentro + 3){

        //}

        if(defesa->tamanho >= CalculaDistanciaEntreP1P2(defesa->xCentro, x, defesa->yCentro, y)){
            return 1;
        }
        else {
            return 0;
        }
    //}
}

/**
 * @brief Usa a defesa, diminuindo seu poder de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa){
    defesa->qtd--;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa){
    return defesa->poder;
}

/**
 * @brief Verifica se a defesa pode defender.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa){
    if(defesa->qtd > 0){
        return 1;
    }
    return 0;

}