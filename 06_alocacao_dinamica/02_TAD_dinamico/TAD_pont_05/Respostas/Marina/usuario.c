#include "usuario.h"


//typedef struct Usuario {
 //   char nome[50]; /**< Nome do usuário. */
   // char cpf[15]; /**< CPF do usuário. */
//} tUsuario;

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario(){
    tUsuario *user;
    
    user = (tUsuario*)malloc(sizeof(tUsuario));
    if(!user){
        exit(1);
    }
    return user;
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user){
    if(user){
        free(user);
    }
    else{
        printf("tentou liberar um ponteiro tUsario jah nulo!\n");
        exit(1);
    }
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user){
    scanf("%*[^a-zA-Z]");
    scanf("%49s ", user->nome);
    scanf("%14s", user->cpf);
    return;
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\nCPF: %s\n", user->nome, user->cpf);
    return;
    //henrique 222444444 1 
}

