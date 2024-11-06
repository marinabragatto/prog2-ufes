#include <stdio.h>
#include <math.h>
#include <tgmath.h>

int verificaAcerto(float xA, float yA, float rA, float xD, float yD, float rD){
    float cateto1 = 0, cateto2 = 0, hipotenusa = 0;

    cateto1 = xA - xD;
    cateto2 = yA - yD;

    if(cateto1 < 0){
        cateto1 = -cateto1;
    }
    if(cateto2 < 0){
        cateto2 = -cateto2;
    }
    hipotenusa = (cateto1*cateto1) + (cateto2*cateto2);
    hipotenusa = sqrt(hipotenusa);
   // printf("\n%f\n", hipotenusa);

    if(hipotenusa <= rA + rD){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    float xA= 0, yA = 0, rA = 0, xD= 0, yD = 0, rD = 0, res = 0;

    scanf("%f %f %f", &xA, &yA, &rA);
    scanf("%f %f %f", &xD, &yD, &rD);

    res = verificaAcerto(xA, yA, rA, xD, yD, rD);
    if(res == 1){
        printf("ACERTOU");
    }
    else{
        printf("ERROU");
    }

    return 0;
}