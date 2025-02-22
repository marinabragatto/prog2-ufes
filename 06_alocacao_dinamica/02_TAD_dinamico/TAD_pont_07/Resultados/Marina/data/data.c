#include "data.h"


/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData(){
    tData *data;

    data = (tData*)malloc(sizeof(tData));
    data->ano = -1;
    data->dia = -1;
    data->mes = -1;

    return data;
}
/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data){
    scanf("%d/%d/%d\n",&data->dia, &data->mes, &data->ano);
}
/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data){
    if(data){
        free(data);
    }
    else{
        printf("tentou liberar vetor jah nulo!\n");
        exit(1);
    }
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data){
    if(!data){
        return 0;
    }
    if(NumeroDiasMes(data) < data->dia || data->dia <= 0 || data->mes > 12  || data->mes <= 0 || data->ano == 0){
        return 0;
    }
    else {
        return 1;
    }
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data){
    char nomesExtenso[12][12] = {"Janeiro" , "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    printf("%s",nomesExtenso[data->mes - 1]);
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data){
    //28 de Janeiro de 2002
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
    return;
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data){
    return ((data->ano%4 == 0) && (data->ano%100 != 0 || data->ano%400 == 0));
        
   // return : ?
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data){
    if(data->mes == 13){
        return 0;
    }
    int dias[12] = {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    if(VerificaBissexto(data)){
        dias[1]++;
    }
    int mesIdx = data->mes-1;
    return dias[mesIdx];
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2){
    //printf("oi");
    if(data1->ano > data2->ano){
        return 1;
    }
    else if(data1->ano < data2->ano){
        return -1;
    }
    else if(data1->ano == data2->ano){
        if(data1->mes > data2->mes){
            return 1;
        }
        else if(data1->mes < data2->mes){
            return -1;
        }
        else if(data1->mes == data2->mes){
            if(data1->dia > data2->dia){
                return 1;
            }
            else if(data1->dia < data2->dia){
                return -1;
            }
            else if(data1->dia == data2->dia){
                return 0;
            }
        }
    }
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data){
   int dias = 0;

    tData *dataAux;
    dataAux = CriaData();


    dataAux->mes = 1;
    dataAux->ano = data->ano;
    dataAux->dia = 1;

    while(dataAux->mes < data->mes){
        dias += NumeroDiasMes(dataAux);
        dataAux->mes++;
    }    
  

    LiberaData(dataAux);

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2){
    int dias = 0;

    tData *dataAux;
    dataAux = CriaData();

    tData *dataFim;
    dataFim = CriaData();
    
    
    if(ComparaData(data1, data2) == 1){
        *(dataFim) = *(data1);
        *(dataAux) = *(data2);
    }
    else if (ComparaData(data1, data2) == -1){
        *(dataFim) = *(data2);
        *(dataAux) = *(data1); 
    }
    else{
        LiberaData(dataAux);
        LiberaData(dataFim);
        return 0;
    }

    while(1){
        dataAux->dia++;
        if(VerificaDataValida(dataAux)){
            if(ComparaData(dataFim, dataAux) == 0){
                dias++;
                break;
            }
            dias++;
        }
        else {
            dataAux->mes++;
            dataAux->dia = 1;
            if(VerificaDataValida(dataAux)){
                if(ComparaData(dataFim, dataAux) == 0){
                    dias++;
                    break;
                }
                dias++;
            }
            else{
                dataAux->mes = 1;
                dataAux->ano++;
                dataAux->dia = 1;
                if(VerificaDataValida(dataAux)){
                    if(ComparaData(dataFim, dataAux) == 0){
                        dias++;
                        break;
                    }
                    dias++;
                }
            }
        }

    }


    LiberaData(dataAux);
    LiberaData(dataFim);

    return dias;
}

