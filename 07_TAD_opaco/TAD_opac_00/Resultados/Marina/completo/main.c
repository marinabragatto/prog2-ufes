#include "circulo.h"

int main(){
    float xC, xP, yC, yP, r;
    scanf("%f %f %f %f %f", &xC, &yC, &r, &xP, &yP);
    
    tCirculo circulo;
    circulo = Circulo_Cria(xC, yC, r);

    tPonto pontoAnalisado;
    pontoAnalisado = Pto_Cria(xP, yP);

    if(Circulo_Interior(circulo, pontoAnalisado)){
        printf("1");
    }
    else {
        printf("0");
    }

    Pto_Apaga(pontoAnalisado);
    Circulo_Apaga(circulo);


    return 0;
}