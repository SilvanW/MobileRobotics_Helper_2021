/* zahlenkonverterV0.4.c
Programm welches Zahlen konvertieren kann
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
V0.5 Hinzufügen der Option "Andere..."
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include "zahlenkonverter.h"

/////////////////////////////////
// Private Function Prototypes //
/////////////////////////////////

static void GetStringFromUser(char *str, size_t size); //Eingabefunktion
static void PrintAsBinary64(long long int zahl); //Ausgabe als Binärzahl


//////////////////////////////////////
/// Public Function Implementations //
//////////////////////////////////////

/**
 * @brief the Number Converter program
 */
void NumberConverter(void)
{
	//Parameter
	char *endptr = 0; //Init
	char input[70];   //Init Eingabewert
	ConverterTypes InputBase = 0; //Init Enum Basis des Eingabewertes
	int InputFunktBase = 0; //Basis des Eingabewertes für Funktion
	bool running = true;
	
	//Auswahl der Basis
	GetStringFromUser(0, 10);

	for(;;) //Endlosloop
	{
		//Eingabe der Basis von Eingabezahl (input)
		for(;;)
		{
			printf("Waehle die Eingabebasis:\n");
			printf("0: (Abbrechen)\n");
			printf("1: Dezimalzahl\n");
			printf("2: Binaerzahl\n");
			printf("3: Hexadezimalzahl\n");
			printf("4: Andere...\n");
			printf("Ihre Eingabe: ");
			// lies ein String vom Benutzer ein
			GetStringFromUser(input, sizeof(input));
			// konvertiere diesen String zu einer Ganzzahl
			InputBase = strtol(input, &endptr, 10);
			// überprüfe auf allfällige falsche Benutzung
			if(*endptr != 0 || InputBase > CONV__COUNT)
			{
				printf("Falsche Eingabe!\n");
			}
			else
			{
				break;
			}
		}
		//_Switch Case für Basiswahl
		switch (InputBase)
		{
			case CONV_DECIMAL: {
				printf("Eingabe als Dezimalzahl: ");
				InputFunktBase = 10;	// Basis 10
			} break;
			case CONV_BINARY: {
				printf("Eingabe als Binaerzahl: ");
				InputFunktBase = 2;		// Basis 2
			} break;
			case CONV_HEXADECIMAL: {
				printf("Eingabe als Hexadezimalzahl: ");
				InputFunktBase = 16;	// Basis 16
			} break;
			case CONV_OTHER: {
				printf("Basis (maximal 36): ");
				GetStringFromUser(input, sizeof(input));
				InputFunktBase = strtoul(input, &endptr, 10);
				printf("Eingabe der Zahl mit Basis %d: ", InputFunktBase);
			} break;
			case CONV_EXIT: {
				running = false;
			} break;
			default: break;
		}
		if(!running) break;
		
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
		if(*endptr != 0 && InputBase == CONV_DECIMAL)
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
		if(*endptr == 0 && errno != ERANGE) //Überprüfen mit letztem Zeichen (bei String: 0)
		{
			//Ausgabe der konvertierten Eingabezahl
			printf("---------------------------------\n");
			printf("64 bit Wert als Ganzzahl -------- %lld\n", KonvInputI64); //Ausgabe in Ganzzahl
			printf("32 bit Wert als Ganzzahl -------- %ld\n", KonvInputI32); //Ausgabe in Ganzzahl
			printf("64 bit Wert als Hexadezimal ----- 0x%llx\n", KonvInputI64); //Ausgabe in hex
			printf("32 bit Wert als Hexadezimal ----- 0x%lx\n", KonvInputI32); //Ausgabe in hex
			printf("64 bit Wert als Binaer ---------- ");
			PrintAsBinary64(KonvInputI64);
			printf("\n");
			printf("32 bit Wert als Binaer ---------- ");
			PrintAsBinary64((unsigned long int)KonvInputI32);
			printf("\n");
			printf("64 bit Wert als Fliesskommazahl - %.52f\n", KonvInputF64); //Ausgabe in Fliesskommazahl
			printf("32 bit Wert als Fliesskommazahl - %.23f\n", KonvInputF32); //Ausgabe in Fliesskommazahl
			printf("---------------------------------\n");
		}
		else
		{
			printf("Ihre Eingabe war etwas schwierig zu verstehen :)\n");
		}

    	printf("\n");
	}
	return;
}

//////////////////////////////////////
// Private Function Implementations //
//////////////////////////////////////

/**
 * @brief Prints a number as a binary one
 * 
 * @param zahl the input number
 */
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
    printf("0b"); //grosser Abstand für gleichmässige Darstellung
    while(count != 0)
    {
		// Bitmaskierungszeugs
		unsigned long long int maske = ((unsigned long long int)1 << (count - 1));
		int bit = (0 != (zahl & maske));
		// Ausgabe
		printf("%d", bit);
		count--;
		if(count % 4 == 0)
		{
			printf(" ");	// ein Abstand zur besseren Darstellung :)
		}
    }
}

/**
 * @brief Get a String From the User
 * 
 * @param str the char* array to write to
 * @param size size of the str in bytes
 */
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
	// fflush(stdin);		// just in case, flushe stdin
}


