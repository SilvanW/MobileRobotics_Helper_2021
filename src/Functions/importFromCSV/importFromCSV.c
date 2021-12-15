/*
 * Function: Import Data from CSV File
 * 
 * Author: Silvan Wiedmer
 * Created: 13.12.2021
 * 
 * 13.12.2021 - First Version of the Program
 * 15.12.2021 - Reading & Giving Feedback to user
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
          char Date[50];
          char Time[50];
          char Theme[50];
          char Points[50];
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

                    // Set valIndex to 0
                    valIndex = 0;

                    // While field is not NULL
                    while(field != NULL) {

                              // Switch by valIndex
                              switch (valIndex) {
                              case 0: // Case 0 => Date
                                        strcpy(values[rowCount].Date, field);
                                        break;
                              
                              case 1: // Case 1 => Time
                                        strcpy(values[rowCount].Time, field);
                                        break;

                              case 2: // Case 2 => Theme
                                        strcpy(values[rowCount].Theme, field);
                                        break;

                              case 3: // Case 3 => Points
                                        strcpy(values[rowCount].Points, field);
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

          // Print Theme to Console
          printf("Thema: %s \n", values[0].Theme);

          // Sleep for 1 second
          sleep(1);

          // Loop through all rows
          for(int i = 0; i < rowCount; i++) {
                    // Get Integer represantation of Points string
                    int prozent = atoi(values[i].Points);

                    // Print Date & Time to console
                    printf("%s %s ", values[i].Date, values[i].Time);
                    
                    // For every 10 Percent of points add # to line
                    for(int index = 1; index <= (prozent / 10); index++) {
                              printf("#");
                    }

                    // Print exact number to Console
                    printf("[%d%%] \n", prozent);

                    // Sleep for 1 second
                    sleep(1);
          }  

          return 0;
}