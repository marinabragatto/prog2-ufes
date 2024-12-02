#include "data.h"
#include <string.h> 

/*
typedef struct Data {
    int dia;
    int mes;
    int ano; 
} tData;*/

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano){
    tData data;
    data.mes = mes;
    data.ano = ano; 
    data.dia = dia;
    return data;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data){
    // Verifica mês e ano válidos
    if (data.mes < 1 || data.mes > 12 || data.dia < 1) {
        return 0;
    }

    
    // Verifica se o dia é válido para o mês correspondente
    int diaMes = 0;

    diaMes = NumeroDiasMes(data);

    if (data.dia > diaMes) {
        return 0;
    }

    return 1; // Data válida
}


/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data){
    // Array com os nomes dos meses
    char meses[12][10] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    // Imprime a data no formato desejado
    printf("%s", meses[data.mes - 1]);
    return;    
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data){
    char mes[10];
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
    return;
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data){
    /*
    if(data.ano % 4 == 0){
        if(data.ano % 100 == 0){
            if(data.ano % 400 == 0){
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }*/

    return (data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0));

}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data){
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (data.mes == 2 && VerificaBissexto(data)) {
        diasNoMes[1] = 29;
    }

    return diasNoMes[data.mes-1];
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2){
    // Compara os anos
    if (data1.ano != data2.ano) {
        return (data1.ano > data2.ano) ? 1 : -1;
    }

    // Compara os meses (se os anos forem iguais)
    if (data1.mes != data2.mes) {
        return (data1.mes > data2.mes) ? 1 : -1;
    }

    // Compara os dias (se os meses e anos forem iguais)
    if (data1.dia != data2.dia) {
        return (data1.dia > data2.dia) ? 1 : -1;
    }

    // Se tudo for igual, retorna 0
    return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data){

}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2){
    tData data3;
    data3 = data2;
    int dias = 0;

    if(ComparaData(data1, data3) == 1){
        while(ComparaData(data1, data3)){
            data3.dia++;
            if(!(VerificaDataValida(data3))){
                data3.dia = 1;
                data3.mes++;
            }
            if(!(VerificaDataValida(data3))){
                data3.mes = 1;
                data3.dia = 1;
                data3.ano++;
            }
            dias++;
        }
    }
    else if(ComparaData(data1, data3) == -1){
        while(ComparaData(data1, data3)){
            data1.dia++;
            if(!(VerificaDataValida(data1))){
                data1.dia = 1;
                data1.mes++;
            }
            if(!(VerificaDataValida(data1))){
                data1.mes = 1;
                data1.dia = 1;
                data1.ano++;
            }
            dias++;
        }
    }
    return dias;
}
