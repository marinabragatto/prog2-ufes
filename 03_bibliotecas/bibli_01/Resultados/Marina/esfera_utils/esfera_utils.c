#include <stdio.h>
#include <math.h>
#include "esfera_utils.h"


float calcula_volume (float R){
    float volume = 0;
    volume = (PI*4*pow(R,3))/3;
    return volume;
}

float calcula_area (float R){
    float area = 0;
    area = PI*4*pow(R,2);
    return area;
}

