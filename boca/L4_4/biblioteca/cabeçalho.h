#ifndef _tPONTO_
#define _tPONTO_


typedef struct{
    int x;
    int y;
}tPonto;

tPonto inicializaPonto(tPonto ponto, int x, int y);

tPonto inicializaPontoEntrada(tPonto ponto);

void imprimePonto(tPonto ponto);

tPonto alteraAbscissa(tPonto ponto, int xNovo);

tPonto alteraOrdenada(tPonto ponto, int yNovo);

int retornaAbscissa(tPonto ponto);

int retornaOrdenada(tPonto ponto);

tPonto movimentaPonto(tPonto ponto, int deltaX, int deltaY);

float distanciaDoisPontos(tPonto p1, tPonto p2);

int retornaQuadrante(tPonto ponto);

tPonto retornaSimetrico(tPonto ponto);

#endif