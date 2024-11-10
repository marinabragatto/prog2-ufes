#include <stdio.h>
#include "string_utils.h"

int main(){
    int size = 0;
    char word[1000];
    scanf("%999[^\n]", word);
    size = string_length(word);
    printf("%d", size);
    return 0;
}