/* 
Data: INF1_Quiz.c
Name: Source Informatik 1 Quiz
Project: Informatik 1 Quiz
Projektleiter: Jannis Mathiuet
Team: Dominic Eicher, Patric Piceci
Company: FHGR/MR
Version: 1.0
Date: 19.12.2021
Changelog:
*/

// Bibliothek
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../Functions/exportToCSV/exportToCSV.h"
#include "../../../Functions/getTime/getTime.h"

// Header
#include "INF1_quiz.h"

// Konstanten
#define ANZ_FG 15		// Anzahl Fragen ins gesamt

// Nebenfunktionen
void formatF(int n); 	//Formatierung Fragen
int frage(int sol); 	// Fragen
void decF(int n, int x, int solarr[], int *punktzahl); // Bestimmung Frage


//======================================================================
// Hauptfunktion
//======================================================================
void inf1_quiz()
{
	//Parameter
	int punktzahl = 0;		// Punktzahl
	int anzf = 0;			// Anzahl Fragen fuer Quiz
	int arrF[ANZ_FG] = {};	// Array fuer gestellte Fragen
	int solarr[ANZ_FG] = {2, 1, 3, 1, 2,	//Antwort auf Fragen case 1-5
						  2, 1, 3, 1, 3,	//Antwort auf Fragen case 6-10
						  1, 3, 2, 3, 1};	//Antwort auf Fragen case 11-15
	srand(time(NULL));		// Basis fuer Zufallszahl
	
	
	// Auswahl der Reihenfolge fuer Quiz-Fragen
	for(int i=0; i < ANZ_FG; ++i)
    {
		int x = 0;		  // Variable Zufallszahl
		int statIO = 0;   // Status ist IO (1), wenn Frage noch nicht gestellt
		
		while (statIO != 1)
		{
			x = (rand()%ANZ_FG) + 1; // Generierung zufaelliger Zahl
			
			for (int j = 0; j < ANZ_FG; ++j) // Kontrolle, ob Frage schon gestellt
			{
				if (arrF[j] == x) 	// Vergleich Arrayelement und Zufallszahl
				{
					statIO = 0;		// Gleichheit statIO auf false (0)
					break;			// und Abbruch
				}
				else
				{
					statIO = 1;		// Ungleichheit statIO auf true (1)
				}
			}
			
			
			if (statIO == 1) // Auffuellen Array
			{	
				arrF[i]=x;
			}
		}
	}
	
	
	
	//Wilkommensgruss und Erklaerung des Programms
	printf(
	"\n\n\n================================================================\n"
	"================================================================\n"
	"Wilkommen zum Informatik 1 Quiz!\n\n\n"
	
	"Hier werden einige Fragen zu den letzten paar Wochen über die Programmiersprache C gestellt\n\n"
	
	"Die Regeln sind einfach: Es werden Ihnen einige Fragen gestellt  mit jeweils drei Antwortmoeglichkeiten\n"
	"Sie entscheiden, welche korrekt ist, mittels Eingabe von 1, 2 oder 3 in die Konsole\n\n"
	"Korrekte Antworten: Pluspunkt\n\n"
	
	"Viel Glueck und gutes Gelingen! >.<"
	"\n\n\n");
	
	// Auswahl Anzahl Fragen
	printf("Wieviele Fragen (1-15) moechten Sie beantworten: ");
	scanf("%d", &anzf);
	printf("\n\n");
	
	// 5 Fragen, wenn Auswahl ausserhalb des Bereichs
	if ((anzf<1) || (anzf>15))
	{
		anzf = 5;
	}
	
	// Fragen aufrufen
	for	(int i=0; i < anzf; ++i)
	{
		//printf("%d\n", arrF[i]);
		decF(i+1, arrF[i], solarr, &punktzahl);
			//       i: Fragennummer
			// arrF[i]: aufgerufene Frage im Fragenrray
			//  solarr: Loesungarray
	}
	
	
	// Ausgabe Punktzahl
	printf(
	"********************\n"
	"Ihre Punkzahl: %d/%d\n"
	"Gratulation! :D\n"
	"********************\n\n"
	"================================================================\n"
	"================================================================\n", 
	punktzahl, anzf);
	int prozent = (float)punktzahl/anzf*100;
	exportToCSV("Auswertung/Informatik_1/informatikQuiz.csv", getDate(), getTime(), "Informatik_1", prozent);
	
// Ende Hauptfunktion
}






//======================================================================
// Definition Nebenfunktionen
//======================================================================


// Formatierung Fragen
void formatF(int n)
{
	char ph[] = "====================\n";	// Platzhalter
	printf("%sFrage %d\n%s", ph, n, ph);
}


// Frage
int frage(int sol)
{
	//Initialisierung
	int antwort = 0;
	char abstand[]= "\n\n\n";
	
	//Eingabe Antwort
	printf("\nIhre Antwort: ");
	scanf("%d", &antwort);
	
	//Kontrolle der Antwort
	if (antwort == sol)
	{	
		printf("Korrekt.\n %s", abstand);
		
		return +1;
	}
	else
	{	
		printf("Falsch, die korrekte Antwort ist %d.\n %s", sol, abstand);
		return 0;
	}
}


// Bestimmung, welche Frage aufgerufen werden soll
void decF(int n, int x, int solarr[], int *punktzahl)
{
	int z = x-1;  // Stelle in Loesungsarray
	switch(x)
	{
		case 1:
			formatF(n);
			printf("Welche Schleifen stehen Ihnen zur Verfuegung?\n\n");
			printf(
			"1. if, when\n"
			"2. for, while, do-while\n"
			"3. and, or\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 2
			break;
			
		case 2:
			formatF(n);
			printf("Welche Schleife sollten Sie verwenden, wenn mehrere Anweisungen mindestens einmal ausgefuehrt werden sollen?\n\n");
			printf(
			"1. do-while\n"
			"2. if\n"
			"3. when\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 1
			break;
			
		case 3:
			formatF(n);
			printf("Welche Aussage zu globalen und lokalen Variablen trifft zu?\n\n");
			printf(
			"1. Eine lokale Variabel wird immer ausserhalb eines Anweisungsblock definiert und ist im Anweisungsblock nicht sichtbar.\n"
			"2. Globale Variablen werden innerhalb des Anweisungsblock definiert und sind im ganzen Programm sichtbar. \n"
			"3. Globale Variablen werden ausserhalb der Anweisungsbloecke definiert und sind im ganzen Programm sichtbar. \n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 3
			break;
			
		case 4:
			formatF(n);
			printf("Was sind Arrays?\n\n");
			printf(
			"1. Datenstrukturen, in denen sich mehrere Werte eines bestimmten Datentyps speichern und bearbeiten lassen.\n"
			"2. Operationen wie Plus oder Minus.\n"
			"3. Eine nach der Groesse sortierte Matrix von Werten.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 1
			break;	
			
		case 5:
			formatF(n);
			printf("Wo liegt der Unterschied zwischen Arrays und Strings?\n\n");
			printf(
			"1. Arrays koennen mehr Werte aufnehmen.\n"
			"2. Strings sind nichts anderes als Arrays vom Datentyp char.\n"
			"3. Strings sind Woerter und Arrays sind Zahlentabellen.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 2
			break;
			
		case 6:
			formatF(n);
			printf("Was ist der NULL-Zeiger und wozu ist er gut?\n\n");
			printf(
			"1. Er zeigt auf die nullte Stelle von einem Array / String.\n"
			"2. Um zu vermeiden, dass ein Zeiger auf eine ungueltige Adresse verweist.\n"
			"3. Strings sind Woerter und Arrays sind Zahlentabellen.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 2
			break;
			
		case 7:
			formatF(n);
			printf("Was ist ein void-Zeiger und wozu wird er verwendet?\n\n");
			printf(
			"1. Er ist ein typenloser Zeiger.\n"
			"2. Er zeigt auf das Ende des Programms.\n"
			"3. Er springt zum Anfang des Programms zurueck.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 1
			break;	
			
		case 8:
			formatF(n);
			printf("Wie koennen nicht benoetigte Speicher wieder an das System zurueckgebracht werden?\n\n");
			printf(
			"1. Mit Loeschen.\n"
			"2. Mit drag'n'drop.\n"
			"3. Mit der Funktion free().\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 3
			break;
			
		case 9:
			formatF(n);
			printf("Was bewirkt das Schluesselwort «const» vor einem Datentyp?\n\n");
			printf(
			"1. Mit dem Qualifikator «const» koennen Sie nicht mehr veränderbare Variablen (Konstanten) definieren.\n"
			"2. Konstanten brauchen keinen Datentyp.\n"
			"3. Nach dem Funktionsaufruf bzw. dessen Durchfuehrung werden Konstanten geloescht.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 1
			break;
						
		case 10:
			formatF(n);
			printf("Was wird in den folgenden Zeilen für einen Wert ausgegeben?\n\n"
					"\tint i = 1;\n"
					"\tprintf(\"i = %%d\", i--);\n"
					"\tprintf(\"i = %%d\", ++i);\n"
					"\tprintf(\"i = %%d\", i++);\n"
					"\tprintf(\"i = %%d\", ++i);\n\n");
			printf(
			"1. i = 1  i = 1  i = 1  i = 1\n"
			"2. i = 1  i = 1  i = 2  i = 1\n"
			"3. i = 1  i = 1  i = 1  i = 3\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 3
			break;	
			
		case 11:
			formatF(n);
			printf("welche Typumwandlung enthaelt der folgende Code?\n\n"
					"\tint iVal = 1;\n"
					"\tdouble dVal = 1.5;\n"
					"\tprintf(\"i = %%f\\n\", iVal + dVal\");\n\n");
			printf(
			"1. Implizite Typumwandlung.\n"
			"2. Explizite Typumwandlung.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 1
			break;
						
		case 12:
			formatF(n);
			printf("Restwert-Ausgabe mit %% bei einer Division:\n\n");	
			printf(
			"1. Ja, immer moeglich.\n"
			"2. Ja, jedoch nur mit einem int und einem double int moeglich.\n"
			"3. Ja, jedoch nur mit einem int moeglich.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 3
			break;
						
		case 13:
			formatF(n);
			printf("Funktionsaufruf sizeof():\n\n");
			printf(
			"1. Gibt die Groesse einer Datei an.\n"
			"2. Gibt die Groesse eines Datentyps in Bytes an.\n"
			"3. Gibt die Groesse eines Datentyps in Bits an.\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 2
			break;
												
		case 14:
			formatF(n);
			printf("Wann ist das Verwenden von Funktionen besonders sinnvoll?\n\n");
			printf(
			"1. Einzeiliger & aehnlicher/gleiche  Code, der immer wieder verwendet wird\n"
			"2. Mehrerezeiliger Code, der einmalig verwendet wird\n"
			"3. Mehrerezeiliger & aehnlicher/gleiche  Code, der immer wieder verwendet wird\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 3
			break;
			
		case 15:
			formatF(n);
			printf("Was ist ein Synoynm fuer Header?\n\n");
			printf(
			"1. Schnittstelle\n"
			"2. Source-Datei\n"
			"3. Kopfsalat\n"
			);
			*punktzahl += frage(solarr[z]); // korrekte Antwort: 1
		default:
			break;
	}
}
