/* Trigonometrie.c
-Spezielle Werte der trigonometrischen Funktionen
-Spezielle Werte der Arcus-Funktionen
Autor: Tim Germann, Yannick Kohler
Firma: FHGR / Mobile Robotics
Version: 0.1
Datum: 13.12.2021
Änderungen: 

0.1 13.12.2021 Version 1*/

// Einbinden von Headerdateien der Programmbibliothek. 
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


//Funktion Vergeichen
int vergleichen(int eingabe, int loesung, int punktzahl)
{
    if ((eingabe==loesung) == 1)
    {
        punktzahl ++;
        printf("-------------------------------------\n");
        printf("richtig\n");
        printf("-------------------------------------\n");
        printf("Punktestand: %d\n",punktzahl);
        printf("-------------------------------------\n\n");


    }
    else 
    {
        printf("-------------------------------------\n");
        printf("falsch\n");
        printf("-------------------------------------\n");
        printf("Punktestand: %d\n",punktzahl);
        printf("-------------------------------------\n\n");

    } 
    return punktzahl;   
}



//Funktion1: Spezielle Werte der trigonometrischen Funktionen
void funktion1(int punktzahl, int eingabe, int loesung, int vergleich)
{	
    //sin

	//Aufgabe 1:
    
    printf("Was ergibt: sin(pi/4)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 3;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 2:
    
    printf("Was ergibt: sin(2pi/3)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 3:

    printf("\nWas ergibt: sin(0)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 4:

    printf("Was ergibt: sin(3pi/4)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 3;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 5:
    
    printf("Was ergibt: sin(pi)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 6:

    printf("Was ergibt: sin(pi/6)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 7:

    printf("Was ergibt: sin(2pi)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 8:

    printf("Was ergibt: sin(pi/2)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 5;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
     
    //Aufgabe 9:

    printf("Was ergibt: sin(3pi/2)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 6;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
       
    //Aufgabe 10:

    printf("Was ergibt: sin(pi/3)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");

    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);  
    
    //Aufgabe 11:

    printf("Was ergibt: sin(5pi/6)\n");
    printf("1: = 0\n");
    printf("2: = 1/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = sqrt(3)/2\n");
    printf("5: = 1\n");
    printf("6: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //cos

    //Aufgabe 12:

    printf("Was ergibt: cos(pi/3)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 13:

    printf("Was ergibt: cos(pi/2)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 5;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 14:

    printf("Was ergibt: cos(pi/6)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);

    //Aufgabe 15:

    printf("Was ergibt: cos(3pi/2)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 5;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);

    

    //Aufgabe 16:

    printf("Was ergibt: cos(3pi/4)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 7;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);

   

    //Aufgabe 17:

    printf("Was ergibt: cos(pi)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 9;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 18:

    printf("Was ergibt: cos(0)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);

    
    //Aufgabe 19:

    printf("Was ergibt: cos(pi/4)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 3;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 20:

    printf("Was ergibt: cos(2pi)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);

    

    //Aufgabe 21:

    printf("Was ergibt: cos(2pi/3)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 6;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 22:

    printf("Was ergibt: cos(5pi/6)\n");
    printf("1: = 1\n");
    printf("2: = sqrt(3)/2\n");
    printf("3: = sqrt(2)/2\n");
    printf("4: = 1/2\n");
    printf("5: = 0\n");
    printf("6: = -1/2\n");
    printf("7: = -sqrt(2)/2\n");
    printf("8: = -sqrt(3)/2\n");
    printf("9: = -1\n");
    
    scanf("%d",&eingabe);
    loesung = 8;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //tan

    //Aufgabe 23:    

    printf("Was ergibt: tan(pi/4)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 3;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);

    //Aufgabe 24:

    printf("Was ergibt: tan(3pi/2)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 5;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);

    //Aufgabe 24:

    printf("Was ergibt: tan(2pi/3)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 6;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 25:

    printf("Was ergibt: tan(pi/6)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 26:

    printf("Was ergibt: tan(0)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 27:

    printf("Was ergibt: tan(3pi/4)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 7;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 28:

    printf("Was ergibt: tan(pi)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");

    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 29:

    printf("Was ergibt: tan(pi/2)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 5;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 30:

    printf("Was ergibt: tan(2pi)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    

    //Aufgabe 31:

    printf("Was ergibt: tan(pi/3)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);    

    //Aufgabe 32:

    printf("Was ergibt: tan(5pi/6)\n");
    printf("1: = 0\n");
    printf("2: = sqrt(3)/3\n");
    printf("3: = 1\n");
    printf("4: = sqrt(3)\n");
    printf("5: = n.v.\n");
    printf("6: = -sqrt(3)\n");
    printf("7: = -1\n");
    printf("8: = -sqrt(3)/3\n");
    
    scanf("%d",&eingabe);
    loesung = 8;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    


    //Auswertung:
    printf("-------------------------------------\n");
    printf("Max Punktzahl: 32\n");
    printf("-------------------------------------\n");
	
	return;
}


//Funktion2: Spezielle Werte der Arcus-Trigonometrie
void funktion2(int punktzahl, int eingabe, int loesung, int vergleich)
{	
	//Aufgabe 1 (arcsin):
    printf("Was ergibt: arcsin(-sqrt(2)/2)\n");
    printf("1: = -pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = pi/6\n");
    
    scanf("%d",&eingabe);
    loesung = 3;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 2 (arcsin):
    printf("Was ergibt: arcsin(1)\n");
    printf("1: = pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = -pi/2\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 3 (arcsin):
    printf("\nWas ergibt: arcsin(-1)\n");
    printf("1: = -pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = pi/6\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 4 (arcsin):
    printf("Was ergibt: arcsin(-1/2)\n");
    printf("1: = -pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = pi/6\n");

    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 5 (arcsin):
    printf("Was ergibt: arcsin(1/2)\n");
    printf("1: = -pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = pi/6\n");
    printf("5: = 0\n");
    printf("6: = -pi/6\n");
    
    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 6 (arcsin):
	printf("Was ergibt: arcsin(0)\n");
    printf("1: = -pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = pi/6\n");
    
    scanf("%d",&eingabe);
    loesung = 5;
    punktzahl = vergleichen(eingabe, loesung, punktzahl); 
    
    //Aufgabe 7 (arcsin):
    printf("Was ergibt: arcsin(sqrt(2)/2)\n");
    printf("1: = -pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = -pi/4\n");
    
    scanf("%d",&eingabe);
    loesung = 3;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 8 (arcsin):
    printf("Was ergibt: arcsin(sqrt(3)/2)\n");
    printf("1: = -pi/2\n");
    printf("2: = pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = -pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 9 (arcsin):
    printf("Was ergibt: arcsin(-sqrt(3)/2)\n");
    printf("1: = -pi/2\n");
    printf("2: = -pi/3\n");
    printf("3: = -pi/4\n");
    printf("4: = -pi/6\n");
    printf("5: = 0\n");
    printf("6: = pi/6\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
	
   
   //Aufgabe 1 (arccos):
    printf("\nWas ergibt: arccos(-1)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 1;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 2 (arccos):
    printf("Was ergibt: arccos(0)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 5;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 3 (arccos):
	printf("Was ergibt: arccos(1)\n");
    printf("1: = pi\n");
    printf("2: = 0\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 4 (arccos):
    printf("Was ergibt: arccos(-1/2)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");

    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 5 (arccos):
    printf("Was ergibt: arccos(-sqrt(3)/2)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 2;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 6 (arccos):
    printf("Was ergibt: arccos(1/2)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 6;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 7 (arccos):
    printf("Was ergibt: arccos(sqrt(2)/2)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = pi/4\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 4;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 8 (arccos):
    printf("Was ergibt: arccos(sqrt(3)/2)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/6\n");
    
    scanf("%d",&eingabe);
    loesung = 6;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Aufgabe 9 (arccos):
    printf("Was ergibt: arccos(-sqrt(2)/2)\n");
    printf("1: = pi\n");
    printf("2: = 5*pi/6\n");
    printf("3: = 3*pi/4\n");
    printf("4: = 2*pi/3\n");
    printf("5: = pi/2\n");
    printf("6: = pi/3\n");
    
    scanf("%d",&eingabe);
    loesung = 3;
    punktzahl = vergleichen(eingabe, loesung, punktzahl);
    
    //Auswertung:
    printf("-------------------------------------\n");
    printf("Max Punktzahl: 18\n");
    printf("-------------------------------------\n");
	
	return;
}