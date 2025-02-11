#include "missil.h"

//#define MAX_TAM 100 /**< Tamanho máximo do nome do míssil. */

/**
 * @brief Estrutura que representa um míssil.
 * 
 * A estrutura tMissil contém o nome do míssil, as coordenadas x e y, e o poder de ataque.
 * 
 */


struct missil{
    char nome[MAX_TAM];
    float x, y;
    float poder;
};

tMissil CriaMissil(){
    tMissil missil;
    missil = (tMissil)malloc(sizeof(struct missil));
    
    missil->x = -1;
    missil->y = -1;
    missil->poder = -1;

    return missil;
}
/**
 * @brief Lê a entrada do usuário e cria um novo míssil.
 * 
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissil LeMissil(){
    
    tMissil missil;
    missil = CriaMissil();

    scanf("%[^ ]", missil->nome);
    scanf(" %f %f %f\n", &missil->x, &missil->y, &missil->poder);
    return missil;

}

/**
 * @brief Imprime as informações do míssil.
 * 
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil missil){
    
        printf("M-%s: %.2f\n", missil->nome, missil->poder);
    
    
    
}
/**
 * @brief Libera a memória alocada para o míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil missil){
    if(missil){
        free(missil);
    }
}
/**
 * @brief Obtém a coordenada y do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float GetMissilY(tMissil missil){
    return missil->y;
}
/**
 * @brief Obtém a coordenada x do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float GetMissilX(tMissil missil){

    return missil->x;

}
/**
 * @brief Obtém o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float GetMissilPoder(tMissil missil){

    return missil->poder;

}
/**
 * @brief Reduz o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil missil, float valor){
    
    if(valor >= missil->poder){
        missil->poder = 0;
    }
    else if(valor < missil->poder){
        missil->poder -= valor; 
    }



}