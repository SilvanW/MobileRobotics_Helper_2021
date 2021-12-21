/*lin_alg.c
 * versin 1.0
 * Autorn: Pascal Sigrist/Eduard Sadovnichiy
 * datum: 09.12.20
 * GR_C S.*/

//Headerdatei
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

//funktionen

//Variabeln
	int eingabe1 = 0;
	int eingabe2 = 0;
	int eingabe3 = 0;
	int eingabe4 = 0;
	int eingabe5 = 0;

//pointer

//Programmbeginn
int linAlg(void)
{ 
while(true)//wenn ich das Programm ausführe scheint es, als ob er die While- Schleife verlassen würde. Hat dies mit den Break befehlen zu tun?
{

	printf("-1- Winkelmass\n");// -n- um in switch case auswahl zu definieren
	printf("-2- LGLS\n");
	printf("-3- Trigo-funktionen\n");
	printf("-4- Vektoren\n");
	printf("-0- Programm beenden\n");
	printf("Ihre Auswahl Bitte:\t");//um switch-Case auszuwählen
	
int check = scanf("%d", &eingabe1);//eingabe überprüfen
	if (check !=1)
	{
		printf("Fehler bei der Eingabe...\n");
		return 1;
	}
	
switch (eingabe1)
		{
			case 1  : //Winkelmass
					{	
						printf("\n-1- Grad(α°)\n");// -n- um in switch case auswahl zu definieren
						printf("-2- Bogenmass(α)\n");
						printf("-3- Artillerie-Grad(αA)\n");
						printf("-4- NeugradMass(Gon)(αN)\n");
						printf("-5- wichtigse Winkel\n");//--------gibt es eine möglichkeit in das auswahl menu zurück zu gehen?
						printf("-0- Programm beenden\n");
						printf("Ihre Auswahl Bitte:\t");
	
						int check = scanf("%d", &eingabe2);//eingabe überprüfen
						if (check !=1)
							{
								printf("Fehler bei der Eingabe...\n\n");
								return 1;
							}
							
							switch (eingabe2)
								{
								  case 1  : printf("Du wähltest 'in Grad umwandeln'\n");//in Grad umwandeln
											printf("\n\tBoganmass in Grad:\t\t α*(180°/π)=α° \n");
											printf("\tArtillerie-Grad in Grad\t\t 1A' = 0.55625° \n");
											printf("\tNeugradMass(Gon) in Grad\t 1gon = 0.9°\n\n");
											break;
								  case 2  : printf("Du wähtest 'in Bogenmass umwandeln'\n");//in Bogenmass umwandeln
											printf("\n\tGrad in Bogenmass:\t\t α°*(π/180°)=α\n");
											printf("\tArtillerie- Grad in Bogenmass:\t αA'*(π/3'200A')=α\n");
											printf("\tNeugradMass(Gon) in Bogenmass:\t αgon(π/200gon)=α\n\n");
											break;
								  case 3  :printf("Du wähltest 'in Artillerie Grad umwandeln'\n");//in Artillerie-Grad umwandeln
											printf("\n\tGrad in Artillerie-Grad\t\t\t 1° = 17.777A'\n");
											printf("\tBogenmass in Artillerie-Grad\t\t α*(3'200A'/π)=αA'\n");
											printf("\tNeugradMass(Gon) in Artillerie-Grad\t 1gon = 16A'\n\n");
											break;
								  case 4  : printf("Du wähltest'in NeugradMass umwandeln'\n");// in NeugradMass(Gon) umwandeln
											printf("\n\tGrad in NeugradMass(Gon)\t\t 1° = 1.1gon\n");
											printf("\tBogenmass in NeugradMass(Gon)\t\t α*(200gon/π)=α gon\n");
											printf("\tArtillerie Grad in NeugradMass(Gon)\t 1A' = 0.0625gon\n\n");
											break;
								  case 5  : printf("Du wähltest'wichtigste Winkel'\n");//wichtigste Winkel für Alle vier Winkel-Masse
											printf("\nα° 0\t30°\t 45°\t 60°\t   90°\t    120°     180°\t360°\n");
											printf("α  0\tπ/6\t π/4\t π/3\t   π/2\t    2π/3     π\t\t2π\n");
											printf("αA 0\t533,3A'\t 800A'\t 1066,6A'  1'600A'  3'200A'  2'133,3A'  6'400A'\n");
											printf("αN 0\t33,3gon\t 50gon\t 66.6''\t   100''    133.3''  200''      400''\n\n");

											break;//------------------Gibt es eine möglich keit aus diesem Switch in den vorherigen switch in in Zeile 46 zurück zu gehen?
								  case 0  : return EXIT_SUCCESS;//programm beenden
								  default : printf("%d? Falsche Eingabe...\n\n", eingabe2);
								}
							break;
					}			
						
						
			case 2  : 		//LGLS
					{	
						printf("\n-1- Matrix(Konsolenfenster grösser machen für Gesammt-Ansicht)\n");// -n- um in switch case auswahl zu definieren
						printf("-2- Vorgehen/Regeln beim lösen\n");
						printf("-0- Programm beenden\n");
						printf("Ihre Auswahl Bitte:\t");
	
						int check = scanf("%d", &eingabe3);//eingabe überprüfen
						if (check !=1)
							{
								printf("Fehler bei der Eingabe...\n\n");
								return 1;
							}
							
							switch (eingabe3)
								{
								  case 1  : printf("Du wähltest'Matrix'\n");
											printf("\nGaus-Jordan Stufenform(nur eine 1 pro Zeile)\n");//Matrix mit Bezeichnungen
											printf("\n\tPs'1'\t\tPs'2'\t\tPs'3'\t|\t   -\n");
											printf("\n\t x\t\ty\t\tz\t=\tLoesung\n");
											printf("\nPv(1)->\t|1|\t\t0\t\t0\t|\t   4\t\tPz'1'\n");//ausgabe von Matrix mit definition wie Pivo element-,variabeln etc.
											printf("\n\t 0\tPv(2)->|1|\t\t0\t|\t   2\t\tPz'2'\n");
											printf("\n\t 0\t\t0\tPv(3)->|1|\t|\t   8\t\tPz'3'\n");										
											printf("\nPe=Pivoelement(3)=|n|\nPv= Pivovariable(3)=(n)\nPs= Pivospalten(3)='n'\nPz= Pivozeilen(3)='n'\nFreie Parameter =Fp(keine)\nNg= Anzahl Gleichungen(3)\n");
											printf("Nv= Anzahl Variabeln(3(x,y,z))\n\n");
											break;
								  case 2  : printf("Du wähltest'Vorgehen/Regeln beim lösen'\n");
											printf("\nMerke: 'Die zu verändernde Gleichung -- die die gleichb leiben soll'\n\n");//wie löse ich eine matrix nach Gaus Jordan auf
											printf("multiplikation oder division der Gleichung um Sie von der Anderen zu subtrahieren\n\n");//was darf ich Machen
											printf("Ein LGLS hat nur dann unendlich viele Lösungen wenn  Pe<Nv UND verträglichkeit auf jeder zeile erfüllt ist\n\n");//definition
											printf("Ein LGLS hat nur dann genau eine Lösung wenn Pe=Nv und Verträglichkeit auf jeder Zeile erfüllt ist\n\n");//definition
											printf("Wenn in einer Zeile bei allen Nv nur noch Nullen stehen(ausser Resultat) hat das LGLS keine Lösung und ist nicht Lösbar\n\n");//definition
											break;
								  case 0  : return EXIT_SUCCESS;//programm beenden
								  default : printf("%d? Unbekante Eingabe...\n\n", eingabe3);
								}
							break;
					}
						
			case 3  :  //Trigo- Funktionen
					{
						printf("\n-1- sin cos am Einheitskreis\n");
						printf("-2- spezielle Winkel(Grad- Bogenmass) \n");
						printf("-3- wichtigste Winkel \n");
						printf("-4- GAGAHünerHofAG \n");
						printf("-0- Programm beenden\n");
						printf("Ihre Auswahl Bitte:\t");
						
						int check = scanf("%d", &eingabe4);
						if( check !=1)
						{
							printf("Fehler bei der Eingabe ...\n");
							return 1;
						}
						
							switch(eingabe4)
								{
									case 1 : printf("Du wähltest'sin cos am Einheitskreis'\n");
											 printf("\n\n");//sin cos am Einheitskreis
											 printf("sin(180° - φ) = sin(φ)\n");
											 printf("cos(360° - φ) = cos(φ)\n");
											 printf("tan(180° + φ) = tan(φ)\n\n");
											 break;		
								    case 2 : printf("Du wähltest'spezielle Winkel(Grad- Bogenmass)'\n");
											 printf("\n");//spezielle Winkel(Grad- Bogenmass)
											 printf("π/6     =  30°\n");
											 printf("π/4     =  45°\n");
											 printf("π/3     =  60°\n");
											 printf("π/2     =  90°\n");
											 printf("2*(π)/3 = 120°\n");
											 printf("3*(π)/4 = 135°\n");
											 printf("5*(π)/6 = 150°\n");
											 printf("π       = 180°\n");
											 printf("3*(π)/2 = 270°\n");
											 printf("2*(π)   = 360°\n\n");
											 break;		
									case 3 : printf("Du wähltest'wichtigste Winkel'\n");
											 printf("\n");//wichtigste Winkel
											 printf("	sin		cos			tan\n");
											 printf("\n");
											 printf("30°	1/2		sqrt(3)/2		sqrt(3)/3\n\n");
											 printf("45°	sqrt(2)/2 	sqrt(2)/2 		1\n\n");
											 printf("60°	sqrt(3)/2	1/2			sqrt(3)\n\n");
											 break;				 
								    case 4 : printf("Du wähltest'GAGAHünerHofAG'\n");
											 printf("\n");//GAGA-HühnerhogAG
											 printf("	sin	cos	tan	cot\n\n");
											 printf("	G	A	G	A	\n");	
											 printf("	-	-	-	-	\n");
											 printf("	H	H	A	G	\n\n");
											 printf("G = Gegenkathete\n");
											 printf("A = Ankathete\n");
											 printf("H = Hypothenuse\n\n");			
											 break;
									case 0 : return EXIT_SUCCESS;
								default : printf("%d? Unbekante Eingabe...\n\n", eingabe4);
							}
						break;
					}		
					  
			case 4  :  //Vektoren
					{	
						printf("\n-1- Linearkombination\n");//Formel
						printf("-2- Betragsvektor\n");//Formel
						printf("-3- Richtungsvektor\n");//Formel
						printf("-4- Gramm- Riemann Skalarprodukt\n");//Formel
						printf("-5- Orthogonalprojektion\n");//Formel
						printf("-6- Grassmann- Vektorprodukt\n");//Formel
						printf("-7- Geraden(Ebenen)\n");//Formel
						printf("-8- Legende\n");
						printf("-0- Programm beenden\n");
						printf("Ihre Auswahl Bitte:\t");
	
						int check = scanf("%d", &eingabe5);//eingabe überprüfen
						if (check !=1)
							{
								printf("Fehler bei der Eingabe...\n\n");
								return 1;
							}
							
							switch (eingabe5)
								{
								  case 1  : printf("Du wähltest'Linearkombination'\n");
											printf("\n\t ->  (1)   -> (3)\n");
											printf("\t v = (2)   w =(2)\n\n");
											printf("\t ->  ->  (1)+(3)   (4)\n");
											printf("\t v + w = (2)+(2) = (4)\n\n");
											printf("  in Linearkombination Zerlegen:\n");
											printf("\t ->   (2)    ->  (1)    ->  (4)\n");
											printf("\t r  = (4)    v = (2)    w = (8)\n\n");
											printf("\t   ->      ->   ->\n");
											printf("\t a*v  +  b*w  = r\n");
											printf("\t                            ->      ->   ->\n");
											printf("\tgesucht ist a& b, so dass a*v  +  b*w  = r gilt\n");
											printf("\t   ->        ->    ->\n");
											printf("\t 2*v  +  0.5*w  =  r\n");
											printf("  bei Komplexeren Vektoren kann man es mit Hilfe eines LGLS lösen\n\n");
											break;
								  case 2  : printf("Du wähltest'Betragsvektor'\n");
											printf("\n\t->\t(1)\t ->\n");
											printf("\tb=\t(2)=\t|b|=sqrt(1^2+2^2+3^2)=\tsqrt(1+4+9)=\tsqrt(14)\n");
											printf("\t\t(3)\n");
											break;
								  case 3  : printf("Du wähltest'Richtungsvektor'\n");
											printf("\t^      ->  ->\n");
											printf("\tv =(1/|v|)*v\n\n");
											printf("\t                    ^     ^\n");
											printf("\t^       ->  (2)   (2/2)  (1)\n");											
											printf("\tv = (1/|2|)*(0) = (0/2)= (0)\n\n");
											break;
								  case 4  : printf("Du wähltest'Gramm- Riemann Skalarprodukt'\n");
											printf("\n<[a,b,c],[x,y,z]>\n");
											printf("=a*x+b*y+c*z\n");
											printf("=ax+by+cz\n\n");
											printf("\n<[a,b,c],[x,y,z]>\n");
											printf("=a*x+b*y+c*z\n");
											printf("=ax+by+cz\n\n");
											printf("\t-> (2)   ->(4)   <(2) (4)>\n");
											printf("\tv =(3) , w (5) = <(3),(5)>\n\n");
											printf("\t<(2) (4)> \n ");
											printf("\t<(3),(5)> = 2*4 + 3*5 = 8 + 15 = 23\n\n");
											break;
								  case 5  : printf("Du wähltest'Orthogonalprojektion'\n");
											printf("\t -> (2)     -> (6)\n");
											printf("\t v =(3) auf w =(0)\n\n");
											printf("\t->    ->  ->   -> ->  ->\n");
											printf("\tv‖= (<v , w> /<w, w>) * w \n\n");
											printf("\t2*6  +  3*0    (6)   (2*6)   (6)   (2)\n");
											printf("\t------------ * ( ) = ----- * ( ) = ( ) = v‖\n");
											printf("\t6**2 + 0**2    (0)   (6*6)   (0)   (0)\n\n");
											printf("\t->   ->  ->   (2) (2)   (0)\n");
											printf("\tvͰ = v - v‖ = (3)-(0) = (3)\n\n");
											printf("                  ->    ^                         \t->    ->  ^    ^\n");
											printf("  gilt nicht wenn v auf w. Hier Lautet die Formel:\tv‖ = <v , w> * w \n\n");
											printf("                                                  \t->   ->  ->\n");
											printf("                                                  \tvͰ = v - v‖\n");											
											break;
				              	  case 6  : printf("Du wähltest'Grassmann- Vektorprodukt'\n");
											printf("\nAllgemine Formel:\n");
											printf("\n[a, b, c]*[x, y, z]\n\n");
											printf("[b*z-c*y]  [bz-cy]\n");
											printf("[c*x-a*z]= [cx-az]=\n");
											printf("[a*y-b*x]  [ay-bx]\n\n");
											printf("Beispiel:\n");
											printf("\n[1, 2, 3]*[4, 5, 6]\n\n");
											printf("[2*6-3*5]  [12-15]  [-3]\n");
											printf("[3*4-1*6]= [12- 6]= [ 6]\n");
											printf("[1*5-2*4]  [ 5- 8]  [-3]\n\n");
											break;
								  case 7  : printf("Du wähltest'Geraden(Ebenen)'\n");
											printf("\n2D:\n");
											printf("Die Gerade, welche parallel zur x-Achse durch den Punkt (3;2)verläuft\n\n");
											printf("s0 := P= [3, 2]\n");
											printf(" v := e(x)= [1, 0]\n");
											printf("\nParametrisierung\n");
											printf("s(tau)= s0+ tau* v= [3, 2]+ tau* [1, 0]\n");
											printf("\nEinheitsnormaler Vektor\n");
											printf("n(hut)= n= e(y)=[0, 1]\n");
											printf("\nEntlang der Geraden gilt\n");
											printf("y= 2\n");
											printf("y-2= 0\n\n");
											break;
								  case 8  : printf("Du wähltest'Legende'\n");
											printf("\t f \n");
								  case 0  : return EXIT_SUCCESS;//programm beenden
								default : printf("%d? Falsche Eingabe...\n\n", eingabe5);
								}
							break;
					}
			case 0  : return EXIT_SUCCESS;			
					  
			default : printf("%d? Fehler bei der Eingabe...\n\n", eingabe1);
		}
	}
/*if(eingabe1==0)  //Zeile196-215 um Abbruchbedingung zu definieren
	{
	return EXIT_SUCCESS;
	}
if(eingabe2==0)
	{
	return EXIT_SUCCESS;	
	}
if(eingabe3==0)
	{
	return EXIT_SUCCESS;	
	}
if(eingabe4==0)
	{
	return EXIT_SUCCESS;	
	}
if(eingabe5==0)
	{
	return EXIT_SUCCESS;	
	}*/
	
return EXIT_SUCCESS;
}

