#include <stdio.h>
#include "string_utils.h"

void menu_print();
void execute_op(int op, char *str);


int main(){
    char str[1000];
    int op = 0, size = 0;
    scanf("%[^\n]", str);
    size = string_length(str);
    str[size - 1] = '\n';
    str[size] = '\0';
    //printf("esse é o tamanho %d (%s)", string_length(str)-2, str);


    while(1){
        menu_print();
        scanf("%d", &op);
        if(op == 6){
            break;
        }
        execute_op(op, str);
        printf("\n");
        
    }

    return 0;
}

void menu_print(){
    printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
    return;
}

void execute_op(int op, char *str){
    if(op == 1){
        printf("Tamanho da string: %d\n", string_length(str));
    }
    else if(op == 2){
        char dest[1000];
        string_copy(str, dest);
        printf("String copiada: %s\n", dest);
    }
    else if(op == 3){
        string_upper(str);
        printf("String convertida para maiusculas: %s\n", str);
    }
    else if(op == 4){
        string_lower(str);
        printf("String convertida para minusculas: %s\n", str);
    }
    else if(op == 5){
        string_reverse(str);
        printf("String invertida: %s\n", str);
    }
    return;
}