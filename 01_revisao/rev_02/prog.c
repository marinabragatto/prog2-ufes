#include <stdio.h>
#include <math.h>
int main(){
    int size = 0, j = 0, i = 0, num = 1;

    scanf("%d", &size);
    for(i = 1, num = 1; i <= size; i++){
        for(j = 1; j <= i; j++, num++){
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}

