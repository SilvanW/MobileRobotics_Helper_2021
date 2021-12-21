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
#include <time.h>
#include "../../../Functions/getTime/getTime.h"
#include "../../../Functions/exportToCSV/exportToCSV.h"

// Variabeln Definieren
int Thema = 0;
int UserAnswer = 0;
int PointCounter = 0;
float PointPercentage = 0;
int CorrectAnswer = 0;
int AnzahlFragen = 0;

// Rückgabewerte von scanf Funktion
int retVal1 = 0;

// Define Dataset Structure
typedef struct {
        char Thema[100];
        char Frage[100];
        char Antwort1[1000];
        char Antwort2[1000];
        char Antwort3[1000];
        char Antwort4[1000];
        char Antwort[100];
} Dataset;

// Define Variables
char buff[1024];
int reiheZehler = 0;
int wertIndex = 0;
Dataset values[999];

// Define File Pointer
FILE *fpt;

//Funktionsdeklaration
int importiereVoCSV(char Filename[50]) {

          // Open File in read mode and save to fpt variable
          fpt = fopen(Filename, "r");

          // Check if fpt is false
          if (!fpt) {
                    // Errpor Reading file
                    printf("Error Reading file");
                    return 0;
          }          

          // Go through the entire file
          while (fgets(buff, 1024, fpt)) {
                    // Seperate buffered strings
                    char *field = strtok(buff, ",");

                    // Set wertIndex to 0
                    wertIndex = 0;

                    // While field is not NULL
                    while(field != NULL) {

                              // Switch by wertIndex
                              switch (wertIndex) {
                              case 0: // Case 0 => Date
                                        strcpy(values[reiheZehler].Thema, field);
                                        break;
                              
                              case 1: // Case 1 => Time
                                        strcpy(values[reiheZehler].Frage, field);
                                        break;

                              case 2: // Case 2 => Theme
                                        strcpy(values[reiheZehler].Antwort1, field);
                                        break;

                              case 3: // Case 3 => Points
                                        strcpy(values[reiheZehler].Antwort2, field);
                                        break;

                              case 4:
                                        strcpy(values[reiheZehler].Antwort3, field);
                                        break;

                              case 5:
                                        strcpy(values[reiheZehler].Antwort4, field);
                                        break;

                            case 6:
                                        strcpy(values[reiheZehler].Antwort, field);
                                        break;

                              default: // Default case => Break
                                        break;
                              }

                              // Set Field to Null
                              field = strtok(NULL, ",");

                              // Increase wertIndex by 1
                              wertIndex++;
                    }
                    // Increase reiheZehler by 1
                    reiheZehler++;
          }

          // close file
          fclose(fpt);
			AnzahlFragen = reiheZehler;
          // Set reiheZehler to 0 => Required for multiple function calls
          reiheZehler = 0;

          return 0;
}

// Restsymbole aus dem Eingabespeicher löschen
void delInput(void)
{
	int c;
	//Liest alle Zeichen bis zum Schluss aus.
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
	
	return;
}

// Define variables
char day[10];
char mon[10];
char year[10];
char dateNew[40];

char hour[10];
char min[10];
char timeNew[30];

int Main_Optikformeln(void)
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
	printf("Jeder andere Wert um das Thema zu verlassen\n");
	printf("Was willst du lernen: ");
	retVal1 = scanf("%i", &Thema);
	delInput();
	
	//Eingabe auswerten und zum Bereich weiterleiten
	switch (Thema)
	{
		case 1:
		    printf("Reflexion und Brechung\n");
            importiereVoCSV("Optik/Optik_1/Optikformeln/Reflexion_Brechung.csv");
            PointCounter = 0;
            
            for(int Index = 0; Index < AnzahlFragen; Index++)
            {
                printf("%s\n", values[Index].Frage);
                printf("%s\n", values[Index].Antwort1);
                printf("%s\n", values[Index].Antwort2);
                printf("%s\n", values[Index].Antwort3);
                printf("%s\n", values[Index].Antwort4);
                
                CorrectAnswer = atoi (values[Index].Antwort);
                
                scanf("%i", &UserAnswer);
                delInput();
                if (CorrectAnswer == UserAnswer)
                {
                    printf("Korrekt\n");
                    PointCounter ++;
                }
                else
                {
                    printf("Falsch\n");
                    printf("Die korrekte Antwort ist: %s\n", values[Index].Antwort);
                }
            
            }
            
            PointPercentage = (float)PointCounter/AnzahlFragen*100;
            
			printf("Du hast %.0f%% der Punkte Erreicht\n", PointPercentage);            
			
			exportToCSV("Auswertung/Optik_1/Reflexion_Brechung.csv", getDate(), getTime(), values[0].Thema, PointPercentage);

            break;
	
		case 2:
			printf("Bildenstehung, Spiegel und Linsen\n");
			importiereVoCSV("Optik/Optik_1/Optikformeln/Bildentstehung_Spiegel_Linse.csv");
			PointCounter = 0;
			
            for(int Index = 0; Index < AnzahlFragen; Index++)
            {
                printf("%s\n", values[Index].Frage);
                printf("%s\n", values[Index].Antwort1);
                printf("%s\n", values[Index].Antwort2);
                printf("%s\n", values[Index].Antwort3);
                printf("%s\n", values[Index].Antwort4);
                
                CorrectAnswer = atoi (values[Index].Antwort);
                
                scanf("%i", &UserAnswer);
                delInput();
                                
                if (CorrectAnswer == UserAnswer)
                {
                    printf("Korrekt\n");
                    PointCounter ++;
                }
                else
                {
                    printf("Falsch\n");
                    printf("Die korrekte Antwort ist: %s\n", values[Index].Antwort);
                }
            
            }
                                 
            printf("%i\n", PointCounter);
			printf("%i\n", AnzahlFragen);
			
			            
            PointPercentage = (float)PointCounter/AnzahlFragen*100;
            
			printf("Du hast %.0f%% der Punkte Erreicht\n", PointPercentage);            
			
			exportToCSV("Auswertung/Optik_1/Bildentstehung_Spiegel_Linsen.csv", getDate(), getTime(), values[0].Thema, PointPercentage);
			
			break;
	
		case 3:
			printf("Mehrlinsen- und Mehrspiegelsysteme und optische Instrumente\n");
			importiereVoCSV("Optik/Optik_1/Optikformeln/Optische_instrumente.csv");
			PointCounter = 0;
			
            for(int Index = 0; Index < AnzahlFragen; Index++)
            {
                printf("%s\n", values[Index].Frage);
                printf("%s\n", values[Index].Antwort1);
                printf("%s\n", values[Index].Antwort2);
                printf("%s\n", values[Index].Antwort3);
                printf("%s\n", values[Index].Antwort4);
                
                CorrectAnswer = atoi (values[Index].Antwort);

                scanf("%i", &UserAnswer);
                delInput();
                
                
                if (CorrectAnswer == UserAnswer)
                {
                    printf("Korrekt\n");
                    PointCounter ++;
                }
                else
                {
                    printf("Falsch\n");
                    printf("Die korrekte Antwort ist: %s\n", values[Index].Antwort);
                }
            
            }
            
            PointPercentage = (float)PointCounter/AnzahlFragen*100;
            
			printf("Du hast %.0f%% der Punkte Erreicht\n", PointPercentage);            
			
			exportToCSV("Auswertung/Optik_1/Mehrlinsen_Mehrspiegelsysteme_optische_Instrumente.csv", getDate(), getTime(), values[0].Thema, PointPercentage);
			
			break;
	
		case 4:
			printf("alle Themen\n");
			importiereVoCSV("Optik/Optik_1/Optikformeln/Alle_Themen.csv");
			PointCounter = 0;
			
            for(int Index = 0; Index < AnzahlFragen; Index++)
            {
                printf("%s\n", values[Index].Frage);
                printf("%s\n", values[Index].Antwort1);
                printf("%s\n", values[Index].Antwort2);
                printf("%s\n", values[Index].Antwort3);
                printf("%s\n", values[Index].Antwort4);
                
                CorrectAnswer = atoi (values[Index].Antwort);

                scanf("%i", &UserAnswer);
                delInput();
                if (CorrectAnswer == UserAnswer)
                {
                    printf("Korrekt\n");
                    PointCounter ++;
                }
                else
                {
                    printf("Falsch\n");
                    printf("Die korrekte Antwort ist: %s\n", values[Index].Antwort);
                }
            
            }
            
            PointPercentage = (float)PointCounter/AnzahlFragen*100;
            
			printf("Du hast %.0f%% der Punkte Erreicht\n", PointPercentage);
            
			exportToCSV("Auswertung/Optik_1/optikOverall.csv", getDate(), getTime(), "Overall", PointPercentage);
			
			break;
		
		default:
			printf("Deine Auswahl ist nicht korrekt.\n");
			
	}

	
	return 0;
}
