/*  weight_converter.c
/   13.12.2021
/   Michael Albisser
*/

#include <stdio.h>
#include "weight_converter.h"

void oz_to_kg(float m){
    float res = (m * 28.349523125) / 1000;
    printf("%.3f ounce sind %.3f kg", m, res);
}

void kg_to_oz(float m){
    float res = (m * 1000) / 28.349523125;
    printf("%.3f kg sind %.3f ounce", m, res);
}

void lb_to_kg(float m){
    float res = (m * 453.59237) / 1000;
    printf("%.3f pound sind %.3f kg", m, res);
}

void kg_to_lb(float m){
    float res = (m * 1000) / 453.59237;
    printf("%.3f kg sind %.3f pound", m, res);
}

void stone_to_kg(float m){
    float res = m * 6.35;
    printf("%.3f stone %.3f kg", m, res);
}

void kg_to_stone(float m){
    float res = m / 6.35;
    printf("%.3f kg sind %.3f stone", m, res);
}