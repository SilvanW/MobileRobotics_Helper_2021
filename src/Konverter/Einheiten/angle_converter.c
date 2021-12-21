/*  angle_converter.c
/   14.12.2021
/   Michael Albisser
*/

#include <stdio.h>
#include "angle_converter.h"

void degrees_to_radians(float a){
    float res = a * PI / 180;
    printf("%.3f Grad sind %.3f rad", a, res);
}

void radians_to_degrees(float a){
    float res = a * 180 / PI;
    printf("%.3f rad sind %.3f Grad", a, res);
}