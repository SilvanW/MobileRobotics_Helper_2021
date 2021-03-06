// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Include custom header files
#include "Functions/importFromCSV/importFromCSV.h"
#include "Mathematik/Mathematik_1/Hangman/piehangman.h"
#include "Informatik/Informatik_1/Quiz/INF1_quiz.h"
#include "Functions/MultipleChoice/Multiple_Choice.h"
#include "Optik/Optik_1/Optikformeln/Main_Optikformeln.h"
#include "Spiele/TicTacToe/TicTacToe.h"
#include "Optik/Optik_1/Quiz/Optik1.h"
#include "Konverter/Einheiten/Einheiten_Konverter_main.h"
#include "Optik/Optik_1/Spiegeldarstellung/optik.h"
#include "Mathematik/Mathematik_1/Trigonometrie/Trigonometrische_Funktionen_Main.h"
#include "Elektronik/Elektronik_1/elektronikQuiz.h"
#include "Konverter/Zahlenkonverter/zahlenkonverter.h"
#include "Mathematik/Mathematik_1/Linalg/lin_alg.h"
#include "Spiele/Lost_Found/lostfound.h"

// Enumeration Hauptmenu
typedef enum {
    MATHEMATIK = 1,
    PHYSIK,
    OPTIK,
    ELEKTRONIK,
    INFORMATIK,
    CONVERTER,
    SPIELE,
    AUSWERTUNG,
    EXIT      
} Hauptmenu;

// Enumeration Mathematik
typedef enum {
          MATHEMATIK_1 = 1,
          MATHEMATIK_2
} Mathematik;

// Enumeration Mathematik_1
typedef enum {
          LINALG = 1,
          TRIGONOMETRISCHE_FUNKTIONEN,
          MATHEMATIK_1_MULTIPLE_CHOICE,
          HANGMAN
} Mathematik_1;

// Enumeration Mathematik_2
typedef enum {
    MATHEMATIK_2_EMPTY = 1
} Mathematik_2;

// Enumeration Physik
typedef enum {
    PHYSIK_1 = 1,
    PHYSIK_2
} Physik;

// Enumeration Physik_1
typedef enum {
    PHYSIK_1_MULTIPLE_CHOICE = 1
} Physik_1;

// Enumeration Physik_2
typedef enum {
    PHYSIK_2_EMPTY = 1
} Physik_2;

// Enumeration Optik
typedef enum {
    OPTIK_1 = 1,
    OPTIK_2
} Optik;

// Enumeration Optik_1
typedef enum {
    FORMELN = 1,
    OPTIK_1_QUIZ,
    SPIEGELSIMULATION
} Optik_1;

// Enumeration Optik_2
typedef enum {
    OPTIK_2_EMPTY = 1
} Optik_2;

// Enumeration Elektronik
typedef enum {
    ELEKTRONIK_1 = 1,
    ELEKTRONIK_2
} Elektronik;

// Enumeration Elektronik_1
typedef enum {
    ELEKTRONIK_1_QUIZ = 1
} Elektronik_1;

// Enumeration Elektronik_2
typedef enum {
    ELEKTRONIK_2_EMPTY = 1
} Elektronik_2;

// Enumeration Informatik
typedef enum {
    INFORMATIK_1 = 1,
    INFORMATIK_2
} Informatik;

// Enumeration Informatik_1
typedef enum {
    INFORMATIK_1_QUIZ = 1
} Informatik_1;

// Enumeration Informatik_2
typedef enum {
    INFORMATIK_2_EMPTY = 1
} Informatik_2;

// Enumeration Converter
typedef enum {
    ZAHLENSYSTEM = 1,
    EINHEITEN,
} Converter;

// Enumeration Spiele
typedef enum {
    TICTACTOE = 1,
    LOST_FOUND
} Spiele;