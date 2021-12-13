/* 
* Helper.c
* Main Programm für Gruppenarbeit des Semesterende
* Autor: Silvan Wiedmer (Projektleiter), Ramona Ferri, Tim Barmettler (Praktikant)
* Erstellungsdatum: 13.12.21
* Version: 1.0 - Aufruf Export und CSV
*/


#include <stdio.h>
#include "Functions/exportToCSV.h"

int main() {
          exportToCSV("test.csv","08.12.21","22:13","Mathematik_1",50);
          return 0;
}