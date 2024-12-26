#include <stdio.h>

int main(){
    char palavra[4];
    scanf("%3[^\n]", palavra);
    //scanf("%s");
    printf("(%s)\n",palavra);

    return 0;
}