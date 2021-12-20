/******************************************
*project name:	Softwareprojekt
*filename:		ElektronikQuiz.h
*version:		1.0
*Authors:		Ahmed Kilic
*               Deborah Schrag
*               Lukas Marti          
*Firma:			FHGR
*Date:			17.12.2021
*Brief:			
*
*Changelog:		17.12.2021	Creation and first version
******************************************/

#ifndef ELEKTRONIKQUIZ_H_
#define ELEKTRONIKQUIZ_H_

//-----------------------------------------------
//Definitionen
//-----------------------------------------------
#define QUESTION_LENGTH 160
#define ANSWER_LENGTH 100

#define NUMBER_OF_QUESTIONS 42

//Typendeklarationen
typedef struct 
{
    char question[QUESTION_LENGTH]; //Frage
    char answer0[ANSWER_LENGTH];    //Antwortmöglichkeit 0
    char answer1[ANSWER_LENGTH];    //Antwortmöglichkeit 1
    char answer2[ANSWER_LENGTH];    //Antwortmöglichkeit 2
    char answer3[ANSWER_LENGTH];    //Antwortmöglichkeit 3
    char correctAnswer;             //korrekte Antwort
}t_multipleChoice;  //struct für multiple choice Fragen

//-----------------------------------------------
//Funktionsprototypen
//-----------------------------------------------
char multipleChoice(t_multipleChoice);
char elQuiz(void);
char quitQuiz(void);
float auswertung(char, char);

int exportToCSV(char[50], char[50], char[50], char[50], int);

#endif /* ELEKTRONIKQUIZ_H_ */