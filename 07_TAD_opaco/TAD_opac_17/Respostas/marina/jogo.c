#include "jogo.h"

struct Jogo {
    int max, min;
    int numeroAdivinha;
    int mc;
};

int retornaFibonacciDeIdx(int idx){
    int ultimo = 1, penultimo = 1;
    int count = 1, numero = 0;
    
    for(count = 1; 1;){
        numero = ultimo + penultimo;
        penultimo = ultimo;
        ultimo =  numero;
        
        if(ehPrimo(numero)){
            if(count == idx){
                return numero;
            }
            else {
                count++;
            }
        }     
    
    }

}

int ehPrimo(int numero){
    if (numero < 2) return 0;

    int i = 0;
    for(i = 2; i < numero; i++){
        if(numero%i == 0){
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Cria uma variável do tipo jogo
 * 
 * @return Uma variável do tipo jogo inicializada.
 */
tJogo* CriaJogo(){
    tJogo *jogo;

    jogo = (tJogo*)malloc(sizeof(tJogo));
    
    if(!jogo){
        printf("erro na alocacao\n");
        exit(1);
    }
    
    return jogo;
}

/**
 * @brief Libera toda a memória alocada para um jogo.
 * 
 * @param jogo - A variável do tipo jogo que será liberada.
 */
void DestroiJogo(tJogo* jogo){
    if(jogo){
        free(jogo);
    }
}

/**
 * @brief Define o valor máximo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param max - o valor máximo do intervalo do jogo.
 */
void DefineMaximo(tJogo* jogo, int max){
    jogo->max = max;
}

/**
 * @brief Define o valor mínimo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param min - o valor mínimo do intervalo do jogo.
 */
void DefineMinimo(tJogo* jogo, int min){
    jogo->min = min;
}

/**
 * @brief Calcula o número a ser adivinhado pelo jogador
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaValorASerAdivinhado(tJogo *jogo, int n){
    int r, fib = 0, x  = 0;
    fib = retornaFibonacciDeIdx(n);

    r = fib%101;

    x = ((float)r/100)*(jogo->max - jogo->min);

    x += jogo->min;
    
    jogo->numeroAdivinha =  x;
}

/**
 * @brief Calcula o número de tentativas que o usuário irá ter para acertar o número. 
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaNumeroTentativas(tJogo *jogo){
    int mc;
    mc  = (log2 (jogo->max-jogo->min+1)) + 1;
    //printf("\n\n\n\n\ %d\n\n\n\n", mc);

    jogo->mc = mc;
// mc = parte_inteira 
}

/**
 * @brief Executa o jogo. Calcula o que for necessário e lê as tentativas, fazendo as devidas verificações.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados.
 * @return int 1 se o usuário venceu o jogo ou 0 caso contrário
 */
int ProcessaTentativas(tJogo* jogo){
   int opa;
   int i = 0;
   printf("\nVoce tem direito a %d tentativas\n", jogo->mc);

    for(i = 0; i < jogo->mc;i++){

        printf("Tentativa %d:\n",i+1);
        scanf("%*[^0-9-]");
        scanf("%d", &opa);
        
        if(opa > jogo->numeroAdivinha){
            printf("Alta\n");
        }
        if (opa < jogo->numeroAdivinha){
            printf("Baixa\n");
        }
        if(opa == jogo->numeroAdivinha){
            printf("Parabens, voce ganhou!");
            return 1;
        }
    }
    printf("Voce perdeu! O numero escolhido foi %d", jogo->numeroAdivinha);
    return 0;
}