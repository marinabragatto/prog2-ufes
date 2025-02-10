#include "jogo.h"

int main(){
    
    while(1){
        tJogo * jogo;
        jogo = CriaJogo();
        ComecaJogo(jogo);
        if(ContinuaJogo()){
            DestroiJogo(jogo);
        }
        else{
            DestroiJogo(jogo);
            break;
        }
    }
    

    return 0;
}