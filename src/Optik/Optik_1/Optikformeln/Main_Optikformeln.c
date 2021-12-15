/*
 * Main_Optikformeln.c
 * Autor: Rebsamen Adrian
 * Firma: FHGR / Photonics
 * Version: 0.2
 * Datum: 15.12.2021
 * Beschreibung: Helfer zum Optikformeln und deren Anwendung zu lernen.
 * Dieses File führt die Multiplechoice Aufgaben auf und Sie können das Themengebiet auswählen.
 * Änderungen:
 * 0.1 13.12.2021 Erste Version
 * 0.2 15.12.2021 Erweiterung für die Auswahl
 */

// Inkludieren der Programmbibliotheken
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Inkludieren der Programmressourcen
//#include "DelInput.h"
//#include "Thema_1.h"
//#include "Thema_2.h"
//#include "Thema_3.h"
//#include "Thema_4.h"

// Variabeln Definieren
int Thema = 0;

// Rückgabewerte von scanf Funktion
int retVal1 = 0;

int main(void)
{
	//Ausgabe der möglichen Auswahl
	printf("-1-\t");
	printf("Reflexion und Brechung\n");
	printf("-2-\t");
	printf("Bildenstehung, Spiegel und Linsen\n");
	printf("-3-\t");
	printf("Mehrlinsen- und Mehrspiegelsysteme und optische Instrumente\n");
	printf("-4-\t");
	printf("Alle obengenannten Inhalte\n");
	printf("\n");
	printf("Wähle das Thema aus, das du lernen möchtest: ");
	retVal1 = scanf("%i", &Thema);
	delInput();
	
	//Eingabe auswerten und zum Bereich weiterleiten
	switch (Thema)
	{
		case 1:
		printf("Du hast Reflexion und Brechung gewählt.\n");
		Thema_1();
		break;
	
		case 2:
		printf("Du hast Bildenstehung, Spiegel und Linsen gewählt.\n");
		Thema_2();
		break;
	
		case 3:
		printf("Du hast Mehlrinsen- und Mehrspiegelsysteme und optische Instrumente gewählt.\n");
		Thema_3();
		break;
	
		case 4:
		printf("Du hast alle genannten Themen ausgewählt.\n");
		Thema_4();
		break;
		
		default:
		printf("Deine Auswahl ist nicht gültig.\n");
	}

	
	return 0;
}



