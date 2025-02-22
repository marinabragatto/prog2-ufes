#include <stdio.h>
#include "tela.h"
#include "botao.h"

void acionaSalvar();
void acionaOpcoes();
void acionaExcluir();

int main(){

    Tela t;
    int i = 0;

    t = CriarTela(200,400);

    RegistraBotaoTela(&t, CriarBotao("Salvar", 12, "FFF", CLICK, acionaSalvar ));
    RegistraBotaoTela(&t, CriarBotao("Excluir", 18, "000", CLICK, acionaExcluir));
    RegistraBotaoTela(&t, CriarBotao("Opcoes", 10, "FF0000", LONGO_CLICK, acionaOpcoes));

    DesenhaTela(t);
    OuvidorEventosTela(t);
    
    return 0;
}
void acionaSalvar(){
    printf("- Botao de SALVAR dados ativado!\n");
}
void acionaOpcoes(){
    printf("- Botao de OPCOES ativado!\n");
}
void acionaExcluir(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

