#include <stdio.h>
#include "agendatarefas.h"

#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "tarefaimprime.h"



int main(){
    int qtd;
    printf("Digite o numero de tarefas: ");
    scanf("%d\n", &qtd);
    int i = 0, prioridades  = 0;

    char tipo;

    tAgendaTarefas * agenda;
    agenda = CriaAgendaDeTarefas(qtd);
    for(i = 0; i < qtd; ){

        scanf("%d %c ", &prioridades, &tipo);
        
        if(tipo == 'I'){
            char msg[120];
            scanf("%[^\n]", msg);
            scanf("%*[\n]");
            void * tarefa = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(agenda, prioridades, tarefa, ExecutaTarefaImprimir, DestroiTarefaImprimir);
            i++;

        }else if(tipo == 'M'){
            float n1, n2;
            scanf("%*[^0-9-]");
            scanf("%f %f\n", &n1, &n2);
            void * tarefa = CriaTarefaMultiplicar(n1,n2);
            CadastraTarefaNaAgenda(agenda, prioridades, tarefa, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
            i++;

        }else if(tipo == 'S'){
            float n1, n2;
             scanf("%*[^0-9-]");
            scanf("%f %f\n", &n1, &n2);
            void * tarefa = CriaTarefaSoma(n1,n2);
            CadastraTarefaNaAgenda(agenda, prioridades, tarefa, ExecutaTarefaSoma, DestroiTarefaSoma);
            i++;
        }
        else{
            scanf("%*[^\n]");
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
        }

    }
    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}

/*5
3 I Olá Mundo!
5 M 3.14 2.0
1 I Tchau Mundo!
5 S 1 1
2 I Quarta Tarefa a Ser Executada
*/