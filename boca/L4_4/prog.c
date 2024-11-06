#include <stdio.h>

typedef struct{
    int x;
    int y;
    int quadrante;
}tPonto;

tPonto lePonto();
int retornaQuadrante(tPonto ponto);
void imprimeDados(tPonto ponto);
tPonto retornaInverso(tPonto ponto);

int main(){
    int qtd = 0, i = 0;

    scanf("%d", &qtd);

    tPonto pontos[qtd];

    for(i = 0 ; i < qtd; i++){
        pontos[i] = lePonto();
        imprimeDados(pontos[i]);
    }

    return 0;
}

void imprimeDados(tPonto ponto){
    tPonto inverso;
    inverso = retornaInverso(ponto);

    printf("(%d,%d) %d (%d,%d) %d\n", ponto.x, ponto.y, ponto.quadrante, inverso.x, inverso.y, inverso.quadrante);
}

tPonto lePonto(){
    tPonto ponto;
    scanf("%d %d", &ponto.x, &ponto.y);
    ponto.quadrante = retornaQuadrante(ponto);
    return ponto;
}

int retornaQuadrante(tPonto ponto){
    if(ponto.x == 0 || ponto.y == 0){
        return 0;
    }
    if(ponto.x > 0 && ponto.y > 0){
        return 1;
    }
    else if(ponto.x > 0 && ponto.y < 0){
        return 4;
    }
    else if (ponto.x < 0 && ponto.y > 0){
        return 2;
    }
    else if(ponto.x < 0 && ponto.y < 0){
        return 3;
    }
}

tPonto retornaInverso(tPonto ponto){
    tPonto inverso;
    inverso.x = -ponto.x;
    inverso.y = -ponto.y;
    inverso.quadrante = retornaQuadrante(inverso);
    return inverso;
}

/* Problema: Implemente um tipo de dados tPonto para representar um 
ponto cartesiano com coordenadas inteiras. Implemente as seguintes funções para o 
tipo: (a) inicialização do ponto a partir de um x e um y dados; (b) inicialização de 
ponto com coordenadas lidas da entrada padrão; (c) apresentação das coordenadas 
do ponto na saída padrão com o formato “(x,y)”; (d) alteração da abscissa x do 
ponto; (e) alteração da ordenada y do ponto; (f) obtenção da abscissa x do ponto; (g) 
obtenção da ordenada y do ponto; (h) movimentação do ponto por um delta x e um 
delta y; (i) cálculo da distância entre dois pontos; (j) identificação do quadrante do 
ponto (1, 2, 3 ou 4 para os quadrantes normais e 0 para pontos em cima dos eixos); 
(k) obtenção do ponto simétrico a um ponto. Com esse tipo, faça um programa que 
leia n pontos e informe seu quadrante, seu simétrico e o quadrante do seu simétrico.  */