#include "ponto.h"
#include <stdio.h>
#include <math.h>

int main(){
    Ponto p1, p2;
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    p1 = pto_cria(x1, y1);
    p2 = pto_cria(x2, y2);
    float distancia = 0;
    distancia = pto_distancia(p1, p2);
    printf("%g", distancia);
    return 0;
}
