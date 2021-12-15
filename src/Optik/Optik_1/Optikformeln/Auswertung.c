/*
 * Auswertung.c
 * Autor: Rebsamen Adrian
 * Firma: FHGR / Photonics
 * Version: 0.1
 * Datum: 15.12.2021
 * Beschriebung: Auswertung der Frage
 * Änderungen:
 * 0.1 15.12.2021 Erste Version
 */

// Inkludieren der Programmbibliotheken
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void Auswertung(int *points)
{

    char answer = 'a';
    char solution = 'a';


    printf("Frage mit Antwort Option a,b,c,d\n");
    scanf(" %c",&answer);

    if (answer == solution){
        *points = *points + 1;
        printf("korrekt!\n");
    }
    else {
        printf("falsch\n");
        printf("Die Richtige Antwort ist: %c\n",solution);
    }
    return *points;
}