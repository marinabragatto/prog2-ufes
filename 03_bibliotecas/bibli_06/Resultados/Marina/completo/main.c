#include <stdio.h>
#include "temperature_conversor.h"

void convert_main(float temperature, char or, char dest);

int main(){
    float temperature = 0;
    char or = 'a', dest = 'a';

    scanf("%f %c %c", &temperature, &or, &dest);
    convert_main(temperature, or, dest);

    return 0;
}

void convert_main(float temperature, char or, char dest){
    if(or == 'c' && dest == 'k'){
        printf("Temperature: %.2fK", convert_temperature((temperature), convert_celsius_to_kelvin));
    }
    if(or == 'f' && dest == 'k'){
        printf("Temperature: %.2fK", convert_temperature((temperature), convert_fahrenheit_to_kelvin));
    }
    if(or == 'f' && dest == 'c'){
        printf("Temperature: %.2fCº", convert_temperature((temperature), convert_fahrenheit_to_celsius));
    }
    if(or == 'k' && dest == 'c'){
        printf("Temperature: %.2fCº", convert_temperature((temperature), convert_kelvin_to_celsius));
    }
    if(or == 'k' && dest == 'f'){
        printf("Temperature: %.2fFº", convert_temperature((temperature), convert_kelvin_to_fahrenheit));
    }
    if(or == 'c' && dest == 'f'){
        printf("Temperature: %.2fFº", convert_temperature((temperature), convert_celsius_to_fahrenheit));
    }
 
}
