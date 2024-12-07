
#ifndef _DATA_H
#define _DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

Data lerData();
void printData(Data d);

#endif