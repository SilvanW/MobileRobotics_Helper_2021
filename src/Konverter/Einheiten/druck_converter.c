/*druck_converter.c

Autor: Corsin Monn
Firma: FHGR Mobile Robotics
Date: 2021/12/13
Version: 0.1
Changelog:

*/
#include <stdio.h> 
#include <stdlib.h>		
#include <string.h>

#include "druck_converter.h"

void bar_to_pascal(float p){
    float pu = p * 100000;
    printf("%.3f bar = %.3f Pascal\n", p, pu);
    return;
}

void pascal_to_bar(float p){
    float pu = p / 100000;
    printf("%.3f Pascal = %.3f bar\n", p, pu);
    return;
}

void atm_to_bar(float p){
    float pu = p * 1.01325;
    printf("%.3f ATM = %.3f bar\n", p, pu);
    return;
}

void atm_to_pascal(float p){
    float pu = p * 101325;
    printf("%.3f ATM = %.3f Pascal\n", p, pu);
    return;
}

void bar_to_atm(float p){
    float pu = p / 1.01325;
    printf("%.3f bar = %.3f ATM\n", p, pu);
    return;
}

void pascal_to_atm(float p){
    float pu = p / 101325;
    printf("%.3f Pascal = %.3f ATM\n", p, pu);
    return;
}

void psi_to_atm(float p){
    float pu = p / 14.696;
    printf("%.3f psi = %.3f ATM\n", p, pu);
    return;
}

void psi_to_bar(float p){
    float pu = p / 14.504;
    printf("%.3f psi = %.3f bar\n", p, pu);
    return;
}

void psi_to_pascal(float p){
    float pu = p * 6895;
    printf("%.3f psi = %.3f Pascal\n", p, pu);
    return;
}

void atm_to_psi(float p){
    float pu = p * 14.696;
    printf("%.3f ATM = %.3f psi\n", p, pu);
    return;
}

void bar_to_psi(float p){
    float pu = p * 14.504;
    printf("%.3f bar = %.3f psi\n", p, pu);
    return;
}

void pascal_to_psi(float p){
    float pu = p / 6895;
    printf("%.3f Pascal = %.3f psi\n", p, pu);
    return;
}
