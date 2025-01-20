#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main(){
    tJogo *jogo;
    
    while(1){
        //free(jogo);
        jogo = CriaJogo();
        ComecaJogo(jogo);
        if(ContinuaJogo()){
            DestroiJogo(jogo);
            continue;
        }
        else{
            DestroiJogo(jogo);
            break;
        }
    }
        
    
}