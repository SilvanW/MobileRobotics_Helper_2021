/*  temeratur_converter.c
/   13.12.2021
/   Michael Albisser
*/

#include <stdio.h>
#include "temperatur_converter.h"

void celsius_to_kelvin(float t){
    float res = t + 273.15;
    printf("%.3f Grad Celsius sind %.3f Kelvin", t, res);
}

void celsius_to_farenheit(float t){
    float res =  t * 9/5 + 32;
    printf("%.3f Grad Celsius sind %.3f Grad Farenheit", t, res);
}

void kelvin_to_celsius(float t){
    float res = t - 273.15;
    printf("%.3f Kelvin sind %.3f Grad Celsius", t, res);
}

void kelvin_to_farenheit(float t){
    float res = (t - 273.15) * 9/5 + 32;
    printf("%.3f Kelvin sind %.3f Grad Farenheit", t, res);
}

void farenheit_to_celsius(float t){
    float res = (t - 32) * 5/9;
    printf("%.3f Kelvin sind %.3f Grad Farenheit", t, res);
}

void farenheit_to_kelvin(float t){
    float res = (t - 32) * 5/9 + 273.15;
    printf("%.3f Grad Farenheit sind %.3f Kelvin", t, res);
}