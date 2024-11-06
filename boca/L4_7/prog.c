#include <stdio.h>
#include <math.h>
#include <tgmath.h>

typedef struct{
    int x;
    int y;
    int quadrante;
}tPonto;

typedef struct{
    tPonto inicio;
    tPonto fim;
    tPonto aux;
}tReta;

tReta leReta();
tPonto lePonto();
int retornaQuadrante(tPonto ponto);
void imprimeDados(tReta reta);
tPonto retornaInverso(tPonto ponto);
float RetornaDistancia(tPonto p1, tPonto p2);

int main(){
    int qtd = 0, i = 0;

    scanf("%d", &qtd);

    tReta retas[qtd];
    

    for(i = 0 ; i < qtd; i++){
        retas[i] = leReta();
        imprimeDados(retas[i]);
    }

    return 0;
}

float RetornaDistancia(tPonto p1, tPonto p2){
    float dis = 0, x = 0, y = 0;
    //printf("%d %d %d %d\n", p1.x, p1.y, p2.x, p2.y);
    x = pow((p1.x - p2.x), 2);
    y = pow((p1.y - p2.y), 2);
    dis = sqrt(x + y);
    
    return dis;
}

void imprimeDados(tReta reta){
    int qIni = 0, qFim = 0;

    qIni = retornaQuadrante(reta.inicio);
    qFim = retornaQuadrante(reta.fim);
    //printf("\n quadrantes %d %d \n \n", qFim, qIni);
    if(qFim == 0 && qIni == 0){
        printf("DIFERENTE\n");
    }
    else if(qFim == qIni){
        printf("MESMO\n");
    }
    else{
        printf("DIFERENTE\n");
    }
   

}

tPonto lePonto(){
    tPonto ponto;
    scanf("%d %d", &ponto.x, &ponto.y);
    //ponto.quadrante = retornaQuadrante(ponto);
    return ponto;
}

tReta leReta(){
    tReta reta;
    reta.inicio = lePonto();
    reta.fim = lePonto();
    return reta;
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

/* (BOCA:L4_6) Problema: Utilizando o tipo tPonto, implemente um tipo de dados 
tReta para representar uma reta no plano cartesiano com coordenadas inteiras. 
Implemente as seguintes funções para o tipo: (a) inicialização da reta a partir de um 
ponto inicial e outro final; (b) inicialização a partir da leitura de dois pontos da 
entrada padrão; (c) apresentação da reta com os pontos iniciais pi e finais pf no 
seguinte formato “[(pi.x,pi.y):(pf.x,pf.y)]”; (d) obtenção do ponto inicial da reta; (e) 
obtenção do ponto final da reta; (f) movimentação da reta; (g) tamanho da reta. Com 
esse tipo, faça um programa que leia pontos e retas e informe se o ponto está mais 
próximo do início ou do fim da reta.   */