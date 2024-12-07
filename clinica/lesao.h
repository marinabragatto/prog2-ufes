#ifndef lesao_h
#define lesao_h


typedef struct {
    char diagnostico[101];
    char regiaoCorpo[101];
    int porcentagemMalignidade;
    char idetificadorUnico[11];
}tLesao;

tLesao leLesao();
void imprimeLesao(tLesao lesao);
int lesaoPossuiEsseID(tLesao lesao , char identificadorUnico[]);
int retornaQtdLesoesCirurgicas(tLesao lesoes[], int qtd);
int ehCirurgica(tLesao lesao);

#endif