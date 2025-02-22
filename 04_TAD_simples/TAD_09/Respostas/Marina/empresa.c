#include "funcionario.h"
#include "empresa.h"



tEmpresa criaEmpresa(int id){
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;
    return empresa;

}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    int id = 0;
    int funcionarios = 0;
    scanf("%d", &id);
    tEmpresa empresa;
    int qtd  = 0;
    empresa = criaEmpresa(id);
    scanf("%d", &qtd);
    int i = 0;
    
    tFuncionario f; 

    for(i = 0; i < qtd; i++){
        f = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, f);
    }
    return empresa;
}
/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){

    if(!estaContratado(funcionario.id, empresa)){
        
        
        empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
        empresa.qtdFuncionarios++;
    }
    
    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){
    printf("Empresa %d:\n", empresa.id);
    int i = 0, idComparado = 0;

    for(i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    return;
}

int estaContratado(int id, tEmpresa empresa){
    int i = 0, idComparado = 0;

    for(i = 0; i < empresa.qtdFuncionarios; i++){
        idComparado = getIdFuncionario(empresa.funcionarios[i]);
        if(idComparado == id){
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, id);
            return 1;
        }
    }
    return 0;
}