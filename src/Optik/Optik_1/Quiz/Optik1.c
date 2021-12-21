/*
Titel: 			Optik1.c
Version: 		V3
Team: 			Katrin, Lukas, Roman, Roger
Teamleiter: 	Roger
Erstellt: 		13.12.2021
Beschreibung: 
				Es werden Fragen zum Thema Optik gestellt (multiple choice, mit 1,2 oder 3 zu beantworten)
				nach jeder frage gibt es die möglichkeit, den test zu beenden
				(Diese Funktion kann auskommentiert werden (Zeile 75))
				am Ende wird die Punktzahl auf die konsole ausgegeben
*/

//---Files einbinden--------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//--- Eigene Datentypen-----------------------------
 struct Task{
	 char Question[200];
	 char Option1[200];
	 char Option2[200];
	 char Option3[200];
	 int Solution;
 };
	 


//---Funktions Prptotypen--------------------------
int askQuestion(int);
int getNextAction(void);
void storeStrings(void);

//---Globale Variablen-----------------------------
struct Task Fragenkatalog[12];

const int NumberOfQsts = 12;
const int AnotherQst = 1;
const int CancelTest = 2;

/*-------------------------------------------
  Optik1_Quiz
---------------------------------------------
 Funktion, die aus dem Main heraus aufgerufen werden kann.
 Das Quiz wird gestartet.
*/
int Optik1_Quiz (void){
	//Variablen definieren
	int CNT_correctAnsw = 0;
	int Qst_CNT = 0;
	int Abbruch = 0;
	int next;	
	
	//Fragen und Antwoertmoeglichkeiten strukturieren
	storeStrings();
	
	//Fragen durchgehen
	while((Abbruch == 0)&&(Qst_CNT < NumberOfQsts)){
		//Ausgabe & Antwort-Eingabe
		if (askQuestion(Qst_CNT)){			//Funktionsaufruf: Fragestellung und Antworteingabe
			CNT_correctAnsw ++;				// + 1 richtige Antwort
		}
		//Abfrage - "naechste Frage" oder "Abbruch"
		if(Qst_CNT != 12){					//Nächster Schritt soll bei letztem Durchlauf nichtmehr abgefragt werden
			next = getNextAction();			//Abfrage - "naechste Frage" oder "Abbruch"
			if(next == AnotherQst){
				Qst_CNT ++;					//Zur naechsten Frage wechseln
			}else if(next == CancelTest){				
				Abbruch = 1;				// Test Abbrechen
			}
		}
		/*
		Alternativ, wenn abbruchmöglichkeit nicht bestehn soll:
		//folgende Zeile einfügen dafür letztes IF mit gesamten Inhalt auskommentieren.
		Qst_CNT++; Zur nächsten Frage wechseln
		*/
	}
	
	//Ausgabe von Resultat
	printf("\n\n-------------------------------------------------------------------------\n");
	printf("Test Optik abgeschlossen.\n");
	printf("   Sie haben %d von 12 Aufgaben richtig geloest!\n", CNT_correctAnsw);
	printf("-----------------------------------------------------------------------\n\n");

	return 0;
}


/*-------------------------------------------
	askQuestion
---------------------------------------------
 In dieser Funktion wird die aktuelle Frage auf der Konsole gestellt und es erscheint die Eingabeaufforderung
 für die Antwort. Dazu wird direkt überprüft, ob eine gültige antwort gegeben wurde, und ob diese stimmt.
 Übergabe: Qst_CNT --> die Wievielte frage wird aktuell bearbeitet
 Rückgabe: 	1 --> Frage richtig beantwortet
			0 --> Frage falsch beantwortet
*/
int askQuestion(int Qst_CNT){
	int Eingabe = 0;
	int Check=0;
	
	//Frage und Antwortmoeglichkeiten auf Konsole ausgeben
	printf("-----------------------------------------------------------------------------------\n");
	printf("\n%s\n", Fragenkatalog[Qst_CNT].Question);
	printf("   1: %s\n", Fragenkatalog[Qst_CNT].Option1);
	printf("   2: %s\n", Fragenkatalog[Qst_CNT].Option2);
	printf("   3: %s\n", Fragenkatalog[Qst_CNT].Option3);
	//Eingabeaufforderung fuer Antwort
	printf("Antwort:");
	fflush(stdin);			
	Check = scanf("%d", &Eingabe);
	printf("\n");
	fflush(stdin);
	
	//Sicherstellen, dass gültige Eingabe gemacht wurde
	while((Check == 0) || (Eingabe < 1) || (Eingabe > 3)){
		printf("Eingabefehler\n");
		printf("Geben Sie 1,2 oder 3 ein!\n");
		fflush(stdin);
		Check = scanf("%d", &Eingabe);
		fflush(stdin);
	}
	
	//Kontrolle von Loesung
	if (Eingabe == Fragenkatalog[Qst_CNT].Solution){
		printf("Richtig\n");
		return 1;	//1 --> Antwort war richtig
	}else{
		printf("Falsch\n");
		printf("die richtige Antwort waere %d\n",Fragenkatalog[Qst_CNT].Solution);
		return 0;	//0 --> Antwort war falsch
	}
}


/*-------------------------------------------
 getNextAction
-------------------------------------------
 Diese Funktion wird nach jeder Frage aufgerufen.
 Es wird abgefragt, ob die nächste Frage angezeigt oder der test abgebrochen werden soll.
 Übergabe: keine
 Rückgabe: 	CancelTest (=2) oder AnotherQst (=1)
			oder 0 --> Fehler
*/
int getNextAction(void){
	char Input = 0;
	int Check = 0;
	
	//Eingabeaufforderung
	printf("-------------------------------\n");
	printf("fuer naechste Frage: 'n'\n");
	printf("Test abbrechen: 'x'\n");	
	//Eingabe
	Check = scanf("%c", &Input);
	fflush(stdin);
	
	//Sicherstellen, dass gültige Eingabe gemacht wurde
	while( (Check == 0) || ((Input != 'x') && (Input != 'n')) ){
		printf("Eingabefehler\n");
		printf("Geben Sie 'x' oder 'n' ein!\n");
		Check = scanf("%c", &Input);
		fflush(stdin);
	}
	
	//Eingabe zurückgeben
	if(Input == 'x'){
		return CancelTest;
	}else if(Input == 'n'){
		return AnotherQst;
	}else{
		return 0;
	}
}


/*-------------------------------------------
 storeStrings
---------------------------------------------
 Alle Fragen, Antwortmöglichkeiten und Lösungen werden hier in das Array "Fragenkatalog"
 des Datentyps "Task" eingespeichert.
*/
void storeStrings(void){
	//Frage1	
	strcpy( Fragenkatalog[0].Question, "Das Snelius Brechnungsgesetzt beschreibt (n_1*sin⁡(Teta_1=n_2*sin⁡(Teta_2))):" );
	strcpy( Fragenkatalog[0].Option1, "die Brechung eines Lichtstrahls an einer Grenzflaeche zweier Medien" );
	strcpy( Fragenkatalog[0].Option2, "die Spektraleigenschaften des Lichtes" );	
	strcpy( Fragenkatalog[0].Option3, "die Lateralvergroesserung fuer sphaerische Spiegel und Linsen" );	
	Fragenkatalog[0].Solution = 1;
	
	//Frage2	
	strcpy( Fragenkatalog[1].Question, "Die Lichtgeschwindigkeit ist eine Konstante:" );
	strcpy( Fragenkatalog[1].Option1, "ja, jedoch kann sie kleiner sein, wenn gewisse Medien durchflossen werden." );
	strcpy( Fragenkatalog[1].Option2, "nein sie ist je nach Jahreszeit unterschiedlich (Winter ist v tiefer)" );	
	strcpy( Fragenkatalog[1].Option3, "Nein die Lichtgeschwindigkeit ist abhaengig vom Luftdruck." );
	Fragenkatalog[1].Solution = 1;
	
	//Frage3	
	strcpy( Fragenkatalog[2].Question, "Totalreflexion tritt nur auf:" );
	strcpy( Fragenkatalog[2].Option1, "wenn der Uebergang von einem Material zum anderen mit einer tieferen zu einer hoehreren Brechzahl geht" );
	strcpy( Fragenkatalog[2].Option2, "wenn der Uebergang von einem Material zum anderen mit einer hoeheren zu einer kleineren Brechzahl geht" );	
	strcpy( Fragenkatalog[2].Option3, "Die Totalreflexion ist ein Aberglaube und ist ein Teil einer grossen Verschwoerungs Theorie." );
	Fragenkatalog[2].Solution = 2;
	
	//Frage4
	strcpy( Fragenkatalog[3].Question, "Der Kruemmungsradius bei einem sphaerischen Hohlspiegel ist?" );
	strcpy( Fragenkatalog[3].Option1, "negativ" );
	strcpy( Fragenkatalog[3].Option2, "positiv" );	
	strcpy( Fragenkatalog[3].Option3, "unendlich" );
	Fragenkatalog[3].Solution = 2;	
	
	//Frage5	
	strcpy( Fragenkatalog[4].Question, "Koennen bei sphaerischen Woelbspiegeln reelle Bilder entstehen?" );
	strcpy( Fragenkatalog[4].Option1, "Nein, das entstehende Bild ist immer virtuell" );
	strcpy( Fragenkatalog[4].Option2, "Ja, das entstehende Bild ist immer reell" );	
	strcpy( Fragenkatalog[4].Option3, "Je nach Gegenstandsweite koennen reelle oder virtuelle Bilder entstehen" );
	Fragenkatalog[4].Solution = 1;
	
	//Frage6	
	strcpy( Fragenkatalog[5].Question, "Die Abbildungsgleichung an einem sphaerischen Spiegel lautet?" );
	strcpy( Fragenkatalog[5].Option1, "B/G = -b/g" );
	strcpy( Fragenkatalog[5].Option2, "1/g + 1/b = 1/f" );	
	strcpy( Fragenkatalog[5].Option3, "n1/g + n2/b = n2/f" );
	Fragenkatalog[5].Solution = 2;
	
	//Frage7	
	strcpy( Fragenkatalog[6].Question, "Was ist die korrekte Bezeichnung fuer die beiden Linien, die bei Dicken Linsen in die Skizze eingefuegt werden muessen?" );
	strcpy( Fragenkatalog[6].Option1, "Hauptebenen" );
	strcpy( Fragenkatalog[6].Option2, "Brechebenen" );	
	strcpy( Fragenkatalog[6].Option3, "Hilfslinien" );
	Fragenkatalog[6].Solution = 1;
	
	//Frage8	
	strcpy( Fragenkatalog[7].Question, "Welche Aussage ist wahr?" );
	strcpy( Fragenkatalog[7].Option1, "Mindestens eine der Hauptebenen muss innerhalb des Linsenmaterials liegen." );
	strcpy( Fragenkatalog[7].Option2, "Beide Hauptebenen muessen immer innerhalb des Linsenmaterials liegen" );	
	strcpy( Fragenkatalog[7].Option3, "Hat die Linse die Dicke 0mm liegen die beiden Hauptebenen uebereinander" );
	Fragenkatalog[7].Solution = 3;
	
	//Frage9	
	strcpy( Fragenkatalog[8].Question, "Wovon ist die  Position der Hauptebenen NICHT abhaengig?" );
	strcpy( Fragenkatalog[8].Option1, "Brechzahl von Luft und Linsenmaterial" );
	strcpy( Fragenkatalog[8].Option2, "Dicke der Linse" );	
	strcpy( Fragenkatalog[8].Option3, "Position des Objektes, das durch die Linse abgebildet wird" );
	Fragenkatalog[8].Solution = 3;
	
	//Frage10
	strcpy( Fragenkatalog[9].Question, "Mit welcher Linse kann ein kurzsichtiges Auge wieder scharf sehen?" );
	strcpy( Fragenkatalog[9].Option1, "Sammellinse" );
	strcpy( Fragenkatalog[9].Option2, "Zerstreuungslinse" );	
	strcpy( Fragenkatalog[9].Option3, "mit beiden moeglich" );
	Fragenkatalog[9].Solution = 2;
	
	//Frage11	
	strcpy( Fragenkatalog[10].Question, "Wie lautet die Abbildungsgleichung fuer duenne sphaerische Linsen?" );
	strcpy( Fragenkatalog[10].Option1, "1/g + 1/b = 1/f" );
	strcpy( Fragenkatalog[10].Option2, "1/f + 1/b = 1/g" );	
	strcpy( Fragenkatalog[10].Option3, "g + b = f" );
	Fragenkatalog[10].Solution = 1;
		
	//Frage12	
	strcpy( Fragenkatalog[11].Question, "Wie nennt sich die Linsenform, welche auf einer Seite flach und auf der anderen Seite nach aussen gewoelbt ist?" );
	strcpy( Fragenkatalog[11].Option1, "konvex-konkav" );
	strcpy( Fragenkatalog[11].Option2, "konkav-plan" );	
	strcpy( Fragenkatalog[11].Option3, "plan-konvex" );
	Fragenkatalog[11].Solution = 3;
}







