#include <stdio.h>

int main(){
    char word[1000];
    scanf("%*[^1-9]");
    scanf("%s", word);
    printf("\n(%s)\n", word);
    return 0;

}