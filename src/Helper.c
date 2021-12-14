/* 
* Helper.c
* Main Programm für Gruppenarbeit des Semesterende
* Autor: Silvan Wiedmer (Projektleiter), Ramona Ferri, Tim Barmettler (Praktikant)
* Erstellungsdatum: 13.12.21
* Version: 1.0 - Aufruf Export und CSV
*/


#include <stdio.h>
#include "Functions/exportToCSV.h"

int main()
{
	// Variablen
	int Hauptmenu = 0;
	int Mathematik, Mathematik1 = 0;
	int Physik, Physik1 = 0;
	int Optik, Optik1 = 0;
	int Elektronik, Elektronik1 = 0;
	int Converter = 0;
	
	
	// Auswahlmenü Hauptmenu
	printf("-1- Mathematik\n");
	printf("-2- Physik\n");
	printf("-3- Optik\n");
	printf("-4- Elektronik\n");
	printf("-5- Converter\n");
	printf("-6- Auswertung\n");
	printf("Bitte gib eine Zahl ein: ");
	scanf("%i", &Hauptmenu);	
	
	// switch case
	switch(Hauptmenu)
	{
		case 1: printf("Mathematik");
			
			// Auswahl Untermenü Mathe
			printf("\n");
			printf("-1- Mathematik 1\n");
			printf("-2- Mathematik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Mathematik);
			
			switch(Mathematik)
			{
				case 1: printf("Mathematik 1");
					
					// Auswahl Untermenü Mathe 1
					printf("\n");
					printf("-1- Linalg\n");
					printf("-2- Quiz\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Mathematik1);
			
					switch(Mathematik1)
					{
						case 1: printf("Linalg");
						break;
						case 2: printf("Quiz");
						break;
						default: printf("Falscher Wert!");
						break;
					}
				break;
				
				case 2: printf("Mathematik 2");
					
					// Auswahl Untermenü Mathe 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;
					
			}
			break;

		case 2: printf("Physik");
		
			// Auswahl Untermenü Physik
			printf("\n");
			printf("-1- Physik 1\n");
			printf("-2- Physik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Physik);
			
			switch(Physik)
			{
				case 1: printf("Physik 1");
					
					// Auswahl Untermenü Physik 1
					printf("\n");
					printf("-1- Quiz\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Physik1);
			
					switch(Physik1)
					{
						case 1: printf("Quiz");
						break;
						default: printf("Falscher Wert!");
						break;
					}
				break;
				
				case 2: printf("Physik 2");
					
					// Auswahl Untermenü Physik 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;
					
			}
			break;
			
		case 3: printf("Optik");
			
			// Auswahl Untermenü Optik
			printf("\n");
			printf("-1- Optik 1\n");
			printf("-2- Optik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Optik);
			
			switch(Optik)
			{
				case 1: printf("Optik 1");
					
					// Auswahl Untermenü Optik 1
					printf("\n");
					printf("-1- Formeln\n");
					printf("-2- Quiz\n");
					printf("-3- Spiegelsimulation\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Optik1);
			
					switch(Optik1)
					{
						case 1: printf("Formeln");
						break;
						case 2: printf("Quiz");
						break;
						case 3: printf("Spiegelsimulation");
						break;
						default: printf("Falscher Wert!");
						break;
					}
				break;
				
				case 2: printf("Optik 2");
					
					// Auswahl Untermenü Optik 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;	
			}
			break;
			
		case 4: printf("Elektronik");
		
			// Auswahl Untermenü Elektronik
			printf("\n");
			printf("-1- Elektronik 1\n");
			printf("-2- Elektronik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Elektronik);
			
			switch(Elektronik)
			{
				case 1: printf("Elektronik 1");
					
					// Auswahl Untermenü Elektronik 1
					printf("\n");
					printf("-1- Elektronik\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Elektronik1);
			
					switch(Elektronik1)
					{
						case 1: printf("Elektronik");
						break;
						default: printf("Falscher Wert!");
						break;
					}
				break;
				
				case 2: printf("Elektronik 2");
					
					// Auswahl Untermenü Elektronik 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;
					
			}
			break;
			
		case 5: printf("Converter");
		
			// Auswahl Untermenü Converter
			printf("\n");
			printf("-1- Zahlensystem\n");
			printf("-2- Einheiten\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Converter);
			
			switch(Converter)
			{
				case 1: printf("Zahlensystem");
				break;
				case 2: printf("Einheiten");
				break;	
			}
			break;
			
		case 6: printf("Auswertung");
		break;
		
		default: printf("Falscher Wert!");
		break;
	}
	
	// Verabschiedung
	printf("\nAuf Wiedersehen!");
	return 0;
}