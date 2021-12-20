/* zahlenkonverterV0.4.c
Programm das....
Autor: Raphael Krause
Studiengang: Photonics
Version: 0.2
Datum: 17.12.2021
Änderungen:
V0.1 Erste Version von Krause
V0.2 Korrektur durch Seitz
V0.3 'scanf()' durch 'GetStringFromUser()' ersetzt
V0.4 Verpacken des Binär-Outputs in 'PrintAsBinary64()'
	 Erweitert auf 32 bit und 64 bit Ausgabe
	 Fliesskommazahl Ein- und Ausgabe
	 Enum 'ConverterTypes' hinzugefügt
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include "zahlenkonverter.h"

//Deklaration der Funktionen
static void GetStringFromUser(char *str, size_t size); //Eingabefunktion
static void PrintAsBinary64(long long int zahl); //Ausgabe als Binärzahl

// 
void NumberConverter(void) //Main
{
	//Parameter
	char *endptr = 0; //Init
	char input[70]; //Init Eingabewert
	ConverterTypes InputBase = 0; //Init Enum Basis des Eingabewertes
	int InputFunktBase = 0; //Basis des Eingabewertes für Funktion
	
	//Auswahl der Basis
	GetStringFromUser(0, 10);

	for(;;) //Endlosloop
	{
		//Eingabe der Basis von Eingabezahl (input)
		for(;;)
		{
			printf("Waehle die Eingabebasis: \n");
			printf("0: (Abbrechen) \n");
			printf("1: Dezimalzahl \n");
			printf("2: Binaerzahl \n");
			printf("3: Hexadezimalzahl \n");
			printf("Ihre Eingabe: ");
			// lies ein String vom Benutzer ein
			GetStringFromUser(input, sizeof(input));
			// konvertiere diesen String zu einer Ganzzahl
			InputBase = strtol(input, &endptr, 10);
			// überprüfe auf allfällige falsche Benutzung
			if(*endptr != 0 || InputBase > 3)
			{
				printf("Falsche Eingabe!");
			}
			else
			{
				break;
			}
		}
		//_Switch Case für Basiswahl
		switch (InputBase)
		{
			case DECIMAL: printf("Eingabe als Dezimalzahl: "); break;
			case BINARY: printf("Eingabe als Binaerzahl: "); break;
			case HEXADECIMAL: printf("Eingabe als Hexadezimalzahl: "); break;
			case EXIT: return;
			default: break;
		}
		
		//Switch Case zu Basiszahl zuweisen
		
		if (InputBase ==1)
		{
			InputFunktBase = 10; //Dezimal
		}
		if (InputBase == 2)
		{
			InputFunktBase = 2; //Binär
		}
		if (InputBase ==3)
		{
			InputFunktBase = 16; //Hexadezimal
		}
		
		//Eingabe der Zahl, die konvertiert werden soll
		GetStringFromUser(input, sizeof(input));
		
		//_Umwandlung in long int(Ganzzahl)
		long long int KonvInputI64 = 0;
		long int KonvInputI32 = 0;
		double KonvInputF64 = 0;
		float KonvInputF32 = 0;
		// konvertiere den String zu einer Ganzzahl
		KonvInputI64 = strtoull(input, &endptr, InputFunktBase); //Konvertierungsfunktion
		KonvInputI32 = (long int)KonvInputI64; //Umwandlung zu 32Bit
		
		// überprüfe ob eine Fliesskommazahl eingegeben wurde
		if(*endptr != 0 && InputBase == DECIMAL)
		{
			// konvertiere String zu double (64 bit)
			KonvInputF64 = strtod(input, &endptr);
			KonvInputI64 = *(long long int *)&KonvInputF64;
			// konvertiere String zu float (32 bit)
			KonvInputF32 = strtof(input, &endptr);
			KonvInputI32 = *(long int *)&KonvInputF32;
		}
		else
		{
			// konvertiere die Ganzzahlen zu Float (im bit-Format)
			KonvInputF64 = *(double *)&KonvInputI64;
			KonvInputF32 = *(float *)&KonvInputI32;
		}
		// war die Konvertierung Erfolgreich?
		if(*endptr == 0) //Überprüfen mit letztem Zeichen (bei String: 0)
		{
			//Ausgabe der konvertierten Eingabezahl
			printf("64 bit Wert in Fliesskommazahl:	%.52f \n", KonvInputF64); //Ausgabe in Fliesskommazahl
			printf("32 bit Wert in Fliesskommazahl:	%.23f \n", KonvInputF32); //Ausgabe in Fliesskommazahl
			printf("64 bit Wert in Ganzzahl: %lld \n", KonvInputI64); //Ausgabe in Ganzzahl
			printf("32 bit Wert in Ganzzahl: %ld \n", KonvInputI32); //Ausgabe in Ganzzahl
			printf("64 bit Wert in hex: 0x %llx \n", KonvInputI64); //Ausgabe in hex
			printf("32 bit Wert in hex: 0x %lx \n", KonvInputI32); //Ausgabe in hex
			printf("64 bit Wert in Binaer: ");
			PrintAsBinary64(KonvInputI64);
			printf(" \n");
			printf("32 bit Wert in Binaer: ");
			PrintAsBinary64((unsigned long int)KonvInputI32);
			printf("\n");
		}
		else
		{
			printf("Ihre Eingabe war etwas schwierig zu verstehen :)");
		}

    	printf("");
	}
	return;
}

static void PrintAsBinary64(long long int zahl)
{
	//Umwandlung in Binärzahl und Ausgabe
    unsigned long long int temp = zahl;
    int count = 0;
    // finde anzahl an bits
    do
    {
        temp = temp >> 1;
        count++;
    }
    while(temp != 0 || count % 4 != 0);	// count muss ein multiples von 4 (Tabspace) sein
    // printe als binärzahl
    printf("0b "); //grosser Abstand für gleichmässige Darstellung
    while(count != 0)
    {
		//Zähler für Tabspace zur besseren Darstellung in der Ausgabe
		for (int CountTabspace=0; CountTabspace<4; CountTabspace++) 
		{
			// Bitmaskierungszeugs
			unsigned long long int maske = ((unsigned long long int)1 << (count - 1));
			int bit = (0 != (zahl & maske));
			// Ausgabe
			printf("%d", bit);
			if(count > 0)	// es muss überprüft werden, ob count noch grösser als 0 ist, sonst wird evtl. das 0 übersprungeen
			{
				count--;
			}
		}
		printf(" ");	// ein Abstand zur besseren Darstellung :)
    }
}

//Unterfunktionen
static void GetStringFromUser(char *str, size_t size)
{
	if(!str || !size) return;	// str oder size dürfen nicht 0 sein
	char c = 0;			// das aktuelle Zeichen welches gelesen wird
	size_t read = 0;	// wie viele Zeichen bereits gelesen wurden
	for(;;) 			// Endlos loop
	{
		c = getchar();	// liest ein Zeichen ein
		if(c == EOF || c == '\n')	// sobald das aktuelle Zeichen ein newline oder EOF ist, geh aus dem loop
		{
			break; 		// Endlos loop verlassen
		}
		if(read < size)	// sind noch weniger Zeichen gelesen worden, als die grösse?
		{
			str[read++] = c;	// füge das Zeichen dem String hinzu
		}
	}
	if(read >= size)	// sind mehr zeichen eingelesen worden, als gewollt?
	{
		read--;			// verkürze die Länge
	}
	str[read] = '\0';	// zum Schluss wird der String mit einem Terminator beendet
	fflush(stdin);		// just in case, flushe stdin
}