/* 
* Helper.c
* Main Programm für Gruppenarbeit des Semesterende
* Autor: Silvan Wiedmer (Projektleiter), Ramona Ferri, Tim Barmettler (Praktikant)
* Erstellungsdatum: 13.12.21
* Version: 1.0 - Aufruf Export und CSV
* Version: 1.1 - Lesen von Ausertungs CSV
* Version: 1.2.0 - Hangman implementiert
* Version: 1.2.1 - INF1_quiz implementiert
* Version: 1.2.2 - Multiple_Choice implementiert
* Version: 1.2.3 - Main_Optikformeln implementiert
* Version: 1.2.4 - TicTacToe implementiert
* Version: 1.2.5 - Optik1 implementiert
* Version: 1.2.6 - Einheiten_Konverter implementiert
* Version: 1.2.7 - Spiegeldarstellung implementiert
* Version: 1.2.8 - Trigonometrische_Funktionen implementiert
* Version: 1.2.9 - elektronikQuiz implementiert
* Version: 1.2.10 - zahlenkonverter implementiert
* Version: 1.2.11 - lin_alg implementiert
* Version: 1.2.12 - lostfound implementiert
* Version: 1.3.0 - Helper.h file added => Switch Cases now from Header enums
* Version: 1.3.1 - Compiler Warnings in elektronikQuiz fixed
*/

#include "Helper.h"

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
		printf("\n-1- Mathematik\n");
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
	
		// Switch Hauptmenu
		switch(hauptmenu)
		{
			case MATHEMATIK: printf("Mathematik\n");
				
				// Auswahl Mathematik
				printf("-1- Mathematik 1\n");
				printf("-2- Mathematik 2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &mathematik);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				// Switch Mathematik
				switch(mathematik)
				{
					case MATHEMATIK_1: printf("Mathematik 1\n");
						
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
				
						// Switch Mathematik_1
						switch(mathematik_1)
						{
							case 1: printf("Linalg\n");
								// Call linAlg() function
								linAlg();
								break;
							case TRIGONOMETRISCHE_FUNKTIONEN: printf("Trigonometrische Funktionen\n");
								// Call Trigo() function
								Trigo();
								break;
							case MATHEMATIK_1_MULTIPLE_CHOICE: printf("Multiple Choice\n");
								// Call multiple_choice() function with Mathematik_1 questions
								multiple_choice("Mathematik/Mathematik_1/test.csv", "Auswertung/Mathematik_1/MultipleChoice.csv","MultipleChoice");
								break;
							case HANGMAN: printf("Hangman\n");
								// Call hangman() function
								hangman();
								break;
							default: printf("Falscher Wert!\n");
								break;
						}
					break;
					
					case MATHEMATIK_2: printf("Mathematik 2\n");
						
						// Auswahl Untermenü Mathe 2
						printf("\n");
						printf("Gids no noed du Streber\n");
					break;
						
				}
				break;

			case PHYSIK: printf("Physik\n");
			
				// Auswahl Untermenü Physik
				printf("-1- Physik 1\n");
				printf("-2- Physik 2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &physik);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				// Switch Physik
				switch(physik)
				{
					case PHYSIK_1: printf("Physik 1\n");
						
						// Auswahl Untermenü Physik 1
						printf("-1- Multiple Choice\n");
						printf("Bitte gib eine Zahl ein: ");
						scanf("%i", &physik_1);

						// flush console
						fflush(stdin);

						// New Line
						printf("\n");
				
						// Switch Physik_1
						switch(physik_1)
						{
							case PHYSIK_1_MULTIPLE_CHOICE: printf("Multiple Choice\n");
								// Call multiple_choice() function with Physik_1 questions
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
				
				// Switch Optik
				switch(optik)
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
				
						// Switch Optik_1
						switch(optik_1)
						{
							case FORMELN: printf("Formeln\n");
								// Call Main_Optikformeln() function
								Main_Optikformeln();
							break;
							case OPTIK_1_QUIZ: printf("Quiz\n");
								// Call Optik1_Quiz() function
								Optik1_Quiz();
							break;
							case SPIEGELSIMULATION: printf("Spiegelsimulation\n");
								// Call Spiegelsimulation() function
								Spiegelsimulation();
							break;
							default: printf("Falscher Wert!\n");
							break;
						}
					break;
					
					case OPTIK_2: printf("Optik 2\n");
						
						// Auswahl Untermenü Optik 2
						printf("Gids no noed du Streber \n");
					break;	
				}
				break;
				
			case ELEKTRONIK: printf("Elektronik\n");
			
				// Auswahl Untermenü Elektronik
				printf("-1- Elektronik 1\n");
				printf("-2- Elektronik 2\n");
				printf("Bitte gib eine Zahl ein: ");
				scanf("%i", &elektronik);

				// flush console
				fflush(stdin);

				// New Line
				printf("\n");
				
				// Switch Elektronik
				switch(elektronik)
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
				
						// Switch Elektronik_1
						switch(elektronik_1)
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

				// Switch Informatik
				switch (informatik)
				{
				case INFORMATIK_1: printf("Informatik 1\n");
                    
                    // Auswahlen Untermenü Infromatik_1
                    printf("-1- Quiz\n");
                    printf("Bitte gib eine Zahl ein: ");
                    scanf("%i", &informatik_1);

					// flush console
					fflush(stdin);

					// Switch Informatik_1
                    switch (informatik_1)
                    {
                    case INFORMATIK_1_QUIZ:
						// Call inf1_quiz() function
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
				
				// Switch Converter
				switch(converter)
				{
					case ZAHLENSYSTEM: printf("Zahlensystem\n");
						// Call NumberConverter() function
						NumberConverter();
					break;
					case EINHEITEN: printf("Einheiten\n");
						// Call Einheiten_Konverter() function
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

				// Switch spiele
				switch (spiele)
				{
				case TICTACTOE:
					// Call TicTacToe() function
					TicTacToe();
					break;
				
                case LOST_FOUND:
					// Call lostfound() function
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