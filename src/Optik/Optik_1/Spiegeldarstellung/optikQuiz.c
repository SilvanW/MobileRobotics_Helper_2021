/* Optik Quiz
Autor: Micha Gelencsér
Version: 0.4
Datum: 14.12.2021

Änderungen:
0.1 08.12.2021 Erstellen der ersten vier Quiz
0.2 10.12.2021 Überarbeitung mit der Quiz-Fragen mit switch case anstatt if else
0.3 13.12.2021 Zweite Überarbeitung der switch case, implementierung der Funktion Alles-Quiz
0.4 14.12.2021 Fertigstellung Funktion Alles-Quiz, implementierung von Vortschritt des Lernstand (in Prozent)
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Definieren der Funktionen
void optikQuiz();
int spiegelquiz(int answer);
int oberflquiz(int answer);
int linsenquiz(int answer);
int allesquiz(int answer);

//Definieren der Variabeln
static float perSpiegel = 0;
static float perOberfl = 0;
static float perLins = 0;
static float perAlles = 0;
static float ovraper = 0; 		//Overall Percentage


//Quiz Menü
void optikQuiz(){
	
	// Variable für die Eingabenwahl
	static int choice = 0;
	static int answer = 0;
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("-------------------------------------------------------------------------------------------------------\n");
	printf("                                     Willkommen im Opik-Quiz\n");
	printf("-------------------------------------------------------------------------------------------------------\n\n");

	// Quiz Auswahl
	do{
		if(ovraper == 100){
			printf("\n\n----------------------------------------------------------------------------------\n");
			printf("\n\n\n\nGratulation! Du kannst alles im Fach Optik und bist bereit fuer die Pruefung.\n");
			return;
		}
		else{
			// Auswahlmöglichkeiten
			printf("\nIn welchem Thema willst du ein Quiz beginnen\?\n");
			printf("1 : Spiegel                        Vortschritt: %ld %%\n", lround (perSpiegel));
			printf("2 : Brechung an Oberflaechen       Vortschritt: %ld %%\n",  lround (perOberfl));
			printf("3 : Linsen                         Vortschritt: %ld %%\n",  lround (perLins));
			printf("4 : Alles durchmischt              Vortschritt: %ld %%\n",  lround (perAlles));
			printf("5 : Ich will doch nicht quizen\n");
			printf("Der Gesamtvortschritt ist: %ld %%\n",lround(ovraper));
			printf("Ihre Wahl : ");
			scanf("%d",&choice);
			fflush(stdin);
		
			switch(choice){
				case 1 : spiegelquiz(answer);
					break;
				case 2 : oberflquiz(answer);
					break;
				case 3 : linsenquiz(answer);
					break;
				case 4 : allesquiz(answer);
					break;
				case 5 : return;
					break;
				default: printf("\nFalsche Eingabe!!!\n\n");
			}
	} 
	}
	while(choice != 5);
	
	return;
}

	//Funktion Quiz Spiegel
	int spiegelquiz (int answer){
		int points = 0;
		printf("\nLos gehts mit dem Spiegelquiz: \n\n");
		
		//Erste Frage Spiegel
		answer = 0;
		do{
		printf("\nFrage 1: \n");
		printf("Entsteht ein reelles Bild bei einem Planspiegel\?\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Zweite Frage Spiegel
		answer = 0;
		do{
		printf("\n\nFrage 2: \n");
		printf("Ist die Bildweite immer negativ bei einem Planspiegel\?\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Dritte Frage Spiegel
		answer = 0;
		do{
		printf("\n\nFrage 3: \n");
		printf("Ist die Formel f = r/2 korrekt fuer sphaerische Spiegel\?\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Vierte Frage Spiegel
		answer = 0;
		do{
		printf("\n\nFrage 4: \n");
		printf("Ist die Lateralvergroesserung positiv wenn die Bildweite b = 3 und die Gegenstandsweite g = 6 ist\?\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Fünfte Frage Spiegel
		answer = 0;
		do{
		printf("\n\nFrage 5: \n");
		printf("Eine negative Lateralvergroesserung bedeutet, dass das Bild eines Gegenstandes kleiner ist als der Gegenstand\?\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		perSpiegel = ((float)points * 100) / 5;
		points ++;
		printf("\n\nDu hast das Quiz beendet und hast folgende Note erreicht: %d\n",points);
		printf("\nDu  kannst nun ein weiteres Quiz spielen oder das Quiz beenden:\n");
		ovraper = (perSpiegel + perOberfl + perLins + perAlles) / 5;
		return 0;
   }
 


	//Funktion Quiz Brechung an Oberflächen 
	int oberflquiz (int answer){
		int points = 0;
		printf("\nLos gehts mit dem Quiz ueber Brechnung an Oberflaechen! \n\n");
	   
		//Erste Frage Oberflaeche
		answer = 0;
		do{
		printf("Frage 1: \n");
		printf("Braucht man die Brechzahl um die Lateralvergroesserung zu berechnen\?\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);		
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Zweite Frage Oberflaeche
		answer = 0;
		do{
		printf("\n\nFrage 2: \n");
		printf("Ist die Gegenstandsweite positiv, ist der Gegenstand auf der Transmissionsseite.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Dritte Frage Oberflaeche
		answer = 0;
		do{
		printf("\n\nFrage 3: \n");
		printf("Im Innern eines Mediums mit Brechzahl groesser eins kann kein reelles Bild entstehen.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Vierte Frage Oberflaeche
		answer = 0;
		do{
		printf("\n\nFrage 4: \n");
		printf("Wir nehmen an dass, b = 10cm, f = 5cm, n1 = 1, n2 = 1.5. Wie gross ist V\?\n");
		printf("1: 2\n");
		printf("2: -1\n");
		printf("3: 1\n");
		printf("4: Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Fünfte Frage Oberflaeche
		answer = 0;
		do{
		printf("\n\nFrage 5: \n");
		printf("Ist die Oberflaeche konkav, sind sowohl reelle als auch virtuelle Bilder moeglich.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		perOberfl = ((float)points * 100) / 5;
		points ++;
		printf("\n\nDu hast das Quiz beendet und hast folgende Note erreicht: %d\n",points);
		printf("Dies ist folgendes in Prozent: %f %%\n\n\n",perOberfl);
		printf("\nDu  kannst nun ein weiteres Quiz spielen oder das Quiz beenden:\n");
		ovraper = (perSpiegel + perOberfl + perLins + perAlles) / 5;

		return 0;
	}
   
   
	//Funktio Quiz Linsen
    int linsenquiz (int answer){
		int points = 0;
		printf("\nLos gehts mit dem Quiz ueber Linsen! \n\n");
	   
		//Erste Frage Linsen
		answer = 0;
		do{
		printf("\nFrage 1: \n");
		printf("Ist f negativ, liegt eine Zerstreuunglinse vor.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Zweite Frage Linsen
		answer = 0;
		do{
		printf("\nFrage 2: \n");
		printf("Die Brechkraft ist ein Synonyom fuer Dioptrie. \n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Dritte Frage Linsen
		answer = 0;
		do{
		printf("\nFrage 3: \n");
		printf("Beide Brennpunkte einer sphaerische Linse liegen gleich weit vom Mittelpunkt der Linse entfernt.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Vierte Frage Linsen 
		answer = 0;
		do{
		printf("\nFrage 4: \n");
		printf("Die Brechkraft einer sphaerischen Linse ist unabhaengig vom Medium, welches die Linse umgibt.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Fünfte Frage Linsen
		answer = 0;
		do{
		printf("\nFrage 5: \n");
		printf("Bei jeder konvex-konkaven Sammellinse ist die Brennweite negativ.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		perLins = ((float)points * 100) / 5;
		points ++;
		printf("\n\nDu hast das Quiz beendet und hast folgende Note erreicht: %d\n",points);
		printf("Dies ist folgendes in Prozent: %f %%\n\n\n",perLins);
		printf("\nDu  kannst nun ein weiteres Quiz spielen oder das Quiz beenden:\n");
		ovraper = (perSpiegel + perOberfl + perLins + perAlles) / 5;
		return 0;
	}
   
   //Funktion Alles-Quiz
    int allesquiz (int answer){
		int points = 0;
		//Erste Frage Alles
		answer = 0;
		do{
		printf("\nFrage 1: \n");
		printf("Die Winkelvergroesserung ist das gleiche wie die Lateralvergroesserung\?\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Zweite Frage Alles
		answer = 0;
		do{
		printf("\nFrage 2: \n");
		printf("Bei der chromatischen Aberration gibt es Variation der Brechzahl durch die unterschiedliche Wellenlaengen\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 :  printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Dritte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 3: \n");
		printf("Wenn man kurzsichtig ist, ist das Auge zu lange und somit \n");
		printf("werden Lichtstrahlen vor anstatt auf der Netzhaut abgebildet werden.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 :  printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Vierte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 4: \n");
		printf("Totalreflexion kann nur auftreten, wenn Licht auf eine Grenzflaeche zu einem optisch dickeren Medium auftrifft.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Fünfte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 5: \n");
		printf("Bei einem Planspiegel gehen keine Lichtstrahlen vom Bildpunkt P' aus.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 :  printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		//Sechste Frage Alles
		answer = 0;
		do{
		printf("\nFrage 6: \n");
		printf("Die Abbildungsgleichung 1/g + 1/b = 1/f gilt nicht exakt.");
		printf("Sie ist eine Naeherung fuer achsennahe Strahlen.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 :  printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Siebte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 7: \n");
		printf("Kann ein reelles Bild entstehen bei einer brechenden Oberflaeche eines Mediums, mit Brechzahl > 1.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 :  printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Achte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 8: \n");
		printf("Bei einer bikonvexen duennen sphaerischen Linse ist der Radius der vorderen Oberflaeche negativ.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
						 
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Neunte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 9: \n");
		printf("Wie bei einer duennen Linse wird ein Lichtstrahl beim Durchgang durch eine dicke Linse zweimal gebrochen\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
						 
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Zehnte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 10: \n");
		printf("Fuer die Bildkonstruktion am Linsensystem braucht man ein Zwischenbild. \n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
						 
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Elfte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 11: \n");
		printf("Koma aeussert sich dadurch, dass sich bei einem parallel zur optischen Achse einfallenden Lichtbuendel,\n");
		printf("die gebrochenen Strahlen in verschiedenen Punkten der optischen Achse schneiden.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Zwölfte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 12: \n");
		printf("Die deutliche Sehweite ist die Distanz zwischen Nahpunkt und Auge.\n");
		printf("1 Wahr\n");
		printf("2 Falsch\n");
		printf("3 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
						 
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : return 0;
					break;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 3) || ( answer < 1));
		
		
		//Dreizehnte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 13: \n");
		printf("Eine sphaerische Sammellinse wird als Lupe verwendet. Mit Hilfe der Lupe wird die deutliche Sehweite\n");
		printf("von 25cm auf 10cm verkleinert. Wie gross ist die Brennweite der Lupe\?\n");
		printf("1 0,3m\n");
		printf("2 0.1666m\n");
		printf("3 0.1m\n");
		printf("4 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 :printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 3 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 4 : return 0;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 4) || ( answer < 1));
		
		
		
		//Vierzehnte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 14: \n");
		printf("Ein Gegenstand befindet sich 12cm vor einem Konkavspiegel und 4cm oberhalb von dessen Achse.\n");
		printf("Der Spiegel hat einen Kruemmungsradius von 6cm. Wie gross ist die Bildweite b\?\n");
		printf("1 4cm\n");
		printf("2 3cm\n");
		printf("3 6cm\n");
		printf("4 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 4 : return 0;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 4) || ( answer < 1));
		
		
		//Fünfzehnte Frage Alles
		answer = 0;
		do{
		printf("\nFrage 15: \n");
		printf("Eine bikonvexe duenne Linse besteht aus Glas mit der Brechzahl n = 1,5. Ihre Kruemmungsradien sind 10cm und 15cm.\n");
		printf("Wie gross ist die Brennweite b\?\n");
		printf("1 12cm\n");
		printf("2 9cm\n");
		printf("3 6cm\n");
		printf("4 Quiz abbrechen\n");
		scanf("%d",&answer);
		fflush(stdin);
			switch(answer){
				case 1 : printf("Sehr gut du hast 1 Punkt fuer diese Aufgabe erhalten!\n\n");
						 points ++;
					break;
				case 2 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 3 : printf("Falsch!! 0 Punkte kriegst du hier fuer!\n\n");
					break;
				case 4 : return 0;
				default: printf("Falsche Eingabe!!!\n\n\n");
			}
		} 
		while ((answer > 4) || ( answer < 1));
		
		perAlles = ((float)points * 100) / 15;
		float points1 = ((float)points / 15) * 5 + 1;
		printf("\n\nDu hast das Quiz beendet und hast folgende Note erreicht: %f\n",points1);
		printf("Dies ist folgendes in Prozent: %f %%\n\n\n",perAlles);
		printf("\nDu  kannst nun ein weiteres Quiz spielen oder das Quiz beenden:\n");
		ovraper = (perSpiegel + perOberfl + perLins + perAlles) / 5;
		
		return 0;
	}	