/******************************************
*project name:	Softwareprojekt
*filename:		main.c
*version:		0.1
*Author:		Lukas Marti
*Firma:			FHGR
*Date:			17.12.2021
*Brief:			
*
*Changelog:		17.12.2021	Creation and first version
******************************************/

//-----------------------------------------------
//Einbinden von bestehenden Modulen
//-----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "elektronikQuiz.h"

//-----------------------------------------------
//Hauptprogramm (wird beim Start ausgeführt)
//-----------------------------------------------
int main(void)
{
    unsigned char punkte = 0;
	punkte = quiz();
	
	return (0);	//Rückgabewert zum Beenden des Programms
}	
