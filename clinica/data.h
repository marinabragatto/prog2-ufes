#ifndef data_h
#define data_h

typedef struct{
    int dia;
    int ano;
    int mes;
}tData;

void imprimeData(tData data);
tData leData();
int retornaIdade(tData data);


#endif