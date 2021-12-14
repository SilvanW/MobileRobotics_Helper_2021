/* (DateiName)
(kurze Beschreibung des Programms)
Autor: Joel Flepp
Firma: HTW Chur/Mobile Robotics
Version: 
Datum: 
Änderungen:
*/

// Einbinden von Headerdateie der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




//Definition Globale Variabeln


//Definition Programm interne Funktionen
void zeichnung(int G, int g, int f, int B, int b, int S);
void berechnung(int G, int g, int f, int *B, int *b);


//Mit main beginnt unser Programm.
int main()
{
//Defnition von variablen

//Berechnungsvariabeln
	int G=0;
	int g=0;
	int B=0;
	int b=0;
	int f=0;
	float V=0;
	int S=0; //Spiegelart: 2=Konkav, 3=Konvex
	
//ProgrammVariabeln
	char AktZeit[6] ={};	
	char Lauf1=0;
	char Zeit[60]={};
	int FreiSch=0;
	char Passwort[50]={};
	char SpiegArt[10]={};
	int Start=0;

//Definition Zeit:
	time_t now;
	now = time(0);
	
	for (Lauf1=0; Lauf1<5; Lauf1++)
	{
		AktZeit[Lauf1] = ctime(&now)[11+Lauf1];
	}




//Entscheidung wie spät es ist
	if (AktZeit[0]==48 && AktZeit[1]<55)
	{
		printf("Was machst du so spaet in der Nacht??\nEs ist verdammt nochmal %s\nAlso geh Schalfen!!!\n\n",AktZeit);
	}
	else if (AktZeit[0]==48 && AktZeit[1]>=55)
	{
		printf("Guten Morgen es ist %s, Zeit fuer Optik JUHU\n",AktZeit);
		FreiSch=1;
	}
	else if (AktZeit[0]==49 && AktZeit[1]<51)
	{
		printf("Um die Mittagszeit am %s, ist die Perfekte Zeit fuer Optik:)\n",AktZeit);
		FreiSch=1;
	}
	else if (AktZeit[0]==49 && AktZeit[1]>=51)
	{
		printf("E ist %s, jetz aber schnell Optik lernen!!\n",AktZeit);
		FreiSch=1;
	}
	else if (AktZeit[0]==50)
	{
		printf("Nun da der Tag schon fast gelaufen ist, bringt es auch nichts mehr zum lernen\n");
		printf("Aber zum Glueck ist %s die Perfekte Zeit um ein Bier zu trinken also prost\n\n",AktZeit);
	}

//***********************************************************************************************************
//Falls der Opitkrechner in der Nacht eingeschaltet wird, muss ein PW eingegeben werden!	
//***********************************************************************************************************

	if (FreiSch==0)
	{
		printf("Wenn du den Optik rechner trotzdem benutzen moechtest, bitte den Streberpasswort eingeben: ");
		fflush(stdin);
		scanf("%50[^\n]s", Passwort);
		
		if (strcmp(Passwort, "Ich liebe Optik")==0)
		{
			printf("Nagut du Optikstreber, du darfst den Optikrechner nutzen\n");
			FreiSch=1;
		}
		else 
		{
			printf("Leider Falsch :( Tschau\n");
		}
	}
//***********************************************************************************************************
//Falls das Programm Freigeschaltet wurde, werden hier die gegebenen Daten eingelesen
//***********************************************************************************************************
	if (FreiSch==1)
	{
		printf("\nNungut, genug herumgetroedelt nun wird gearbeitet.\n\n");
		
	//Gegenstand Eingabe	
		printf("Gegenstand eingeben (1-10) \t\tG= ");
		fflush(stdin);
		scanf("%i", &G);
		
	//Gegenstandsweite Eingabe
		printf("Gegenstandsweite eingeben (1-40) \tg= ");
		fflush(stdin);
		scanf("%i", &g);
		
	//Brennweite Eingabe
		printf("Brennweite Eingeben  \n");
		printf("Bei Konkav f>0 und bei Konvex f<0 \tf= ");
		fflush(stdin);
		scanf("%i", &f);
		
	//fals ein üngültiger Wert eingelesen wird, wird kein Programm gestartet und das Programm wird beendet
		if ((G==0) || (G>10) || (g==0) || (g>40) || (f==0))
		{
			printf("Ungueltige Angabe! Tschau\n");
			Start=1;
		}
		else 
		{
			Start=0;
		}

//*********************************************************************************************
//Berechnung von B und b
//*********************************************************************************************	
		berechnung( G, g, f, &B, &b);
		V=B/G;

//*********************************************************************************************
//Spiegelauswahl und Start der jeweiligen Funktion
//*********************************************************************************************	
		if (Start==0)
		{
			if (f>0)
			{
				printf("\nSie haben einen Konkaven Spieghel\n\n");
				S=2;
				zeichnung(G, g, f, B, b, S);
			}
			else if (f<0)
			{
				printf("\nSie haben einen Konvexen Spieghel\n\n");
				S=3;
				zeichnung(G, g, f, B, b, S);
			}
			//Ausgabe der Werte
			printf("\nBildweite= %i\n", b);
			printf("Bild= %i\n", B);
			printf("Vergroesserung= %i\n", V);
		}
	}
		

	system("pause");	
	// Rückgabewert, dass das Programm erfolgreich beendet wurde.
	return 0;
}

void zeichnung(int G, int g, int f, int B, int b, int S)
{
	
	int Lauf1=0;
	int Lauf2=0;
	int Lauf3=0;
	int Lauf4=0;
	int StrG=0; //Falls ein Strich in dieser Zeile Vorkommt, wird der integer auf 1 erhöht
	int StrB=0;
	int AbsGe=50-g;
	int AbsBi=50-b;
	int bplus=0;
	int Bplus=0;
	int BOORp=1; //Bild out of Range wenn oben kein Bild -1 
	int BOORn=1; //Bild out of Range wenn unten ein Bild -1

	
	//Falls Bildweite negativ wird er hier umgewandelt
	if (b<0)
	{
		bplus=-b;
	}
	else
	{
		bplus=b;
	}
	
	//Das Gleiche mit der Bilhöhe
	if (B<0)
	{
		Bplus=-B;
	}
	else 
	{
		Bplus=B;
	}
	
	printf("Die Zeichnung sieht wie folgt aus: (Es ist natuerlich nur eine Annaeherung^^)\n\n\n");
	//Spieghel erstellen	
	//Über bzw Unter der Optischen Achse
	for (Lauf1=0; Lauf1<2; Lauf1++)
	{
		//Nächse Zeile 
		for (Lauf2=0; Lauf2<10; Lauf2++)
		{
			//Falls es der erste durchlauf ist, wird für die Gegenstandhöhe berechnet
			if(Lauf1==0)
			{
				//Falls die Zeile kleiner gleich Die Gegenstandhöhe ist, wird der integer auf 1 
				//gewechselt und so wird in der Zeile in derrichtigen Stelle ein Strich gemacht
				if (10-Lauf2<=G)
				{
					StrG=1;
				}
				else
				{
					StrG=0;
				}
				//Falls das Bild hinter dem Spiegel ist wird hier Die höhe Berechnet
				if (b<0 && (10-Lauf2<=Bplus))
				{
					StrB=1;
				}
				else
				{
					StrB=0;
				}
			}
			//Beim zweiten Durchlauf
			else 
			{
				if (b>0 && Bplus>=Lauf2)
				{
					StrB=1;
				}
				else
				{
					StrB=0;
				}
			}
			
			//Beim ersten durchlauf wird vor dem Spieghel der Gegensgtand gemacht
			if (Lauf1==0)
			{
				//Anzahl Abstände bis zum Spiegelauswahl
				//Wenn Strich gleich 1 und der richtige Abstand ist, wird ein strich gemacht
				for (Lauf3=0; Lauf3<49; Lauf3++)
				{
					if (Lauf3==AbsGe && StrG==1 && Lauf1==0)
					{
						printf("|");
						StrG=0;
					}

					else
					{
						printf(" ");
					}
				}
			}
			
			//Beim zweiten, wird das Bild gemacht falls es existiert
			else
			{
				for (Lauf3=0; Lauf3<49; Lauf3++)
				{
					if (Lauf3==AbsBi && StrB==1 && Lauf1==1)
					{
						printf(":");
						StrB=0;
						BOORn=0;
					}

					else
					{
						printf(" ");
					}
				}
			}

			
			//Beim Ersten Durchlauf, wird für jede Zeile ein Abstand mehr gemacht
			if ((Lauf1==0 && S==2) || (Lauf1==1 && S==3))
			{
				//Es werden soviele Abstände gemacht wie die Anzahl Zeilen in der man ist
				for (Lauf4=0; Lauf4<Lauf2; Lauf4++)
				{
					printf(" ");
				}
			}
			//Beim zweiten Durchlauf werden die Abstände nach jeder Zeile um eins weniger
			else if ((Lauf1==1 && S==2) || (Lauf1==0 && S==3))
			{
				//Pro Zeile wird jeweils einen Abstand weniger gemacht
				for (Lauf4=9; Lauf4>Lauf2; Lauf4--)
				{
					printf(" ");
				}
			}
			

			//Beim ersten Durchlauf werden Backslashes gemacht bei konkav bei konvex werden sie beim zweiten durchlauf gemacht
			if ((Lauf1==0 && S==2) || (Lauf1==1 && S==3))
			{
				printf("\\");
				//Leerschläge damit keine Striche noch im Spiegel
				for (Lauf4=9; Lauf4>Lauf2; Lauf4--)
				{
					printf(" ");
				}
			}
			//Beim zweiten Durchlauf werden slashes gemacht bei Konkav bzw beim ersten Durchlauf Konvex
			else if ((Lauf1==1 && S==2) || (Lauf1==0 && S==3))
			{
				printf("/");
				//Leerschläge damit keine Striche im Spiegel
				for (Lauf4=0; Lauf4<Lauf2; Lauf4++)
				{
					printf(" ");
				}
			}

			
			//Hier wird das gleiche mit dem Bild gemacht
			//Wenn der Zähler gleich ist wie die Bildweite und ein Strich gemachtwerden soll, macht er ein Strich
			for (Lauf4=0; Lauf4<50; Lauf4++)
			{
				if (Lauf4-10==bplus+20-10*S && StrB==1 && Lauf1==0)
				{
					printf(":");
					StrB=0;
					BOORp=0;
				}
				
				else
				{
					printf(" ");
					
				}
			}
			//Nachdem Das Bild gemacht wurde, wird ein Enter gemacht
			printf("\n");
		}
		//Hier wird beim ersten Durchlauf die Optische Acshe gemacht
		if (Lauf1==0)
		{
			//Beim Ersten durchlauf werden Striche gemacht und ein | danach werden nochamsl Striche gemacht jedoch mit einem \n am Schluss
			for(Lauf3=0;Lauf3<2;Lauf3++)
			{
				
				for(Lauf4=0;Lauf4<81-11*S;Lauf4++)
				{
					printf("-");
				}
				if (Lauf3==0)
				{
					printf("|");
				}
				else
				{
					printf("\n");
				}
			}
		}
	}

	if ((BOORn+BOORp)==2)
	{
		printf("Bild ausserhalb der Zeichnung\n");
	}

}


void berechnung(int G, int g, int f, int *B, int *b)
	{
	//b berechnen
	if (f!=g)
	{
		*b=((-f)*g)/(f-g);	
		*B=(-1*(*b)*G)/g;

	}
	else 
	{
		printf("Kein Bild\n");
		*b=0;
		*B=0;
	}
}