#ifndef _TDATA_
#define _TDATA_

typedef struct {
    int day;
    int month;
    int year;
}tData;

tData leData();
tData normalizaData(tData data);
int ehBissexto(int year);
void imprimeIntervalo(tData inicio, tData fim);
int ehIgual(tData data, tData fim);
void imprimeData(tData data);
tData avancaData(tData data);

#endif
