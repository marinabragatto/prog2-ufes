#include <stdio.h>
#include "tData.h"

tData leData(){
    tData data;
    scanf("%d %d %d", &data.day, &data.month, &data.year);

    data = normalizaData(data);
    return data;
}

tData normalizaData(tData data){
    //corrige o mes
    if(data.month > 12){
        data.month = 12;
    }
    else if(data.month <= 0){
        data.month = 1;
    }
    //corrige o caso do mes de fevereiro, que possui o problema de 29 ou 28 dias
    if(ehBissexto(data.year)){
        if(data.month == 2){
            if(data.day > 29){
                data.day = 29;
            }
        }
    }
    else {
        if(data.month == 2){
            if(data.day > 28){
                data.day = 28;
            }
        }
    }

    if(data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 ||  data.month == 12){
        if(data.day > 31){
            data.day = 31;
        }
    }
    else {
        if(data.day > 30 && data.month != 2){
            data.day = 30;
        }
    }
    return data;
}

int ehBissexto(int year){
    if(year%4 == 0){
        if(year%100 == 0){
            if(year%400 == 0){
                return 1;
            }
            else {
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

void imprimeIntervalo(tData inicio, tData fim){
    tData data;
    data = inicio;
    imprimeData(data);
    data = avancaData(data);

    while(!(ehIgual(data, fim))){
        imprimeData(data);
        data = avancaData(data);
    }

}

tData avancaData(tData data){

    if(data.month == 12){
        if(data.day == 31){
            data.month = 1;
            data.day = 1;
            data.year++;
        }
        else {
            data.day++;
        }
        
    }
    else if(data.month == 2){
        if(ehBissexto(data.year)){
            if(data.day == 29){
                data.day = 1;
                data.month++;
            }
            else{
                data.day++;
            }
            
        }
        else {
            if(data.day == 28){
                data.day = 1;
                data.month++;
            }
            else{
                data.day++;
            }
        }
    }
    else if(data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10){
        if(data.day == 31){
            data.day = 1;
            data.month++;
        }
        else{
            data.day++;
        }
    }
    else {
        if(data.day == 30){
            data.day = 1;
            data.month++;
        }
        else{
            data.day++;
        }
    }

    return data;
}

int ehIgual(tData data, tData fim){
    if(data.day == fim.day && data.month == fim.month && data.year == fim.year){
        return 1;
    }
    else{
        return 0;
    }

}

void imprimeData(tData data){
    if(ehBissexto(data.year)){
        printf("'%02d/%02d/%02d':Bisexto\n", data.day, data.month, data.year);
    }
    else {
        printf("'%02d/%02d/%02d':Normal\n", data.day, data.month, data.year);
    }
    
}