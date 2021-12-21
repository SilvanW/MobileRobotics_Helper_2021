/* Trigonometrie.c
-Spezielle Werte der trigonometrischen Funktionen
-Spezielle Werte der Arcus-Funktionen
Autor: Tim Germann, Yannick Kohler
Firma: FHGR / Mobile Robotics
Version: 0.1
Datum: 13.12.2021
Änderungen: 

0.1 13.12.2021 Version 1*/

// Einbinden von Headerdateien der Programmbibliothek. 
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "Trigonometrische_Funktionen_Headerfile.h"


//Main Programm
int Trigo()
{
    //Variablen
	int auswahl =0;
	int punktzahl =0;
    int eingabe =0;
    int loesung =0;
    int vergleich =0;
    
	//Auswahlmöglichkeiten
    printf("Was moechten Sie berechnen?\n");
    printf("1: Spezielle Werte der Trigonometrischen-Funktionen\n");
    printf("2: Spezielle Werte der Arcus-Funktionen\n");
	
	scanf("%d",&auswahl);
	
	if (auswahl == 1)
	{
		funktion1(punktzahl,eingabe,loesung,vergleich);
	}																				
		
	else if (auswahl == 2)
	{
		funktion2(punktzahl,eingabe,loesung,vergleich);
	}																				
	
	// Rückgabewert, dass das Programm erfolgreich beendet wurde. 
	return 0;
}