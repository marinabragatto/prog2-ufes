#include <stdio.h>
#include "temperature_conversor.h"

float convert_celsius_to_kelvin(float temperature){
    return temperature + 273.15; 
}

float convert_celsius_to_fahrenheit(float temperature){
    return temperature*(9.0/5) + 32;
}


float convert_kelvin_to_celsius(float temperature){
    return temperature - 273.15;
}

float convert_kelvin_to_fahrenheit(float temperature){
    return (1.8)*(temperature - 273.15) + 32;
}

float convert_fahrenheit_to_celsius(float temperature){
    return (temperature - 32)/(1.8);
}

float convert_fahrenheit_to_kelvin(float temperature){
    return (temperature-32)*(5.0/9) + 273.15;
}

/**
 * @brief Converte uma temperatura usando uma função de conversão dada.
 * @param temperature A temperatura a ser convertida.
 * @param convert_func A função de conversão a ser usada.
 * @return A temperatura convertida.
 */
float convert_temperature(float temperature, float convert_func(float temperature)){ 
    return convert_func(temperature);
}