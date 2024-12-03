#include "funcionario.h"

tFuncionario criaFuncionario(int id, float salario){
    tFuncionario funcionario;
    funcionario.id = id;
    funcionario.salario = salario;
    return funcionario;
}

/**
 * @brief Le os dados de um funcionario da entrada padrao.
 * 
 * @return TFuncionario Funcionario criado a partir dos dados lidos.
 */
tFuncionario leFuncionario(){
    tFuncionario funcionario;
    int id = 0;
    float salario = 0;
    scanf("%d %f", &id, &salario);
    funcionario = criaFuncionario(id, salario);
    return funcionario;
}

int getIdFuncionario(tFuncionario funcionario){
    return funcionario.id;
}

/**
 * @brief Imprime todos os dados de um funcionario.
 * 
 * @param funcionario Funcionario a ser impresso no terminal.
 */
void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n", getIdFuncionario(funcionario), funcionario.salario);
    return;
}

