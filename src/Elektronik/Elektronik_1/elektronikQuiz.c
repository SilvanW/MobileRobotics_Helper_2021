/******************************************
*project name:	Softwareprojekt
*filename:		ElektronikQuiz.c
*version:		1.0
*Authors:		Ahmed Kilic
*               Deborah Schrag
*               Lukas Marti          
*Firma:			FHGR
*Date:			17.12.2021
*Brief:			Programm zum Stellen und Überprüfen von Elektronikfragen
*
*Changelog:		17.12.2021	Creation and first version
******************************************/


//-----------------------------------------------
//Einbinden von bestehenden Modulen
//-----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elektronikQuiz.h"
#include "../../Functions/getTime/getTime.h"
#include "../../Functions/exportToCSV/exportToCSV.h"

//-----------------------------------------------
//Definition Fragen 
//-----------------------------------------------
const t_multipleChoice widerstand = 
{
    "Was ist der elektrische Widerstand?",
    "Der Zusammenstoss von Ladungstraegern mit Atomen",
    "Ein Bauteil",
    "Eine Ansammlung von Ladungstraegern",
    "Zwei Bauteile",
    0
};

const t_multipleChoice pol =
{
	"Von welchem Pol zu welchem Pol fliesst der Strom innerhalb der Batterie?",
	"Plus zu Minus",
	"Minus zu Plus",
	"Plus zu Plus",
	"Minus zu Minus-Plus",
	1
};

const t_multipleChoice stromrichtung =
{	
	"Wie verlaeuft die technische Stromrichtung?",
	"Minus zu Plus",
	"Plus zu Minus",
	"Die gibt es nicht",
	"Plus zu Plus-Minus",
	1
};

const t_multipleChoice halbleiter =
{
	"Durch was zeichnet sich ein Halbleiter aus?",
	"Er leitet nur 50%",
	"Die Atome gehen nur kovalente Bindungen ein",
	"Die Atome gehen nur Metallbindungen ein",
	"Die Atome gehen nur Unpolare Bindungen ein",
	1
};

const t_multipleChoice leiter =
{
	"Wieso leitet ein Leiter?",
	"Wegen seinem durchmesser",
	"Er hat freie Elektronen",
	"Der Atomkern kann sich bewegen",
	"Die Neutronen sind frei beweglich",
	1
};

const t_multipleChoice kirchhof =
{
	"Welche Saetze machen den Kirchhof aus?",
	"Schleife & Masche",
	"Knoten & Schleife",
	"Schlaufe & Masche",
	"Masche & Knoten",
	3
};

const t_multipleChoice maschenregel =
{
	"Was macht die Maschenregel aus?",
	"Alle Stroeme ergeben Null",
	"Die Widersteande heben sich gegenseitig auf",
	"Die Spannungen in einer Masche ergeben immer Null",
	"Die Spannungen addieren sich positiv im Uhrzeigersinn",
	2
};

const t_multipleChoice knotenregel =
{
	"Was macht die Knotenregel aus?",
	"Die Stroeme in einem Knoten ergeben immer Null",
	"Alle Knoten sind verboten",
	"Alle Widerstaende sind 0",
	"Die Stroeme in einem Knoten ergeben nie Null",
	0
};

const t_multipleChoice reihenschaltung =
{
	"Wie addiert sich Spannung in einer Reihenschaltung?",
	"Ug = U1 - U2..",
	"Ug = U1 = U2..",
	"Ug = U1 + U2..",
	"Ug = U1/U2..",
	2
};

const t_multipleChoice parallelschaltung = 
{
	"Wie addiert sich Spannung in einer Parallelschaltung",
	"Ug = U1 - U2..",
	"Ug = U1 = U2..",
	"Ug = U1 + U2..",
	"Ug = U1/U2..",
	1
};

const t_multipleChoice reihenschaltungW =
{
	"Wie addieren sich Widerstaende in einer Reihenschaltung?",
	"Rg = (1/R1 + 1/R2)^-1",
	"Rg = R1 = R2..",
	"Rg = R1/R2",
	"Rg = R1 + R2",
	3
};

const t_multipleChoice parallelschaltungW =
{
	"Wie addieren sich Widerstaende in einer Parallelschaltung?",
	"Rg = (1/R1 + 1/R2)^-1",
	"Rg = R1 = R2..",
	"Rg = R1/R2",
	"Rg = R1 + R2",
	0
};

const t_multipleChoice reihenschaltungI = 
{
	"Wie addieren sich Stroeme in einer Reihenschaltung?",
	"Ig = I1 = I2..",
	"Ig = 1/I1 + 1/I2",
	"Ig = I1 + I2..",
	"Rueckwaerts",
	0
};

const t_multipleChoice parallelschaltungI = 
{
	"Wie addieren sich Stroeme in einer Parallelschaltung?",
	"Ig = I1 = I2..",
	"Ig = 1/I1 + 1/I2",
	"Ig = I1 + I2..",
	"Links",
	2
};

const t_multipleChoice elektrischeladung =
{
	"Formelzeichen der Elektrischen Ladung?",
	"L",
	"U",
	"K",
	"Q",
	3
};

const t_multipleChoice elektrischeladungE = 
{
	"Einheit der Elektrischen Ladung",
	"Hyugens",
	"Ampere",
	"Coulumb",
	"Farrad",
	2
};


const t_multipleChoice elektrischeladungF =
{
	"Formel fuer die Elektrische Ladung?",
	"Q = I*t",
	"Q = F*K",
	"Q = W/I",
	"Q = U/W",
	0
};

const t_multipleChoice difwiderstand =
{
	"Was ist ein differentieller Widerstand?",	
	"Ein Widerstand aber mit konstant steigender Kennlinie",
	"Der Widerstand an einem bestimmten Punkt einer U/I Kennlinie",
	"Den gibt es gar nicht",
	"Der Widerstand an einem bestimmten Punkt einer A/I Kennlinie",
	1
};

	
const t_multipleChoice kondensatork = 
{
	"Formelzeichen der Kapazitaet?",
	"K",
	"C",
	"V",
	"F",
	1
};

const t_multipleChoice kondensatorE =
{
	"Einheit des Kondensators?",
	"Fahrrad",
	"Farad",
	"Velo",
	"Zweirad",
	1
};

const t_multipleChoice kondensatorF =
{
	"Welches ist KEINE Formel fuer  die Kondensator Kapazitaet?",
	"C = Q/U",
	"C = (I*t)/U",
	"C = (my0 * myR * A)/s",
	"C = Q*F/I",
	3
};

const t_multipleChoice kapazitaet = 
{
	"Was ist ein Dielektrikum?",
	"Das Material zwischen Kondensorplatten",
	"Der Zwischenraum in einer Spule",
	"Der Bereich der fehlenden Anionen",
	"Keine Ahnung ist das ueberhaupt relevant?",
	0
};


const t_multipleChoice	durchschlag = 
{
	"Welche Faktoren beeinflussen die Durchschlagsfestigkeit eines Kondensators?",
	"Dielektrikum und Elektronenanzahl",
	"Plattenabstand und Dielektrikum",
	"Rueckhaltekraft und Vorhaltekraft",
	"Die breite des Tuerstehers",
	1
};


const t_multipleChoice spannungsteiler = 
{
	"Wie definiert man die Spannungsteiler Regel?",
	"U1/U2 = R1/R2",
	"(I1/R1)^-1",
	"U1*I1",
	"U1/I1 = R1/R2",
	0
};

const t_multipleChoice spannungsabfall = 
{
	"Was ist ein Spannungsabfall?",
	"Der Quotient zwischen zwei Knoten",
	"Der Kommunismus zwischen Plus und Minus Pol",
	"Die Differenz der Spannung zwischen 2 Punkten",
	"Die Differenz der Spannung zwischen ausschliesslich Plus und Minus Pol",
	2
};	

const t_multipleChoice kondensatorenergie = 
{
	"Wie wird Energie in einem Kondensator gespeichert?",
	"In vielen kleinen Loechern",
	"Durch Aufbau eines elektrischen Feldes",
	"Durch chemische Energie",
	"In einer Batterie",
	1
};


const t_multipleChoice dc = 
{
	"Fuer was steht DC?",
	"Dimensional Current",
	"Diagnol Current",
	"Diet Coke",
	"Direct Current",
	3
};

const t_multipleChoice ac = 
{
	"Fuer was steht AC?",
	"Animal Crossing",
	"Automatic Current",
	"Alternative Current",
	"Alternating Current",
	3
};

	
const t_multipleChoice gleichrichter =
{
	"Wozu dient ein Gleichrichter?",
	"Damit jeder Straefling die gleiche Strafe bekommt",
	"Um DC in AC umzuwandeln",
	"Um AC in DC umzuwandeln",
	"Dieses Bauteil ist rein fiktiv",
	2
};

const t_multipleChoice pmaterial =
{
	"Was zeichnet das P Material aus?",
	"Es hat ueberschuessige Elektronen",
	"Was ist ein P Material?",
	"Es hat ueberschuessige Loecher",
	"Im Ernst was ist das?",
	2
};

const t_multipleChoice nmaterial =
{
	"Was zeichnet das N Material aus?",
	"Es hat ueberschuessige Neutronen",
	"Es hat ueberschuessige Elektronen",
	"Es ist generell ueberfluessig",
	"Ich weiss nicht was das ist?",
	1
};

const t_multipleChoice enten =
{
	"Wie viele Enten gibt es auf der Welt?",
	"2",
	"24",
	"34 Millionen",
	"nicht genug",
	3
};	

const t_multipleChoice kurzschlusse = 
{
    "Was versteht man unter einem Kurzschluss?",
    "Das schnelle Beenden einer Praesentation",
    "Eine ungewollte Verbindung von Plus- und Minuspol",
    "Das Ueberbruecken eines Widerstands",
    "Aus versehen einen Kondensator einbauen",
    1
};

const t_multipleChoice diodeIdeal = 
{
    "Was ist der Unterschied zwischen einer idealen und einer realen Diode?",
    "Eine ideale Diode besitzt meist keine Schwellspannung.",
    "Eine ideale Diode besitzt eine normierte Schwellspannung von 1V",
    "Eine reale Diode laesst keinen Rueckwaertsstrom fliessen",
    "Eine reale Diode vertraegt genau 1A, bevor sie kaputt geht",
    0
};

const t_multipleChoice oszilloskop = 
{
    "Wofuer benoetigt man ein Oszilloskop?",
    "Um den Sauerstoffgehalt in der Raumladungszone zu messen",
    "Um zeitlich veraendernde Signale zu messen",
    "Um Kapazitaeten in Leitern zu messen",
    "Um DC Signale zu betrachten",
    1
};

const t_multipleChoice indFormelzeichen =
{
    "Welches ist das Formelzeichen der Induktivitaet",
    "C",
    "u",
    "L",
    "N",
    2
};

const t_multipleChoice spulenFormel =
{
    "Welche Formel benutzt man um die Induktivitaet zu berechnen?",
    "L = U/Q",
    "L = F/Q",
    "L = N * (u0*ur*A/l)",
    "L = N^2 * (u0*ur*A/l)",
    3
};

const t_multipleChoice spulenEnergie = 
{
    "In welcher Form wird Energie in der Spule gespeichert?",
    "In einem magnetischen Feld",
    "In einem elektrischen Feld",
    "In chemischen Verbindungen",
    "In kinetischer Energie",
    0
};

const t_multipleChoice spulenStrom = 
{
    "Nimmt der Strom in der Spule zu, wird die Spannung...",
    "...geringer",
    "...groesser",
    "...gleichbleiben",
    "...verschwinden",
    0
};

const t_multipleChoice raumladungZone = 
{
    "Was ist die Raumladungszone?",
    "Was macht die Katze auf der Tastadcfjd dsafj",
    "Das Gebiet, in welchem P- und N-Material aufeinander treffen",
    "Der Ort, wo Fracht aus dem Container genommen wird",
    "Das Elektronengas in einem Leiter",
    1
};

const t_multipleChoice uRaumladung = 
{
    "Welche Spannung entsteht ungefaehr in einer Raumladungszone aus Silizium?",
    "0.01V",
    "0.2V",
    "5V",
    "0.7V",
    3
};

const t_multipleChoice spulenSpannung =
{
    "Ist in einer Spule ein magnetisches Feld aufgebaut und wird der Strom unterbrochen, in welche Richtung zeigt nun die Spannung ueber der Spule?",
    "Die Spannung ist gleich Null",
    "In dieselbe Richtung, wie zuvor",
    "Entgegen der urpsruenglichen Spannung",
    "Kommt auf die Wicklungszahl an",
    2
};


/**
 * Ruft die Fragen nacheinander auf und Berechnet den Punktestand
 * 
 * Rückgabe: Punktestand in Prozent
 */
char elQuiz(void)
{
    char punktestand = 0;
    char name[2] ={}; 

    printf("Herzlich Wilkommen zum Elektronikquiz!\n\n");
    printf("Sie koennen den Test nach allen 10 Fragen beenden\n");
    printf("Name Bitte: ");
    scanf("%1[^\n]s", &name[0]);    //Eingabe des Strings
    fflush(stdin);
    printf("Hallo Fridolin\n\n");

    //Fragen
    punktestand += multipleChoice(widerstand);
    punktestand += multipleChoice(pol);
    punktestand += multipleChoice(stromrichtung);
    punktestand += multipleChoice(halbleiter);
    punktestand += multipleChoice(leiter);
    punktestand += multipleChoice(kirchhof);
    punktestand += multipleChoice(maschenregel);
    punktestand += multipleChoice(knotenregel);
    punktestand += multipleChoice(reihenschaltung);
    punktestand += multipleChoice(parallelschaltung);

    if(quitQuiz() == 0)
    {
        return auswertung(10, punktestand);
    }

    punktestand += multipleChoice(reihenschaltungW);
    punktestand += multipleChoice(parallelschaltungW);
    punktestand += multipleChoice(reihenschaltungI);
    punktestand += multipleChoice(parallelschaltungI);
    punktestand += multipleChoice(elektrischeladung);
    punktestand += multipleChoice(elektrischeladungE);
    punktestand += multipleChoice(elektrischeladungF);
    punktestand += multipleChoice(difwiderstand);
    punktestand += multipleChoice(kondensatork);
    punktestand += multipleChoice(kondensatorE);

    if(quitQuiz() == 0)
    {
        return auswertung(20, punktestand);
    }

    punktestand += multipleChoice(kondensatorF);
    punktestand += multipleChoice(kapazitaet);
    punktestand += multipleChoice(durchschlag);
    punktestand += multipleChoice(spannungsteiler);
    punktestand += multipleChoice(spannungsabfall);
    punktestand += multipleChoice(kondensatorenergie);
    punktestand += multipleChoice(dc);
    punktestand += multipleChoice(ac);
    punktestand += multipleChoice(gleichrichter);
    punktestand += multipleChoice(pmaterial);

    if(quitQuiz() == 0)
    {
        return auswertung(30, punktestand);
    }

    punktestand += multipleChoice(nmaterial);
    punktestand += multipleChoice(enten);
    punktestand += multipleChoice(kurzschlusse);
    punktestand += multipleChoice(diodeIdeal);
    punktestand += multipleChoice(oszilloskop);
    punktestand += multipleChoice(indFormelzeichen);
    punktestand += multipleChoice(spulenFormel);
    punktestand += multipleChoice(spulenEnergie);
    punktestand += multipleChoice(spulenStrom);
    punktestand += multipleChoice(raumladungZone);
    punktestand += multipleChoice(uRaumladung);
    punktestand += multipleChoice(spulenSpannung);
    
    return auswertung(NUMBER_OF_QUESTIONS, punktestand);   //Rückgabe von Punktestand in ganzzahligen Prozenten
}

/**
 * Führt Fragen aus
 * 
 * Rückgabe:    1 bei korrekter Antwort
 *              0 bei falscher Antwort
 */
char multipleChoice(t_multipleChoice frage)
{
    char answer = 0;    //Eingabevariable

    printf("%s\n", frage.question);      //Ausgabe von Frage

    printf("1: %s\n", frage.answer0);    //
    printf("2: %s\n", frage.answer1);    //
    printf("3: %s\n", frage.answer2);    //
    printf("4: %s\n\n", frage.answer3);  //Ausgabe von Anwortmöglichkeiten

    do
    {
        printf("Auswahl: ");    //
        scanf("%u", &answer);   //Eingabe von Auswahl
        fflush(stdin);
    }
    while ((answer <= 0) || (answer > 4));  //Abfangen von unzulässigen Antworten

    if(answer == (frage.correctAnswer+1))    //Überprüfung der Antworten
    {
        printf("Korrekt!\n\n");  //richtige Antwort
        return 1;   //Punktestand hochzählen
    }
    else
    {
        printf("Falsch! Korrekte Antwort: %u\n\n", frage.correctAnswer+1);   //falsche Antwort
        return 0;   //Punktestand beibehalten
    }
}

/**
 * Fragt nach Quizbeendung und macht Auswertung
 * 
 * Rückgabe:    1 bei Beenden
 *              0 bei Abbruch
 */
char quitQuiz(void)
{
    char yesNo[2];
    do
    {
        printf("Wollen Sie weiterfahren? (y/n): ");
        scanf("%s", &yesNo);
        fflush(stdin);
    } while ((strcmp(&yesNo, "y") != 0) && ((strcmp(&yesNo, "n") != 0)));

    if(strcmp(&yesNo, "y") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Macht Auswertung
 * 
 * Rückgabe:    Punktestand in Prozent
 */
float auswertung(char punkte, char punktestand)
{
    float percent = 100*((float)punktestand/(float)punkte);    //Berechnung von Resultat in Prozent

    printf("\n\nDein Resultat, Fridolin: %f%%\n\nKommentar zum Resultat:\n", percent);    //Ausgabe des Resultats

    //Ausgabe eines Kommentars, abhängig von Resultat
    if(percent == 100)
    {
        printf("Herzlichen Glueckwunsch!, du erhaelst 1 ECTS Punkt\nAbholbar bei: 0901 373 790 + 129 (1.50CHF/min)");
    }
    else if(percent >= 90)
    {
        printf("Deine Kapazitaet koenntest du schon noch etwas erhoehen...");
    }
    else if(percent >= 60)
    {
        printf("Schau! ein dreikoepfiger Affe!\n -Guybrush Threepwood");
    }
    else
    {
        printf("I don't want you to be hopeful. I want you to panic.\n - Greta Thunberg\n");
    }

    exportToCSV("Auswertung/elektronikQuiz.csv", getDate() , getTime() , "Elektronikquiz", (int)percent);

    return percent;
}