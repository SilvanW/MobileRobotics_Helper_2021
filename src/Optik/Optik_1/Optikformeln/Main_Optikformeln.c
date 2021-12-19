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
#include "DelInput.h"

// Variabeln Definieren
int Thema = 0;

// Rückgabewerte von scanf Funktion
int retVal1 = 0;

// Define Dataset Structure
typedef struct {
          char Frage[100];
          char Antwort1[100];
          char Antwort2[100];
          char Antwort3[100];
          char Antwort4[100];
          char Antwort[100];
} Dataset;

// Define Variables
char buff[1024];
int rowCount = 0;
int valIndex = 0;
Dataset values[999];

// Define File Pointer
FILE *fpt;

//Funktionsdeklaration
int importFromCSV(char Filename[50]) {

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

                    // Set valIndex to 0
                    valIndex = 0;

                    // While field is not NULL
                    while(field != NULL) {

                              // Switch by valIndex
                              switch (valIndex) {
                              case 0: // Case 0 => Date
                                        strcpy(values[rowCount].Frage, field);
                                        printf("%s \n", values[rowCount].Frage);
                                        break;
                              
                              case 1: // Case 1 => Time
                                        strcpy(values[rowCount].Antwort1, field);
                                        printf("%s \n", values[rowCount].Antwort1);
                                        break;

                              case 2: // Case 2 => Theme
                                        strcpy(values[rowCount].Antwort2, field);
                                        printf("%s \n", values[rowCount].Antwort2);
                                        break;

                              case 3: // Case 3 => Points
                                        strcpy(values[rowCount].Antwort3, field);
                                        printf("%s \n", values[rowCount].Antwort3);
                                        break;

                              case 4:
                                        strcpy(values[rowCount].Antwort4, field);
                                        printf("%s \n", values[rowCount].Antwort4);
                                        break;

                              case 5:
                                        strcpy(values[rowCount].Antwort, field);
                                        printf("%s \n", values[rowCount].Antwort);
                                        break;

                              default: // Default case => Break
                                        break;
                              }

                              // Set Field to Null
                              field = strtok(NULL, ", ");

                              // Increase valIndex by 1
                              valIndex++;
                    }
                    // Increase rowCount by 1
                    rowCount++;
          }

          // close file
          fclose(fpt);

          // Set rowCount to 0 => Required for multiple function calls
          rowCount = 0;

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
	printf("Jeder andere Wert um das Thema zu verlassen\n");
	printf("Was willst du lernen: ");
	retVal1 = scanf("%i", &Thema);
	delInput();
	
	//Eingabe auswerten und zum Bereich weiterleiten
	switch (Thema)
	{
		case 1:
		printf("Reflexion und Brechung\n");
		importFromCSV("Reflexion_Brechung.csv");
		break;
	
		case 2:
		printf("Bildenstehung, Spiegel und Linsen\n");
		
		break;
	
		case 3:
		printf("Mehlrinsen- und Mehrspiegelsysteme und optische Instrumente\n");
		
		break;
	
		case 4:
		printf("alle Themen\n");
		
		break;
		
		default:
		printf("Deine Auswahl ist nicht korrekt.\n");
	}

	
	return 0;
}