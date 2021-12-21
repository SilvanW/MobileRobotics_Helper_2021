/*
 ============================================================================
 Name        : Einheiten_Konverter.c
 Author      : Lukas Ospelt
 Version     : 1.0
 Copyright   : 
 Description : Einheiten Umrechner
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Laengen_Flaechen_Volumen.h"
#include "angle_converter.h"
#include "druck_converter.h"
#include "geschwindigkeit_converter.h"
#include "temperatur_converter.h"
#include "weight_converter.h"

void Einheiten_Konverter(void);

int main(void)
{
	Einheiten_Konverter();
	return 0;
}

void Einheiten_Konverter(void)
{ 
	int auswahl1,auswahl2;
	float wert;
	char erneut;
	
	do
	{
		printf("\nWas moechten Sie konvertieren?\n\nLaengen(1)\nFlaechen(2)\nVolumen(3)\nWinkel(4)\nGeschwindigkeit(5)\nGewicht(6)\nTemperatur(7)\nDruck(8)\n\n");
		printf("Auswahl: ");
		scanf("%d",&auswahl1);
		fflush(stdin);
		printf("\n");

		switch(auswahl1)
		{
			case 1:
				printf("Was moechten Sie konvertieren?\n\nMeter in Feet(1)\nFeet in Meter(2)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Meter eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					meter_to_feet(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Feet eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					feet_to_meter(wert);//Funktionsaufruf
					break;
				}	
			break;

			case 2:
				printf("Was moechten Sie konvertieren?\n\nQuadratmeter in Quadratfeet(1)\nQuadratfeet in Quadratmeter(2)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Quadratmeter eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					squaremeter_to_squarefeet(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Quadratfeet eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					squarefeet_to_squaremeter(wert);//Funktionsaufruf
					break;
				}
			break;

			case 3:
				printf("Was moechten Sie konvertieren?\n\nKubikmeter in Kubikfeet(1)\nKubikfeet in Kubikmeter(2)\nLiter in Gallon(3)\nGallon in Liter(4)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Kubikmeter eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					cubicmeter_to_cubicfeet(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Kubikfeet eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					cubicfeet_to_cubicmeter(wert);//Funktionsaufruf				
					break;
					case 3:
					printf("Bitte Wert in Liter eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					liter_to_gallon(wert);//Funktionsaufruf
					break;
					case 4:
					printf("Bitte Wert in Gallon eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					gallon_to_liter(wert);//Funktionsaufruf				
					break;
					
				}
			break;
							
			case 4:
				printf("Was moechten Sie konvertieren?\n\nGrad in Radiant(1)\nRadiant in Grad(2)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Grad eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					degrees_to_radians(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Radiant eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					radians_to_degrees(wert);//Funktionsaufruf
					break;
				}	
			break;

			case 5:
				printf("Was moechten Sie konvertieren?\n\nMeter pro Sekunde in Kilometer pro Stunde(1)\nKilometer pro Stunde in Meter pro Sekunde(2)\nMeter pro Sekunde in Meilen pro Stunde(3)\nMeilen pro Stunde in Meter pro Sekunde(4)\nKilometer pro Stunde in Meilen pro Stunde(5)\nMeilen pro Stunde in Kilometer pro Stunde(6)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Meter pro Sekunde eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					mps_to_kmph(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Kilometer pro Stunde eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					kmph_to_mps(wert);//Funktionsaufruf
					break;
					case 3:
					printf("Bitte Wert in Meter pro Sekunde eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					mps_to_mph(wert);//Funktionsaufruf
					break;
					case 4:
					printf("Bitte Wert in Meilen pro Stunde eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					mph_to_mps(wert);//Funktionsaufruf
					break;
					case 5:
					printf("Bitte Wert in Kilometer pro Stunde eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					kmph_to_mph(wert);//Funktionsaufruf
					break;
					case 6:
					printf("Bitte Wert in Meilen pro Stunde eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					mph_to_kmph(wert);//Funktionsaufruf
					break;
				}
			break;

			case 6:
				printf("Was moechten Sie konvertieren?\n\nKilogramm in Ounces(1)\nOunces in Kilogramm(2)\nKilogramm in Pounds(3)\nPounds in Kilogramm(4)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Kilogramm eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					kg_to_oz(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Ounces eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					oz_to_kg(wert);//Funktionsaufruf
					break;
					case 3:
					printf("Bitte Wert in Kilogramm eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					kg_to_lb(wert);//Funktionsaufruf
					break;
					case 4:
					printf("Bitte Wert in Pound eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					lb_to_kg(wert);//Funktionsaufruf
					break;
				}
			break;
			
			case 7:
				printf("Was moechten Sie konvertieren?\n\nCelsius in Kelvin(1)\nCelsius in Fahrenheit(2)\nKelvin in Celsius(3)\nKelvin in Fahrenheit(4)\nFahrenheit in Celsius(5)\nFahrenheit in Kelvin(6)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Celsius eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					celsius_to_kelvin(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Celsius eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					celsius_to_farenheit(wert);//Funktionsaufruf
					break;
					case 3:
					printf("Bitte Wert in Kelvin eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					kelvin_to_celsius(wert);//Funktionsaufruf
					break;
					case 4:
					printf("Bitte Wert in Kelvin eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					kelvin_to_farenheit(wert);//Funktionsaufruf
					break;
					case 5:
					printf("Bitte Wert in Fahrenheit eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					farenheit_to_celsius(wert);//Funktionsaufruf
					break;
					case 6:
					printf("Bitte Wert in Fahrenheit eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					farenheit_to_kelvin(wert);
//Funktionsaufruf
					break;
				}
			break;

			case 8:
				printf("Was moechten Sie konvertieren?\n\nBar in Pascal(1)\nPascal in Bar(2)\nBar in PSI(3)\nPSI in Bar(4)\nPascal in PSI(5)\nPSI in Pascal(6)\n\n");
				printf("Auswahl: ");
				scanf("%d", &auswahl2);
				fflush(stdin);
				printf("\n");
				switch(auswahl2)
				{
					case 1:
					printf("Bitte Wert in Bar eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					bar_to_pascal(wert);//Funktionsaufruf
					break;
					case 2:
					printf("Bitte Wert in Pascal eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					pascal_to_bar(wert);//Funktionsaufruf
					break;
					case 3:
					printf("Bitte Wert in Bar eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					bar_to_psi(wert);//Funktionsaufruf
					break;
					case 4:
					printf("Bitte Wert in PSI eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					psi_to_bar(wert);//Funktionsaufruf
					break;
					case 5:
					printf("Bitte Wert in Pascal eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					pascal_to_psi(wert);//Funktionsaufruf
					break;
					case 6:
					printf("Bitte Wert in PSI eingeben: ");
					scanf("%f",&wert);
					fflush(stdin);
					printf("\n");
					psi_to_pascal(wert);//Funktionsaufruf
					break;
				}
			break;		
		}
		printf("\nErneut? (j/n)?\n");
		scanf("%c",&erneut);
		fflush(stdin);
		
	}	while(erneut=='j');	
	return;
}


