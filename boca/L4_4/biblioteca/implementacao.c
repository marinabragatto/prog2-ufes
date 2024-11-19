#include "cabeçalho.h"
#include <stdio.h>
#include <math.h>

tPonto inicializaPonto(tPonto ponto, int x, int y){
    ponto.x = x;
    ponto.y = y;
    return ponto;
}

tPonto inicializaPontoEntrada(tPonto ponto){
    scanf("%d %d", &ponto.x, &ponto.y);
    return ponto;
}

void imprimePonto(tPonto ponto){
    printf("(%d,%d)", ponto.x, ponto.y);
    return;
}

tPonto alteraAbscissa(tPonto ponto, int xNovo){
    ponto.x = xNovo;
    return ponto;
}

tPonto alteraOrdenada(tPonto ponto, int yNovo){
    ponto.y = yNovo;
    return ponto;
}

int retornaAbscissa(tPonto ponto){
    return ponto.x;
}

int retornaOrdenada(tPonto ponto){
    return ponto.y;
}

tPonto movimentaPonto(tPonto ponto, int deltaX, int deltaY){
    ponto.x += deltaX;
    ponto.y += deltaY;
    return ponto;
}

float distanciaDoisPontos(tPonto p1, tPonto p2){
    float deltaX = 0, deltaY = 0, res = 0;

    deltaX = pow(p1.x - p2.x, 2);
    deltaY = pow(p1.y - p2.y, 2);
    res = sqrt(deltaX+deltaY);

    return res;
}

int retornaQuadrante(tPonto ponto){
    if(ponto.x == 0 || ponto.y == 0){
        return 0;
    }
    else if(ponto.x > 0 && ponto.y > 0){
        return 1;
    }
    else if(ponto.x > 0 && ponto.y < 0){
        return 4;
    }
    else if(ponto.x < 0 && ponto.y > 0){
        return 2;
    }
    else if(ponto.x < 0 && ponto.y < 0){
        return 3;
    }
}

tPonto retornaSimetrico(tPonto ponto){
    tPonto simetrico;
    simetrico.x = -ponto.x;
    simetrico.y = -ponto.y;
    return simetrico;
}