#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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



//--- Globale Variablen (Böse) -------------------------------------------------
static List list;
//--- Globale Variablen (Böse) Ende --------------------------------------------

//--- Frage einfügen -----------------------------------------------------------
void insert_Element (Frage *newElement, List *list) {
  Frage *temp;
  temp = list->first;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newElement;
}
//--- Frage einfügen Ende ------------------------------------------------------


//--- Frage löschen ------------------------------------------------------------
void delete_Element (Frage *delElement, List *list) {
  Frage *temp;
  Frage *del;

  temp = list->first;

  // Wenn das zu löschende Element das erste ist.
  if(temp == delElement) {
    list->first = temp->next;
    free(temp);
    return;
  }

  // Falls nicht, Liste durchgehen.
  while (temp != NULL) {
    if(temp->next == delElement) {
      del = temp->next;
      temp->next = del->next;
      free(del);
    }
    temp = temp->next;
  }
}
//--- Frage löschen Ende -------------------------------------------------------

//--- Fragen ausgeben (Test) ---------------------------------------------------
void print_list(List *list) {
  Frage *temp;
  printf("---------------------------------------------------\n");
  temp = list->first;
  while(temp != NULL) {
    printf("%d\t",temp->nummer);
    printf("%s",temp->frage);
    temp = temp->next;
  }
  printf("---------------------------------------------------\n");
}
//--- Fragen ausgeben (Test) Ende ----------------------------------------------

//--- Fragen Laden -------------------------------------------------------------
int fragen_laden2(char dateiname[]){
  FILE *fp;
  char row[MAXROW];


  char *buffer;
  char *frage_buffer, *erklaerung_buffer;
  bool loesung_buffer;
  int i=0;

  // File öffnen
  fp = fopen(dateiname,"r");


    while (feof(fp) != true) //feof end of file
    {
        fgets(row, MAXROW, fp);
        //printf("Row: %s", row);

        // Frage auslesen
        frage_buffer = strtok(row, ";");

        // Lösung auslesen
        buffer = strtok(NULL, ";");

        // Erklärung auslesen
        erklaerung_buffer = strtok(NULL, "");

        if(erklaerung_buffer == NULL) {
          break;
        }

        i++;
        // String vergleichen und Bool ausgeben
        if (strcmp(buffer, "Richtig") == 0) {
          loesung_buffer = 1;
        } else if (strcmp(buffer, "Falsch") == 0) {
          loesung_buffer = 0;
        }

        /*
        printf("%s
", frage_buffer);
        printf("%d
", loesung_buffer);
        printf("%s
", erklaerung_buffer);
        */

        //Frage in Liste laden
        Frage *b;
        b  = malloc(sizeof(Frage));
        b->nummer = i;
        b->loesung = loesung_buffer;
        strcpy(b->frage, frage_buffer);
        strcpy(b->erklaerung, erklaerung_buffer);

        insert_Element(b, &list);
    }

    printf("Es wurden %d Fragen geladen\n",i);

fclose(fp);
return 0;
}
//--- Fragen Laden Ende --------------------------------------------------------

void init_list(void) {
  Frage *a;
  a = malloc(sizeof(Frage));
  a->nummer = 0;
  a->loesung = 0;
  strcpy(a->frage,"Testfrage: Delfine haben Beine.\n");
  strcpy(a->erklaerung,"Testerklärung: Nein sie haben Flossen\n");
  a->next = NULL;

  list.first = a;
}

// Frage stellen
void frage_stellen(List *list) {
  Frage *temp;
  char *antwort_temp;
  int punkte = 0;

  // Struct in temp laden
  temp = list->first;

  // Es werden alle Fragen gestellt bis die Liste am Ende ist.
  while(temp != NULL) {
    printf("%s",temp->frage);

    scanf("%s",&antwort_temp);

    if(strcmp(&antwort_temp, "Richtig") == 0) {
      temp->antwort = 1;
    } else if (strcmp(&antwort_temp, "Falsch") == 0) {
      temp->antwort = 0;
    } else {
      printf("Bitte gebe Richtig oder Falsch ein!Viel Erfolg bei der nächsten Frage, diese hast du verkackt!");
    }

    if(temp->antwort == temp->loesung) {
      printf("Das ist richtig!");
      punkte++;
    } else {
      printf("Das ist leider Falsch!\t");
      printf("%s",temp->erklaerung);
      printf("");
      punkte--;
    }
    temp = temp->next;
  }
  if(punkte < 0) {
    punkte = 0;
  }
  printf("Du hast %d Punkte erzielt", punkte);
}

//--- MAIN ---------------------------------------------------------------------
int multiple_choice(char dateiname []) {
  init_list();

  fragen_laden2(dateiname);

  print_list(&list);

  frage_stellen(&list);
}
//--- MAIN Ende ----------------------------------------------------------------
