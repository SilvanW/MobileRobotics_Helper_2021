#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Multiple_Choice.h"

#define MAXCHAR 200 // Maximale Zeichen pro Frage oder Antwort
#define MAXROW 500  // Maximale Zeichen die pro Zeile eingelesen werden


int main (void) {
  multiple_choice("test.csv", "Auswertung.csv");
}
