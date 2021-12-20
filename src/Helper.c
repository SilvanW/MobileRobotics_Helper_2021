/* 
* Helper.c
* Main Programm für Gruppenarbeit des Semesterende
* Autor: Silvan Wiedmer (Projektleiter), Ramona Ferri, Tim Barmettler (Praktikant)
* Erstellungsdatum: 13.12.21
* Version: 1.0 - Aufruf Export und CSV
* Version: 1.1 - Lesen von Ausertungs CSV
* Version: 1.2 - Hangman implementiert
*/


#include <stdio.h>
#include "Functions/importFromCSV/importFromCSV.h"
#include "Mathematik/Mathematik_1/Hangman/piehangman.h"
#include "Elektronik/Elektronik_Quiz/elektronikQuiz.h"

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

          // New Line
          printf("\n");	
	
	// switch case
	switch(Hauptmenu)
	{
		case 1: printf("Mathematik"); // Case 1 => Mathematik
			
			// Auswahl Untermenü Mathe
			printf("\n");
			printf("-1- Mathematik 1\n");
			printf("-2- Mathematik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Mathematik);

                              // New Line
                              printf("\n");
			
			switch(Mathematik) // Swtich Mathematik
			{
				case 1: printf("Mathematik 1"); // Case 1 => Mathematik 1
					
					// Auswahl Untermenü Mathe 1
					printf("\n");
					printf("-1- Linalg\n");
					printf("-2- Quiz\n");
					printf("-3- Hangman\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Mathematik1);

                                                  // New Line
                                                  printf("\n");
			
					switch(Mathematik1) // Switch Mathematik 1
					{
						case 1: printf("Linalg");
							break;
						case 2: printf("Quiz");
							break;
						case 3: printf("Hangman");
							hangman();
							break;
						default: printf("Falscher Wert!");
							break;
					}
				break;
				
				case 2: printf("Mathematik 2"); // Case 2 => Mathematik 2
					
					// Auswahl Untermenü Mathe 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;
					
			}
			break;

		case 2: printf("\nPhysik"); // Case 2 => Physik
		
			// Auswahl Untermenü Physik
			printf("\n");
			printf("-1- Physik 1\n");
			printf("-2- Physik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Physik);

                              // New Line
                              printf("\n");
			
			switch(Physik) // Swtich Physik
			{
				case 1: printf("Physik 1"); // Case 1 => Physik 1
					
					// Auswahl Untermenü Physik 1
					printf("\n");
					printf("-1- Quiz\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Physik1);

                                                  // New Line
                                                  printf("\n");
			
					switch(Physik1) // Switch Physik 1
					{
						case 1: printf("Quiz");
						break;
						default: printf("Falscher Wert!");
						break;
					}
				break;
				
				case 2: printf("Physik 2"); // Case 2 => Physik 2
					
					// Auswahl Untermenü Physik 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;
					
			}
			break;
			
		case 3: printf("Optik"); // Case 3 => Optik
			
			// Auswahl Untermenü Optik
			printf("\n");
			printf("-1- Optik 1\n");
			printf("-2- Optik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Optik);

                              // New Line
                              printf("\n");
			
			switch(Optik) // Switch Optik
			{
				case 1: printf("Optik 1"); // Case 1 => Optik 1
					
					// Auswahl Untermenü Optik 1
					printf("\n");
					printf("-1- Formeln\n");
					printf("-2- Quiz\n");
					printf("-3- Spiegelsimulation\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Optik1);

                                                  // New Line
                                                  printf("\n");
			
					switch(Optik1) // Switch Optik1
					{
						case 1: printf("Formeln"); // Case 1 => Formeln
						break;
						case 2: printf("Quiz"); // Case 2 => Quiz
						break;
						case 3: printf("Spiegelsimulation"); // Case 3 => Spiegelsimulation
						break;
						default: printf("Falscher Wert!"); // Default Case
						break;
					}
				break;
				
				case 2: printf("Optik 2"); // Case 2 => Optik 2
					
					// Auswahl Untermenü Optik 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;	
			}
			break;
			
		case 4: printf("Elektronik"); // Case 4 => Elektronik
		
			// Auswahl Untermenü Elektronik
			printf("\n");
			printf("-1- Elektronik 1\n");
			printf("-2- Elektronik 2\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Elektronik);

                              // New Line
                              printf("\n");
			
			switch(Elektronik) // Switch Elektronik
			{
				case 1: printf("Elektronik 1"); // Case 1 => Elektronik 1
					
					// Auswahl Untermenü Elektronik 1
					printf("\n");
					printf("-1- Elektronik\n");
					printf("Bitte gib eine Zahl ein: ");
					scanf("%i", &Elektronik1);

                                                  // New Line
                                                  printf("\n");
			
					switch(Elektronik1) // Swtich Elektronik1
					{
						case 1: printf("Elektronik"); // Case 1 => Elektronik
								elQuiz();
						break;
						default: printf("Falscher Wert!"); // Default Case => Falscher Wert
						break;
					}
				break;
				
				case 2: printf("Elektronik 2"); // Case 2 => Elektronik 2
					
					// Auswahl Untermenü Elektronik 2
					printf("\n");
					printf("Gids no noed du Streber");
				break;
					
			}
			break;
			
		case 5: printf("Converter"); // Case 5 => Converter
		
			// Auswahl Untermenü Converter
			printf("\n");
			printf("-1- Zahlensystem\n");
			printf("-2- Einheiten\n");
			printf("Bitte gib eine Zahl ein: ");
			scanf("%i", &Converter);

                              // New Line
                              printf("\n");
			
			switch(Converter) // Switch Converter
			{
				case 1: printf("Zahlensystem"); // Case 1 => Zahlensystem
				break;
				case 2: printf("Einheiten"); // Case 2 => Einheiten
				break;	
			}
			break;
			
		case 6: printf("Auswertung\n"); // Case 6 => Auswertung

                              // Read data from test.csv
                              importFromCSV("test.csv");

                              // Read data from Optik_1/Auswertung.csv
                              importFromCSV("Optik/Optik_1/Auswertung.csv");
		break;
		
		default: printf("Falscher Wert!");
		break;
	}
	
	// Verabschiedung
	printf("\nAuf Wiedersehen! \n");
	return 0;
}