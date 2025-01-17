#include "tDepartamento.h"
#include <stdio.h>

int main(){
    int qtd = 0;
    scanf("%d", &qtd);
    tDepartamento departamentos[qtd];
    char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX]; 
    int m1, m2, m3, i = 0; 

    for(i = 0; i < qtd; i++){
        while(1){
            scanf("%*[^a-zA-Z]");
            scanf("%s", nome);
            scanf("%*[^a-zA-Z]");
            scanf("%s", diretor);
            scanf("%*[^a-zA-Z]");
            scanf("%s", curso1);
            scanf("%*[^a-zA-Z]");
            scanf("%s", curso2);
            scanf("%*[^a-zA-Z]");
            scanf("%s", curso3);
            scanf("%*[^0-9]");
            scanf("%d %d %d", &m1, &m2, &m3);
            if(m1 > 0 || m2 > 0 || m3 > 0){
                break;
            }
            else {
                printf("Digite um departamento com médias válidas\n");
            }
        }
        
        departamentos[i] = CriaDepartamento( &curso1, &curso2, &curso3, &nome, &m1, &m2, &m3, &diretor);
    }
    OrdenaDepartamentosPorMedia(departamentos, qtd);

    for(i = 0; i < qtd; i++){  
        ImprimeAtributosDepartamento(departamentos[i]);

    }
     
    return 0;
}




/* entrada: A entrada começa com uma linha contendo um numero inteiro N
 representando a quantidade de departamentos, seguido dos N departamentos.
 Cada departamento sera representado por um nome, um diretor (Éx: “Luiz”),
 tres nomes de cursos (Éx: “Letras”) e as tres medias de nota de cada curso
 inserido, respectivamente.
  Saída: Éxibir na saída padrao os departamentos ordenados, e, para cada
 departamento, seu nome, seu diretor, os cursos e suas respectivas medias e a
 media de notas dos cursos do departamento.*/