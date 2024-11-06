#include <stdio.h>
#define B 66
#define C 67
#define D 68
#define E 69

typedef struct{
    int vet[4];
}tPrioridade;

typedef struct{
    int x;
    int y;
    int flag;
}tPonto;

tPrioridade recebePrioridade();
void leMatriz(int i, int j, int mapa[i][j]);
void imprimeMatriz(int i, int j, int mapa[i][j]);
tPonto lePonto();
void movimentaPersonagem(tPrioridade p, int i, int j, int mapa[i][j], tPonto inicial, tPonto final);
int chegouFim(tPonto atual, tPonto fim);
tPonto atualizaPos(tPrioridade p, int i, int j, int mapa[i][j], tPonto atual);
void imprimePos(tPonto ponto);
void implemantaInicio(int i, int j, int mapa[i][j], tPonto inicio);

int main(){
    int i = 0, j = 0;

    scanf("%d %d", &i, &j);

    int mapa[i][j];
    leMatriz(i, j, mapa);

    tPonto inicial, final;

    inicial = lePonto();
    implemantaInicio(i, j, mapa, inicial);
    final = lePonto();
    tPrioridade p;
    p = recebePrioridade();
    //printf("inicial == %d %d\n\n", inicial.x, inicial.y);

    movimentaPersonagem (p, i, j, mapa, inicial, final);
    
    //imprimeMatriz(i, j, mapa);
    

    return 0;
}

void leMatriz( int i, int j, int mapa[i][j]){
    int l = 0, c = 0;

    for(l = 0; l < i; l++){
        for(c = 0; c < j; c++){
            scanf("%d", &mapa[l][c]); 
        } 
    }
    return;
}

void imprimeMatriz(int i, int j, int mapa[i][j]){
    int l = 0, c = 0;

    for(l = 0; l < i; l++){
        for(c = 0; c < j; c++){
            printf("%d ", mapa[l][c]); 
        }
        printf("\n");
    }
    return;
}

tPonto lePonto(){
    tPonto pt;
    scanf("%d %d", &pt.x, &pt.y);
    pt.x--;
    pt.y--;
    pt.flag = 0;
    return pt;
}

void implemantaInicio(int i, int j, int mapa[i][j], tPonto inicio){
    mapa[inicio.x][inicio.y] = 2;
}

tPrioridade recebePrioridade(){
    tPrioridade p;
    int i = 0;
    char c1 = 'a', c2 = 'a', c3 = 'a', c4 = 'a';

    scanf("%*[^A-Z]");
    
    scanf("%c%c%c%c", &c1, &c2, &c3, &c4);
    p.vet[0] = c1;
    p.vet[1] = c2;
    p.vet[2] = c3;
    p.vet[3] = c4;

   // printf("\n %d %d %d %d\n", p.vet[0], p.vet[1], p.vet[2], p.vet[3]);
    
    return p;
}

void movimentaPersonagem (tPrioridade p, int i, int j, int mapa[i][j], tPonto inicial, tPonto final){
    tPonto posAtual;
    posAtual = inicial;
    imprimePos(posAtual);
   // printf("\n\nfinal === %d %d\n\n", final.x, final.y);

    while(1){
        posAtual = atualizaPos(p, i, j, mapa, posAtual);
        if(posAtual.flag != 1){
            imprimePos(posAtual);
        }
        if(chegouFim(posAtual, final) || posAtual.flag == 1){
            break;
        }
        
    }

}

tPonto atualizaPos(tPrioridade p, int i, int j, int mapa[i][j], tPonto atual){
    int l = 0;

    for(l = 0; l < 4; l++){
        if(p.vet[l] == D && atual.y != j - 1){
            if(mapa[atual.x][atual.y + 1] != 1 && mapa[atual.x][atual.y + 1] != 2){
                atual.y = atual.y + 1;
                mapa[atual.x][atual.y] = 2;
                return atual;
            }
        }
        if (p.vet[l] == E && atual.y != 0){
            if(mapa[atual.x][atual.y - 1] != 1 && mapa[atual.x][atual.y - 1] != 2){
                atual.y = atual.y - 1;
                mapa[atual.x][atual.y] = 2;
                return atual;
            }
        }
        if (p.vet[l] == C &&  atual.x != 0){
            if(mapa[atual.x - 1][atual.y] != 1 && mapa[atual.x - 1][atual.y] != 2){
                atual.x = atual.x - 1;
                mapa[atual.x][atual.y] = 2;
                return atual;
            }
        }
        if (p.vet[l] == B &&  atual.x != i - 1){
            if(mapa[atual.x + 1][atual.y] != 1 && mapa[atual.x + 1][atual.y] != 2){
                atual.x = atual.x + 1;
                mapa[atual.x][atual.y] = 2; 
                return atual;
            }
        }
    }
    atual.flag = 1;
    return atual;
}

int chegouFim(tPonto atual, tPonto fim){
    if(atual.x == fim.x && atual.y == fim.y){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimePos(tPonto ponto){
    printf("(%d,%d) ", ponto.x + 1, ponto.y + 1);
}