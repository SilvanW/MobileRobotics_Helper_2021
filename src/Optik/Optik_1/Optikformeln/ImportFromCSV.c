/*
 * Function: Import Data from CSV File
 * 
 * Author: Silvan Wiedmer
 * Created: 13.12.2021
 * Changed: Adrian Rebsamen
 * Date of Change: 19.12.2021
 * 
 * 13.12.2021 - First Version of the Program
 * 15.12.2021 - Reading & Giving Feedback to user
 * 19.12.2021 - Reading Questions from a CSV file and importing them in to the Programm
 */

// Include the Required Libraries => Required for FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// Define Dataset Structure
typedef struct {
          char Theme[100];
          char *Question;
          char *Answers;
          char Answer[2];
} Dataset;

// Define Variables
char buff[1024];
int rowCount = 0;
int valIndex = 0;
Dataset values[999];

// Define File Pointer
FILE *fpt;

// Call Main Routine
int importFromCSV(char Filename[50]) {

          // Open File in read mode and save to fpt variable
          fpt = fopen(Filename, "r");

          // Check if fpt is false
          if (!fpt) {
                    // Errpor Reading file
                    printf("Error Reading file");
                    return 0;
          }          

          // Go through the entire file
          while (fgets(buff, 1024, fpt)) {
                    // Seperate buffered strings
                    char *field = strtok(buff, ", ");

                    printf("%s", field);

                    // Set valIndex to 0
                    valIndex = 0;

                    // While field is not NULL
                    while(field != NULL) {

                              // Switch by valIndex
                              switch (valIndex) {
                              case 0: // Case 0 => Theme
                                        strcpy(values[rowCount].Theme, field);
                                        break;
                              
                              case 1: // Case 1 => Question
                                        strcpy(values[rowCount].Question, field);
                                        break;

                              case 2: // Case 2 => Answers
                                        strcpy(values[rowCount].Answers, field);
                                        break;

                              case 3: // Case 3 => Answer
                                        strcpy(values[rowCount].Answer, field);
                                        break;

                              default: // Default case => Break
                                        break;
                              }

                              // Set Field to Null
                              field = strtok(NULL, ", ");

                              // Increase valIndex by 1
                              valIndex++;
                    }
                    // Increase rowCount by 1
                    rowCount++;
          }

          // close file
          fclose(fpt);

return 0;

}

int main() {
    importFromCSV("Reflexion_Brechung.csv");

    return 0;
}