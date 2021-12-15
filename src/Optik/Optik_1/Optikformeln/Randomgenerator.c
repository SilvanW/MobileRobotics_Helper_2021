/*
 * Randomgenerator.c
 * Autor: Rebsamen Adrian
 * Firma: FHGR / Photonics
 * Version: 0.1
 * Datum: 15.12.2021
 * Beschreibung: Hier werden die Fragen durchmischt, gestellt und zum Schluss ein Logfile ausgegeben.
 * Änderungen:
 * 0.1 15.12.2021 Erste Version
 */

// Inkludieren der Programmbibliotheken
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int Randomgenerator(void)
{
	char Questions[];
	int RandomNr;
	char Quest;


	string Frage_1 = "I am over powered";
	string Frage_2 = "Lost in space";
	string Frage_3 = "cracked up";



	Questions[0] = rand() % 10 + 1;

	do{
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr);
	}
	while(index == -1)
		
	Questions[1] = RandomNr;

	do{
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr);
	}
	while(index == -1)
		
	Questions[2] = RandomNr;

	do{
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr);
	}
	while(index == -1)
		
	Questions[3] = RandomNr;

	do{
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr);
	}
	while(index == -1)
		
	Questions[4] = RandomNr;

	for (int i = 0; i < Questions.size(); i++) 
	{
		Questions[i] = "Frage_%f \n", Questions[i];
		Quest = printf("%s \n" ,Questions[i]);
		printf("%s \n" ,Quest);
	}
	return;
}
