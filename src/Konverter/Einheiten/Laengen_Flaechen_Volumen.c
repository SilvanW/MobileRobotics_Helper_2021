/*
 ============================================================================
 Name        : Laengen_Flaechen_Volumen.c
 Author      : Lukas Ospelt
 Version     :
 Copyright   : 
 Description : 
 ============================================================================
 */
 
#include <stdio.h> 
#include <stdlib.h>	
#include <string.h>

#include "Laengen_Flaechen_Volumen.h"

void meter_to_feet(float input)
{
	float output;
	output = input * 3.28084;
	printf("%.3f Meter = %.3f Feet\n", input, output);
	return;
}
void feet_to_meter(float input)
{
	float output;
	output = input * 0.3048;
	printf("%.3f Feet = %.3f Meter\n", input, output);
	return;
}
void squaremeter_to_squarefeet(float input)
{
	float output;
	output = input * 10.7639;
	printf("%.3f Quadratmeter = %.3f Quadratfeet\n", input, output);
	return;
}
void squarefeet_to_squaremeter(float input)
{
	float output;
	output = input * 0.092903;
	printf("%.3f Quadratfeet = %.3f Quadratmeter\n", input, output);
	return;
}
void cubicmeter_to_cubicfeet(float input)
{
	float output;
	output = input * 35.3147;
	printf("%.3f Kubikmeter = %.3f Kubikfeet\n", input, output);
	return;
}
void cubicfeet_to_cubicmeter(float input)
{
	float output;
	output = input * 0.0283168;
	printf("%.3f Kubikfeet = %.3f Kubikmeter\n", input, output);
	return;
}
void liter_to_gallon(float input)
{
	float output;
	output = input * 0.219969;
	printf("%.3f Liter = %.3f Gallon\n", input, output);
	return;
}
void gallon_to_liter(float input)
{
	float output;
	output = input * 4.54609;
	printf("%.3f Gallon = %.3f Liter\n", input, output);
	return;
}

