/* Name des Programms.c
Programm das einen Text auf die Konsole ausgibt
Autor: Enrico Pirolt
Firma: HTW Chur/Photonics
Version: 0.0
Datum: 26.10.2021
Änderungen:
0.0 26.10.2021 Erste Version
*/
// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Mit main beginnt unser Programm.



int hangman(void)
{

	//Variablen
char String[] = "differenzial";
int  stringlaenge = strlen(String);
int  wortlaenge= stringlaenge-1;
char gesuchtesWort[wortlaenge];
char eingegebnerBuchstabe;
char run=0;
char buchstabevorgekommen=0;
int hangmanwert = 0;
int laufvariable=0;
int gamestand=0;
int gefundeneBuchstaben=0;
int test=0;
//Galgenteile
int galgenpart1 = 61;
int galgenpart2 = 124;
int galgenpart3 = 124;
int galgenpart4 = 95;
int galgenpart5 = 95;
int galgenpart6 = 95;
int galgenpart7 = 124;
int galgenpart8 = 124;
int galgenpart9 = 111;

//Bibiliothek	


	//Programm
for(int laufvariable=0; laufvariable<stringlaenge; laufvariable++) // Gesuchtes Wort mit ....... füllen und ausgeben
	{
		gesuchtesWort[laufvariable] = '.';
		printf("%c",gesuchtesWort[laufvariable]);
	}
	fflush(stdin);
	printf("\n");


while (run <1)
{
	//kontrolle ob das Wort schon komplett herrausgefunden worden ist oder ob man tot ist
	
	laufvariable=0;
	
	while (laufvariable<stringlaenge) //Auswertung Gewonnen/Gameover
	{
		if (gesuchtesWort[laufvariable] == '.') 
		{
			gefundeneBuchstaben+=0;
		}
		else 
		{
			gefundeneBuchstaben+=1;
		}
		
		
		
		
		if (gefundeneBuchstaben<wortlaenge)
		{
			if (hangmanwert <9)
			{
				gamestand=0; //geht weiter
			}
			else 
			{
				gamestand =1;//Gameover
			}
		}
		else if (gefundeneBuchstaben==stringlaenge)
		{
			if (hangmanwert <9)
			{
				gamestand=2; //Gewonnen
			}
		}
		laufvariable+=1;
	}
	gefundeneBuchstaben=0;
	switch (gamestand) //Game Main
	{
		case 0:
			//Eingabe
			printf("Geben Sie einen Buchstaben ein(kleingeschrieben):\n");
			fflush(stdin);
			scanf("%c", &eingegebnerBuchstabe);
			//Abfrage ob Buchstabe vorhanden ist
			laufvariable=0;
			
			while (laufvariable<stringlaenge)
			{
				if (test ==0)
				{
					if(gesuchtesWort[laufvariable] == eingegebnerBuchstabe)
					{
					printf("Buchstabe schonmal verwendet!\n");
					printf("\n");		
					test=1;
					}
				}
				if (String[laufvariable] == eingegebnerBuchstabe)
				{
					gesuchtesWort[laufvariable] = eingegebnerBuchstabe;
					laufvariable+=1;
					buchstabevorgekommen=1;
				}
				else
				{
					laufvariable+=1;
				}
				
			}
			test=0;
			if (buchstabevorgekommen==0)
				{
					printf("Dein Buchstabe ist nicht im Wort enthalten\n");
					hangmanwert+=1;
					//hangmanpart
					buchstabevorgekommen=0;
					switch (hangmanwert) 
					{
						case 1:
							printf("%c \n",galgenpart1);
							break;
						case 2:
							printf("%c \n",galgenpart2);
							printf("%c \n",galgenpart1);
							break;
						case 3:
							printf("%c \n",galgenpart3);
							printf("%c \n",galgenpart2);
							printf("%c \n",galgenpart1);
							break;
						case 4:
							printf("%c \n",galgenpart4);
							printf("%c \n",galgenpart3);
							printf("%c \n",galgenpart2);
							printf("%c \n",galgenpart1);
							break;
						case 5:
							printf("%c%c \n",galgenpart4,galgenpart5);
							printf("%c \n",galgenpart3);
							printf("%c \n",galgenpart2);
							printf("%c \n",galgenpart1);
							break;
						case 6:
							printf("%c%c%c \n",galgenpart4,galgenpart5,galgenpart6);
							printf("%c \n",galgenpart3);
							printf("%c \n",galgenpart2);
							printf("%c \n",galgenpart1);
							break;			
						case 7:
							printf("%c%c%c \n",galgenpart4,galgenpart5,galgenpart6);
							printf("%c %c \n",galgenpart3,galgenpart7);
							printf("%c \n",galgenpart2);
							printf("%c \n",galgenpart1);
							break;
						case 8:
							printf("%c%c%c \n",galgenpart4,galgenpart5,galgenpart6);
							printf("%c %c \n",galgenpart3,galgenpart7);
							printf("%c %c \n",galgenpart3,galgenpart8);
							printf("%c \n",galgenpart1);
							break;
						case 9:
							printf("%c%c%c \n",galgenpart4,galgenpart5,galgenpart6);
							printf("%c %c \n",galgenpart3,galgenpart7);
							printf("%c %c \n",galgenpart3,galgenpart8);
							printf("%c %c \n",galgenpart3,galgenpart9);
							printf("%c \n",galgenpart1);
							break;	
					}
				}
	
				else
				{
					buchstabevorgekommen=0;
					for(int laufvariable=0; laufvariable<stringlaenge; laufvariable++) // Gesuchtes Wort mit gefundenen buchstaben
						{
						printf("%c",gesuchtesWort[laufvariable]);
						}
			
					printf("\n");
				}
		break;
	
		case 1:
			printf("Gameover \n");
			run =1;
		break;
	
		case 2:
			printf("Gewonnen \n");
			run =1;
		break;
	}
	
}
	//Ausgabe


	return 0;
}