/* Optik.c
Hauptprogramm Optik. Hier wird die Auswahl zwischen den Unterprogrammen
und zusätzlichen Informationen ermöglicht
Autor: Joshua Stutz
Firma: FHGR / Photonics
Version: 2.1
Datum: 06.12.2021

Änderungen:
1.0 	Erstellung des Programms
1.1 	Grundgerüst Menü
1.2 	Eastereggs
2.0 	Zeit Komponente hinzugefügt
2.1 	Einbinden der Headerdateien
*/

//Bibliotheken und Headerdateien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "optikSpiegel.h"
#include "optikQuiz.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


//Funktionen
void Spiegelsimulation()
{
	//Variablen Menueauswahl
	char auswahlStr[20] = {};
	int auswahlInt = 0;
	char *pEnd = 0;
	int exit = 0;
	int anzPw = 3;
	
	//Zeit Variablen by Joel Flepp
	char AktZeit[6] ={};	
	char Lauf1=0;
	char Zeit[60]={};
	int FreiSch=0;
	char Passwort[50]={};
	
	
	//Begrüssung
	printf("\nSchoen, dass Sie sich fuer das schoenste Optik-Programm entschieden haben!\n");
	
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
		printf("Morgenstund hat Gold im Mund, es ist %s, Zeit fuer Optik JUHU\n\n",AktZeit);
		FreiSch=1;
	}
	else if (AktZeit[0]==49 && AktZeit[1]<51)
	{
		printf("Um die Mittagszeit am %s, ist die Perfekte Zeit fuer Optik:)\n\n",AktZeit);
		FreiSch=1;
	}
	else if (AktZeit[0]==49 && AktZeit[1]>=51)
	{
		printf("Es ist %s, jetz aber schnell Optik lernen!!\n\n",AktZeit);
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
		while(anzPw > 0) {
			printf("Wenn du den Optik rechner trotzdem benutzen moechtest, bitte das Streberpasswort eingeben:\n");
			printf("(Euch sei gewahr: Nach 3 fehlgeschlagenen Versuchen wird Ihr PC aus Sicherheitsgruenden heruntergefahren!)\n");
			fflush(stdin);
			scanf("%50[^\n]s", Passwort);
			
			if(anzPw == 0) {
				
				printf("PC sagt Schuess!!");
				#ifdef _WIN32
				system("C:\\WINDOWS\\System32\\shutdown /s");
				#else
				printf("Diese Funktion wird nur unter Windows unterstützt.\n");
				printf("Für das gleiche erlebnis schalten sie nun ihren PC aus.");
				#endif

				
			}
			
			else if(strcmp(Passwort, "Ich liebe Optik")==0) {
			
				printf("Nagut du Optikstreber, du darfst den Optikrechner nutzen\n");
				FreiSch = 1;
				anzPw = 0;
			}
			
			else { 
				
				anzPw--;
				printf("Falsches Passwort, Sie haben noch %i Versuche uebrig.\n", anzPw);
			}
			
		}
	}
	
	//Dem Benutzer wird Zugriff gestattet, wenn die Uhrezeit es gestattet oder das Streberpasswort eingegeben wurde.
	if(FreiSch == 1) {
		
		//Ausgeführt bis inputok != 0
		while(exit == 0) {
			
			//Hauptmenue
			printf("\n-------------------------------------------------------------------------------------------------------\n");
			printf("Hauptmenue.\nBitte waehlen sie:\n");
			printf("<1>\tSpiegeloptik\n");
			printf("<2>\tOptik-Quiz\n");
			printf("<3>\tStrahlenoptik Simolator (Browser)\n");
			printf("<4>\tAbout\n");
			printf("<5>\tHelp (Browser)\n");
			printf("<6>\tExit\n");
			printf("-------------------------------------------------------------------------------------------------------\n");
			fflush(stdin);
			scanf("%s", auswahlStr);
			
			// Sortiert auswahlStr nach integer und String
			auswahlInt = strtol(auswahlStr, &pEnd, 10);
			//printf("pEnd =%s\n", pEnd);
			
			// Konvertierung erfolgreich -> Eingabe einer Integer
			if(*pEnd == '\0') {
				
				//Je nach eingabe wird die Entsprechende Funktion/ Zeilen ausgeführt
				switch(auswahlInt) {
				
					case 1:
						optikSpiegel();
					break;
						
					case 2:
						optikQuiz();
					break;
					
					case 3:
						#ifdef _WIN32
						system("explorer https://ricktu288.github.io/ray-optics/simulator/");
						#else
						printf("Diese Funktion wird nur unter Windows unterstützt. \n");
						printf("Für das gleiche erlebnis folgen sie der url: \n");
						printf("https://ricktu288.github.io/ray-optics/simulator/");
						#endif
					break;
					
					case 4:
						//About
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n-------------------------------------------------------------------------------------------------------\n");
						printf("About:\n");
						printf("Das schoenste Optik-Programm ist im Zusammanehang mit einem Schulprojekt entstanden.\n");
						printf("Hier kann sich der Optik-versessene Student in Sachen Wissensvertierfung\n");
						printf("und Begeisterungsentfaltung geanzlich austoben.\n\n");
						printf("Hingweise zum Optik-Programm:\n");
						printf("Begriffe wie \"nice\", \"fun\" und \"hack\" sollten auf keinen Fall im Hauptmenue eingegeben werden ;)\n");
						printf("Des weiteren soll bekannt sein, dass das Streberpasswort auf keinen Fall \"Ich liebe Optik\" lautet ;)\n");
						printf("-------------------------------------------------------------------------------------------------------\n");
					break;
					
					case 5:	
						#ifdef _WIN32
						system("explorer http://www.ismycomputeron.com/");
						#else
						printf("Diese Funktion wird nur unter Windows unterstützt.\n");
						printf("Für das gleiche erlebnis folgen sie der url:\n");
						printf("http://www.ismycomputeron.com/");
						#endif
					break;
					
					case 6:
						//Exit
						printf("Habt Dank fuer euer Interesse! Wir wuenschen einen angenehmen Tag.\n");
						exit = 1;
					break;
					
					default:
						//Benutzer hat müll eingegeben
						printf("Ungueltige Eingabe!\n");
					break;
				}
			}
			
			//Easteregg 1
			else if(strcmp(auswahlStr, "fun") == 0) {
				
				printf("\n\n");
				printf("                                                       ,,,,ggggg,\n");                                                                                       
				printf("                                          ,,ggg@@@@@@@@@@@@@@@@@@@@@@@N\n");                                                                                  
				printf("                                     ,g@@@@@@@@@@@@@@@@@@@@@@@@@@@@R@@@g\n");                                                                                 
				printf("                               g@@@@@NMMP*****MMNNB@@@@@@@@@@@@@@$   \"RB@@g\n");                                                                            
				printf("                             g@@P\"                   '\"$@@@@@P**MM\"      \"B@\n");                                                                             
				printf("                           g@K                     $@@@@@@@M               $@g\n");                                                                           
				printf("                         g@@P                      @@@@@@@@P                ]@@g\n");                                                                         
				printf("                       g@@P-                      $@@@@@@@@P        ,,       '$@@g\n");                                                                       
				printf("                  ,,g@@@\"                         @@@@@@@@@P   ,g@@@@'\"$@g,   ]@@@@@\n");                                                                     
				printf("           J@@@@@@@@@@@@@@g,,,,                  $@@@@@@@P   g@@@M*\"    ]@@@@, $@@@@@,\n");                                                                   
				printf("                ,g@@@NMPPMN@@@@@@@@g            ]@@@@@@@   g@@P`      ,  '\"B@@@g$@@@@@\n");                                                                   
				printf("             ,g@@P^          *&@@@@@@           ]@@@@@@  ,@@P        $@P     $@@@@@@@@P\n");                                                                  
				printf("           ]@@@@-               $@@\"            ]@@@@@  y@@P         '$@,    gP&@@@@@@@\n");                                                                  
				printf("           @@@P            ,gggg,]@@,            $@@@@ j@@             %B@@@@@` \"@@%@@@g\n");                                                                 
				printf("          $@@@        ,g@@N\"-   '\"RB@@g          $@@@P $@                        '@@\"@@@g\n");                                                                
				printf("         ]@@@       ,@@R\"            $@@@g             ]@p                        ]@P \"@@@,\n");                                                              
				printf("         @@@P      J@P                ]@@@@,            $@g                       '@@  ]@@@@\n");                                                             
				printf("        ]@@@       @NR@@@@             \"MN@@p            ]@@                       @@   \"@@@@\n");                                                            
				printf("        $@@       j@    ]@@               $@P              *@g,                    \"`    ]@@@@\n");                                                           
				printf("        @@@        ,gg@@@@\"              g@B     ,,,ggggg,,  \"B@@g,             ,@@`      @@@@@\n");                                                          
				printf("        @@        ]@@P\"\"               ,@@P  g@@@P\"\"'\"*RPPPMNB@@@@@B@ggggggggg@NP^        ]@@@@W\n");                                                         
				printf("       ]@@        ]@@                 g@@  ,@@N\"g@,    -@,    g'%%B@g,-`\"**\"\"`              ]@@@@\n");                                                         
				printf("       $@P         $@               y@@\"  ,@@    $@p   ]@NBB@@N    \"*B@@gggg@gg,            ]@@@\n");                                                         
				printf("       $@          \"B@g           g@@`  ,@@P     ]@@@gg@@               \"N@@@@P*B@           $@@F \n");                                                       
				printf("       @@            \"R@g,      g@@\"   @@@`$@,    ]@  \"**                        ]@          ]@@P\n");                                                        
				printf("      ]@@               -\"**  &NM\"     @@  ]@@g,,,$@                              ]@,         @@P\n");                                                        
				printf("      $@@                             ]@@  ]@@P\"*PM\"                               ]@@        $@P\n");                                                        
				printf("      $@@                             ]@@@@@P                     ,,,               ]@@       $@P\n");                                                        
				printf("      @@@P                            @@@                       g@@RMB@g              $b      $@P\n");                                                        
				printf("      @@@@                           ]@@                     ,g@P     '%@g     ,,      @      $@P\n");                                                        
				printf("      $@@@P                          ]@@              g@\"\"%@@@@C        $@@, g@\"\"%@@g  $F     $@P\n");                                                        
				printf("      $@@@@                          $@F            g@@               ,@R\"\"$@@     '*B @P     $@-\n");                                                        
				printf("      ]@@@@W                         @@            $@@         ,,,,  ,@@    $@        @@      ]@@ \n");                                                       
				printf("       $@@@@                        ]@P           ]@@       g@@R\"\"$@@@@P   ,,,,,,,,gg@@C       @@@\n");                                                      
				printf("       '@@@@@                       @@                     j@@P    \"*\" ,g@RP*P**PPP**\"         $@@\n");                                                       
				printf("        \"@@@@                      $@              ,ggg@@  $@@      g@@P                       $@@\n");                                                       
				printf("         '$@@@                    g@P            ,@@\"  \"@@g@@P   ,g@P\"                        g@@P\n");                                                       
				printf("           $@@W                  @@\"            @@P     '\"M*` ,@@P`                          @@@@\n");                                                        
				printf("            ]@@g                @@   ,g@@@@@g  $@P        ,@@ \"                             @@@P\n");                                                         
				printf("             $@B@,             $@@  ,@P   -\"B@@@P    ,ggNP`                                @@@`\n");                                                          
				printf("             ]@ ]@@g           \"RB@@@@@g,,   -`  g@@@NP                                   $@@P\n");                                                           
				printf("              @p  %@@@g            `\"**MMNNBB@@@@R\"                                      ]@@@\n");                                                            
				printf("              $@    \"B@@@g                                                              ,@@@\n");                                                             
				printf("               $@      \"%N@@                                                            $@@\n");                                                              
				printf("                `*                                                                      B\"\n");
				printf("\n\t\t-->WENN HERR BORER SAGT ES SEI NUR EINE ANNAEHERUNG ;))\n\n\n");
			}
			
			//Easteregg 2
			else if(strcmp(auswahlStr, "nice") == 0) {	
				
				printf("                                                                      ,          g@@@g\n");
				printf("                                                                g@@@@N*   gg@g   $@,@@\n");
				printf("                               ,,gp@@@@@@@@@@@@gg,            ]@@@ ,gg  $@,g@@  $@P\"\n");
				printf("                          g@@@@N*\"\"             `\"M@@g,         ]@@@P'   $@P\"$@  %%@\n");
				printf("                       ,g@P'   ,gmNN  ]NgmP\"''`'    'TMN@g       \"%%@      `   \"\n");
				printf("                     ,@@^    gP            $ w*\"\"\"\"*@*,| \"%%@g\n");
				printf("                   g@M\"     @\"   g@.=,,     j   ;@  $    | `j@,\n");
				printf("                 ,@P       '    C      jj@   '*w,gg\"       | '%%g\n");
				printf("                ,@P          ]  %%, '$@,@        ``\"v        '  j@,\n");
				printf("                @P           ``'* ''``  ]M             `*w      \"%%g\n");
				printf("              @@                       \"     ,g@M\"\"'\"]$       |  %%@,        g@@@@g\n");
				printf("             ]@L                           ,@ggg,g@ML-]F          \"@g      ]@@   `,,\n");
				printf("              $@                           @\"    \"`  '              ]@      @@*MM ]@@ ]@P$@\n");
				printf("              @K                          F                      |  ]@      \"     %%@@F$@@M`\n");
				printf("             ]@L                         g                 ,        ]@              \" $P\n");
				printf("             ]@`                          \"\"\"             >M      | ]@\n");
				printf("             ]@                                             ~,      ]@\n");
				printf("             ]@                                            k  \"V    ]@\n");
				printf("            ]@                                            $   F    ]@\n");
				printf("             ]@                                           )  g\"     $@\n");
				printf("             ]@                                          /'       | @P\n");
				printf("              $@                                    www*`          j@       ,gggg      @@@g\n");
				printf("               %%@,                                                ,@@       ]@g  g@@@ ]@@@@\n");
				printf("                \"@g                                             ,g@P         @@MR@@@@r]@P\n");
				printf("                  %@                                          ,@@\"           ]@  $@\"%% ]@F\n");
				printf("                  ]@g                                     ,g@N\"              '` \"F    `\n");
				printf("         ,      ggg,*B@g                               ,g@@\"\n");
				printf("    g@@@@M^;@@@,$[]@  `*B@gg,,,,,  ,,,,        ,,,,,g@@M\"\n");
				printf("      $@@ggg4@@@@@@@\"      '\"\"**P**P*M@@M*******P*\"\"*'\n");
				printf("      %%@@\" J@P'\"]@C                  ]@@@g              ,,,\n");
				printf("        ]@                g            $@@M@g             *PN@w\n");
				printf("         '               @@            $@\%@ \"\%@,              %%P\n");
				printf("                         @  $@  ,      $@ $g  '%%@g          \"N,\n");
				printf("                            $`g@'      $@  @F    *N@      '@g %%g\n");
				printf("                              @L      ]@`  $F      @        $g %%W     g\n");
				printf("                              `*     g@`   ]K     ]@        'BF       @K\n");
				printf("                                    j@'    ]@     @P\n");
				printf("                                     %%@g,  ]@    jP\n");
				printf("                                       '""` \"\n");
				printf("\n\n\t\t-->WENN MAN HERREN BORERS ERKLAERUNG FOLGEN KANN ;))\n\n\n");
			}
			
			else if(strcmp(auswahlStr, "hack") == 0) {
				#ifdef _WIN32
				system("explorer https://hackertyper.com/");
				#else
				printf("Dies funktion wird nur unter Windows unterstützt");
				#endif
				
			}
			
			else {
				printf("\nEingabe ungueltig!!!!!!!!!! Versuchen sie es noch einmal:\n");
			}
			//https://asciiart.club/
			
		}
	}

	// Return after successfully execution, and returning of a vallue
	return;
}