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
#include <stdlib.h>
#include <stdbool.h>
#include "Helper.h"
#include "Functions/importFromCSV/importFromCSV.h"
#include "Mathematik/Mathematik_1/Hangman/piehangman.h"
#include "Informatik/Informatik_1/Quiz/INF1_quiz.h"
#include "Functions/MultipleChoice/Multiple_Choice.h"
#include "Optik/Optik_1/Optikformeln/Main_Optikformeln.h"
#include "Spiele/TicTacToe/TicTacToe.h"
#include "Optik/Optik_1/Quiz/Optik1.h"
#include "Konverter/Einheiten/Einheiten_Konverter_main.h"
#include "Optik/Optik_1/Spiegeldarstellung/optik.h"
#include "Mathematik/Mathematik_1/Trigonometrie/Trigonometrische_Funktionen_Main.h"
#include "Elektronik/Elektronik_1/elektronikQuiz.h"
#include "Konverter/Zahlenkonverter/zahlenkonverter.h"
#include "Mathematik/Mathematik_1/Linalg/lin_alg.h"
#include "Spiele/Lost_Found/lostfound.h"

// Variablen
Hauptmenu hauptmenu = 0;

// Mathematik
Mathematik mathematik = 0;
Mathematik_1 mathematik_1 = 0;
Mathematik_2 mathematik_2 = 0;

// Physik
Physik physik = 0;
Physik_1 physik_1 = 0;
Physik_2 physik_2 = 0;

// Optik
Optik optik = 0;
Optik_1 optik_1 = 0;
Optik_2 optik_2 = 0;

// Elektronik
Elektronik elektronik = 0;
Elektronik_1 elektronik_1 = 0;
Elektronik_2 elektronik_2 = 0;

// Informatik
Informatik informatik = 0;
Informatik_1 informatik_1 = 0;
Informatik_2 informatik_2 = 0;

// Converter
Converter converter = 0;

// Spiele
Spiele spiele = 0;

int main()
{
	while (1) {
	
		// Auswahlmenü Hauptmenu
		printf("-1- Mathematik\n");
		printf("-2- Physik\n");
		printf("-3- Optik\n");
		printf("-4- Elektronik\n");
		printf("-5- Informatik\n");
		printf("-6- Converter\n");
		printf("-7- Spiele\n");
		printf("-8- Auswertung\n");
		printf("-9- Exit\n");
		printf("Bitte gib eine Zahl ein: ");
		scanf("%i", &hauptmenu);

		// flush console
		fflush(stdin);

		// New Line
		printf("\n");	
	
		// switch case
		switch(hauptmenu)
		{
			case MATHEMATIK: printf("Mathematik\n"); // Case 1 => Mathematik
				
				// Auswahl Untermenü Mathe
				printf("-1- Mathematik 1\n");
				printf("-2- Mathematik 2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &mathematik);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				switch(mathematik) // Swtich Mathematik
				{
					case MATHEMATIK_1: printf("Mathematik 1\n"); // Case 1 => Mathematik 1
						
						// Auswahl Untermenü Mathe 1
						printf("-1- Linalg\n");
						printf("-2- Trigonometrische Funktionen\n");
						printf("-3- Multiple Choice\n");
						printf("-4- Hangman\n");
						printf("Bitte gib eine Zahl ein: ");
						scanf("%i", &mathematik_1);

						// flush console
						fflush(stdin);

						// New Line
						printf("\n");
				
						switch(mathematik_1) // Switch Mathematik 1
						{
							case 1: printf("Linalg\n");
								linAlg();
								break;
							case TRIGONOMETRISCHE_FUNKTIONEN: printf("Trigonometrische Funktionen\n");
								Trigo();
								break;
							case MATHEMATIK_1_MULTIPLE_CHOICE: printf("Multiple Choice\n");
								multiple_choice("Mathematik/Mathematik_1/test.csv", "Auswertung/Mathematik_1/MultipleChoice.csv","MultipleChoice");
								break;
							case HANGMAN: printf("Hangman\n");
								hangman();
								break;
							default: printf("Falscher Wert!\n");
								break;
						}
					break;
					
					case MATHEMATIK_2: printf("Mathematik 2\n"); // Case 2 => Mathematik 2
						
						// Auswahl Untermenü Mathe 2
						printf("\n");
						printf("Gids no noed du Streber\n");
					break;
						
				}
				break;

			case PHYSIK: printf("Physik\n"); // Case 2 => Physik
			
				// Auswahl Untermenü Physik
				printf("-1- Physik 1\n");
				printf("-2- Physik 2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &physik);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				switch(physik) // Swtich Physik
				{
					case PHYSIK_1: printf("Physik 1\n");
						
						// Auswahl Untermenü Physik 1
						printf("-1- Quiz\n");
						printf("Bitte gib eine Zahl ein: ");
						scanf("%i", &physik_1);

						// flush console
						fflush(stdin);

						// New Line
						printf("\n");
				
						switch(physik_1) // Switch Physik 1
						{
							case PHYSIK_1_QUIZ: printf("Quiz\n");
								multiple_choice("Physik/Physik_1/test.csv", "Auswertung/Physik_1/MultipleChoice.csv", "MultipleChoice");
							break;
							default: printf("Falscher Wert!\n");
							break;
						}
					break;
					
					case PHYSIK_2: printf("Physik 2\n");
						
						// Auswahl Untermenü Physik 2
						printf("Gids no noed du Streber \n");
					break;
						
				}
				break;
				
			case OPTIK: printf("Optik\n");
				
				// Auswahl Untermenü Optik
				printf("\n");
				printf("-1- Optik 1\n");
				printf("-2- Optik 2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &optik);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				switch(optik) // Switch Optik
				{
					case OPTIK_1: printf("Optik 1\n");
						
						// Auswahl Untermenü Optik 1
						printf("-1- Formeln\n");
						printf("-2- Quiz\n");
						printf("-3- Spiegelsimulation\n");
						printf("Bitte gib eine Zahl ein: ");
						scanf("%i", &optik_1);

						// flush console
						fflush(stdin);

						// New Line
						printf("\n");
				
						switch(optik_1) // Switch Optik1
						{
							case FORMELN: printf("Formeln\n");
								Main_Optikformeln();
							break;
							case OPTIK_1_QUIZ: printf("Quiz\n");
								Optik1_Quiz();
							break;
							case SPIEGELSIMULATION: printf("Spiegelsimulation\n");
								Spiegelsimulation();
							break;
							default: printf("Falscher Wert!\n"); // Default Case
							break;
						}
					break;
					
					case OPTIK_2: printf("Optik 2\n");
						
						// Auswahl Untermenü Optik 2
						printf("Gids no noed du Streber \n");
					break;	
				}
				break;
				
			case ELEKTRONIK: printf("Elektronik\n"); // Case 4 => Elektronik
			
				// Auswahl Untermenü Elektronik
				printf("-1- Elektronik 1\n");
				printf("-2- Elektronik 2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &elektronik);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				switch(elektronik) // Switch Elektronik
				{
					case ELEKTRONIK_1: printf("Elektronik 1\n");
						
						// Auswahl Untermenü Elektronik 1
						printf("-1- Quiz\n");
						printf("Bitte gib eine Zahl ein: ");
						scanf("%i", &elektronik_1);

						// flush console
						fflush(stdin);

						// New Line
						printf("\n");
				
						switch(elektronik_1) // Swtich Elektronik1
						{
							case ELEKTRONIK_1_QUIZ: printf("Quiz\n");
								elQuiz();
							break;
							default: printf("Falscher Wert!\n"); // Default Case => Falscher Wert
							break;
						}
					break;
					
					case ELEKTRONIK_2: printf("Elektronik 2\n");
						
						// Auswahl Untermenü Elektronik 2
						printf("\n");
						printf("Gids no noed du Streber\n");
					break;
						
				}
				break;
			
			case INFORMATIK: printf("Informatik\n");

				// Auswahl Untermenü Informatik
				printf("-1- Informatik_1\n");
                printf("-2- Informatik_2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &informatik);

				// flush console
				fflush(stdin);

				printf("\n");

				switch (informatik)
				{
				case INFORMATIK_1: printf("Informatik 1\n");
                    
                    // Auswahlen Untermenü Infromatik_1
                    printf("-1- Quiz\n");
                    printf("Bitte gib eine Zahl ein: ");
                    scanf("%i", &informatik_1);

                    switch (informatik_1)
                    {
                    case INFORMATIK_1_QUIZ:
                        inf1_quiz();
                        break;
                    
                    default:
                        break;
                    }
					
					break;
				
                case INFORMATIK_2: printf("Informatik 2");
                    printf("Gids no noed du Streber \n");
                    break;
				default:
					break;
				}
				break;

			case CONVERTER: printf("Converter\n");
			
				// Auswahl Untermenü Converter
				printf("-1- Zahlensystem\n");
				printf("-2- Einheiten\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &converter);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				switch(converter) // Switch Converter
				{
					case ZAHLENSYSTEM: printf("Zahlensystem\n");
						NumberConverter();
					break;
					case EINHEITEN: printf("Einheiten\n");
						Einheiten_Konverter();
					break;	
				}
				break;
			
			case SPIELE: printf("Spiele\n");
				// Auswahl Untermenü Converter
				printf("-1- TicTacToe\n");
                printf("-2- Lost&Found\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &spiele);

				// flush console
				fflush(stdin);

				switch (spiele)
				{
				case TICTACTOE:
					TicTacToe();
					break;
				
                case 2:
                    fflush(stdin);
                    lostfound();
                    break;

				default:
					break;
				}

				break;

			case AUSWERTUNG: printf("Auswertung\n");

				// Auswertung Mathematik
				printf("Mathematik_1\n");
				importFromCSV("Auswertung/Mathematik_1/MultipleChoice.csv");

				// Auswertung Physik
				printf("Physik_1\n");
				importFromCSV("Auswertung/Physik_1/MultipleChoice.csv");

				// Auswertung Optik
				printf("Optik_1\n");
                importFromCSV("Auswertung/Optik_1/Quiz.csv");
				importFromCSV("Auswertung/Optik_1/Bildentstehung_Spiegel_Linsen.csv");
				importFromCSV("Auswertung/Optik_1/Mehrlinsen_Mehrspiegelsysteme_optische_Instrumente.csv");
				importFromCSV("Auswertung/Optik_1/Reflexion_Brechung.csv");
				importFromCSV("Auswertung/Optik_1/optikOverall.csv");

				// Auswertung Elektronik
				printf("Elektronik_1\n");
				importFromCSV("Auswertung/Elektronik_1/elektronikQuiz.csv");

                // Auswertung Informatik
                printf("Informatik_1\n");
                importFromCSV("Auswertung/Informatik_1/informatikQuiz.csv");
			break;

			case EXIT: printf("Exit\n");
				return 0;
				break;
			
			default: printf("Falscher Wert!");
			break;
		}
	}
	
	// Verabschiedung
	printf("\nAuf Wiedersehen! \n");
	return 0;
}