#ifndef _FILE_NAME_H_
#define _FILE_NAME_H_

#define MAXCHAR 200 // Maximale Zeichen pro Frage oder Antwort
#define MAXROW 500  // Maximale Zeichen die pro Zeile eingelesen werden

//--- Struct -------------------------------------------------------------------
typedef struct {
  int nummer;// Nummer der Frage, dient zum identifiezeirung
  char frage[MAXCHAR]; // die Frage
  bool loesung; // Losung der Frage, 0 = Falsch, 1 = Richtig
  int antwort; // Antwort die vom Benutzer gegeben wird, 0 = Keine Antwort, 1 = Falsch, 2 = Richtig
  char erklaerung[MAXCHAR]; // Erklärung der Frage
  struct Frage *next;

}Frage;

typedef struct {
  Frage *first;
}List;
//--- Struct Ende --------------------------------------------------------------

//--- Funktionsprototypen ------------------------------------------------------
void insert_Element (Frage *newElement, List *list);
void delete_Element (Frage *delElement, List *list);
void print_list(List *list);
int fragen_laden2(char dateiname[]);
void init_list(void);
void frage_stellen(List *list);
int multiple_choice(char dateiname [], char exportName [], char Theme []);
//--- Funktionsprototypen Ende -------------------------------------------------


#endif
