#include <stdio.h>

int analisaRepeticao(int livros[], int repetidos[], int qtd);
void inicializaRepetidos(int repetidos[]);
int existeRepeticao(int repetidos[], int size, int valor);
int valorEstaNoVetor(int repetidos[], int size, int valor);
void adionaRep(int repetidos[], int valor);
void leLivros(int livros[], int qtd);
void imprimeVetor(int repetidos[], int qtdRep);
void ordenaVetor(int repetidos[], int qtdRep);

int main(){
    int livros[1000], qtd = 0, repetidos[1000], qtdRep = 0;
    scanf("%d", &qtd);

    leLivros(livros, qtd);
    
    inicializaRepetidos(repetidos);
    
    qtdRep = analisaRepeticao(livros, repetidos, qtd);
    
    ordenaVetor(repetidos, qtdRep);
    if(qtdRep != 0){
        imprimeVetor(repetidos, qtdRep);
    }
    else{
        printf("NENHUM");
    }
    
    return 0;
}

void ordenaVetor(int repetidos[], int qtdRep){
    int j = 0, i = 0, menor = 0, aux = 0, idxMenor = 0;

    for(i = 0; i < qtdRep - 1 ; i++){
        menor = repetidos[i+1];
        idxMenor = i+1;
        for(j = i+2; j < qtdRep; j++){
            if(repetidos[j] < menor){
                menor = repetidos[j];
                idxMenor = j;
            }
        }
        if(menor < repetidos[i]){
            aux = repetidos[i];
            repetidos[i] = menor;
            repetidos[idxMenor] = aux;
        }
    }
    return;
    
}

void imprimeVetor(int repetidos[], int qtdRep){
    int i = 0;
    for (i = 0; i < qtdRep; i++){
        if(i == qtdRep-1){
            printf("%d", repetidos[i]);
        }
        else {
            printf("%d ", repetidos[i]);
        }
        
    }
    
    return;
}

void leLivros(int livros[], int qtd){
    int i = 0;
    for(i = 0; i < qtd; i++){
        scanf("%d", &livros[i]);
    }
    return;
}

void adionaRep(int repetidos[], int valor){
    int i = 0;
    if(!(valorEstaNoVetor(repetidos, 1000, valor))){
        for(i = 0; i < 1000; i++){
            if(repetidos[i] == -1){
                repetidos[i] = valor;
                return;
            }
        }
    }
    return;
}

int valorEstaNoVetor(int repetidos[], int size, int valor){
    int i = 0, contadorRep = 0;
    for(i = 0; i < size; i++){
        if(valor == repetidos[i]){
             return 1;
        }
    }
    return 0;

}

int existeRepeticao(int repetidos[], int size, int valor){
    int i = 0, contadorRep = 0;

    for(i = 0; i < size; i++){
        if(valor == repetidos[i]){
            contadorRep++;  
        }
        if(contadorRep >= 2){
            return 1;
        }   
    }
    return 0;
}

void inicializaRepetidos(int repetidos[]){
    int i = 0;
    for(i = 0; i < 1000; i++){
        repetidos[i] = -1;
    }
    return;
}

int analisaRepeticao(int livros[], int repetidos[], int qtd){
    int i = 0, total = 0;

    for(i = 0; i < qtd; i++){
        if(!(existeRepeticao(livros, qtd, livros[i]))){
            if(!(valorEstaNoVetor(repetidos, 1000, livros[i]))){
                adionaRep(repetidos, livros[i]);
                total++;
            }
        }
    }
    return total;
}

