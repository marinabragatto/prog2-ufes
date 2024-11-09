#include <stdio.h>
#include "string_utils.h"

int string_length(char *str){
    int i = 0;
    for (i = 0; str[i]; i++);
    printf("(%s)", str);
    printf("\n esse é o tamanho %d\n", i);
    return i + 1;
}

void string_copy(char *src, char *dest){
    int sizeScr = 0, i = 0;
    sizeScr = string_length(src);
    for(i = 0; i <= sizeScr; i++){
        dest[i] = src[i];
    }
    return;
}

void string_upper(char *str){
    int i = 0;
    for(i = 0; str[i]; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
    return;
}

void string_lower(char *str){
    int i = 0;
    for(i = 0; str[i]; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
    return;
}

void string_reverse(char *str){
    int sizeStr = 0, i = 0, j = 0;

    char staticStr[1000];

    sizeStr = string_length(str) - 2;
    
    string_copy(str, staticStr);


    for(i = 0, j = sizeStr - 1; i < sizeStr; i++, j--){
        //if(staticStr[j] == '\n'){
          //  i = i - 1;
        //}
        //else{
            str[i] = staticStr[j];
        //}
        
    }
   // printf("teste 2 = %s\n", str);
    //str[i+1] = '\0';
    return;
}

//if(str[0]){
      //  string_reverse(str+1);
        //printf("%c", str[0]);
   // }
    //else{
        //return;
   // }
    