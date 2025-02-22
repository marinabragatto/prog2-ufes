#include "esfera_utils.h"

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param volume Um ponteiro para uma variável float para armazenar o volume calculado.
 */
void CalculaVolume (float R, float *volume){
    *volume = (R*R*R*PI*4)/3;
    return;
}

/**
 * @brief Calcula a área de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param area Um ponteiro para uma variável float para armazenar a área calculada.
 */
void CalculaArea (float R, float *area){
    *area = (R*R*PI*4);
    return;
}