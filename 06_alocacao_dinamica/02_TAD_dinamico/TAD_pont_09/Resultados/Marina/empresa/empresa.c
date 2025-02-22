#include "empresa.h"
#include <stdlib.h>


//typedef struct empresa {
//    int id;
//    tFuncionario** funcionarios; //Ponteiro duplo pois será um vetor (alocado dinamicamente) para ponteiros de Funcionarios
//    int qtdFuncionarios;
//} tEmpresa;

/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa(){
    tEmpresa *empresa;

    empresa = (tEmpresa*)malloc(sizeof(tEmpresa));
    empresa->id = -1;
    empresa->qtdFuncionarios = -1;
    empresa->funcionarios = NULL;

    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa){
    int i  = 0, qtdFuncionarios;
    scanf("%d %d", &empresa->id, &qtdFuncionarios);
    
    tFuncionario *funcionarios[qtdFuncionarios];
    empresa->qtdFuncionarios =  0;
    for(i = 0; i < qtdFuncionarios;i++){
        funcionarios[i] = CriaFuncionario();
        LeFuncionario(funcionarios[i]);
    }

    for(i = 0; i < qtdFuncionarios; i++){
        ContrataFuncionarioEmpresa(empresa, funcionarios[i]);
    }
    return;
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa){
    int i = 0;

    if(empresa){
        if(empresa->funcionarios){
            for(i = 0; i < empresa->qtdFuncionarios;i++){
                if(empresa->funcionarios[i]){
                    free(empresa->funcionarios[i]);
                }
                else{
                    printf("tentou liberar vetor nulo\n");
                    exit(1);
                }
            }
            free(empresa->funcionarios);
        }
        else{
            printf("tentou liberar vetor nulo\n");
            exit(1);
        }
        free(empresa);
    }
    else {
        printf("tentou liberar vetor nulo\n");
        exit(1);
    }
}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
    int i = 0;

    for(i = 0; i < empresa->qtdFuncionarios; i++){
        if(GetIdFuncionario(empresa->funcionarios[i]) == funcionario->id){
            i = -1;
            break;
        }
    }
    if(i != -1){
        empresa->funcionarios = (tFuncionario**)realloc( empresa->funcionarios, sizeof(tFuncionario*)*(empresa->qtdFuncionarios+1));
        empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
        empresa->qtdFuncionarios++;
    }
    else {
        printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, funcionario->id);
        ApagaFuncionario(funcionario);
    }
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa){
    int i = 0;
    printf("Empresa %d:\n", empresa->id);
    for(i = 0; i < empresa->qtdFuncionarios; i++){
        ImprimeFuncionario(empresa->funcionarios[i]);
    }
}