/*
 * Function: Import Data from CSV File
 * 
 * Author: Silvan Wiedmer
 * Created: 13.12.2021
 * 
 * 13.12.2021 - First Version of the Program
 * 15.12.2021 - Print Data as Percentage values to console
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

char buff[1024];
int rowCount = 0;
int valIndex = 0;
Dataset values[999];

// Define File Pointer
FILE *fpt;

// Call Main Routine
int main() {

          // open file in read mode => save in fpt
          fpt = fopen("test.csv", "r");

          // Check if fpt is false
          if (!fpt) {
                    // Print reading error
                    printf("Error Reading file");

                    // return 0
                    return 0;
          }          

          // Go throung whole file
          while (fgets(buff, 1024, fpt)) {
                    // Seperate string by ", "
                    char *field = strtok(buff, ", ");

                    // Set valIndex to 0
                    valIndex = 0;

                    // Check if field exists
                    while(field != NULL) {

                              // Switch
                              switch (valIndex) {
                              case 0: // Case 0 => Date
                                        // Copy field string to Date value of rowCount index
                                        strcpy(values[rowCount].Date, field);
                                        break;
                              
                              case 1: // Case 1 => Time
                                        // Copy field string to Time value of rowCount index
                                        strcpy(values[rowCount].Time, field);
                                        break;

                              case 2: // Case 2 => Theme
                                        // Copy field string to Theme value of rowCount index
                                        strcpy(values[rowCount].Theme, field);
                                        break;

                              case 3: // Case 3 => Points
                                        // Copy field string to Points value of rowCount index
                                        strcpy(values[rowCount].Points, field);
                                        break;

                              default:
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

          // Close the file
          fclose(fpt);

          // Tell the user what theme gets presented
          printf("Thema: %s \n", values[0].Theme);

          // Sleep for 1 second
          sleep(1);

          // Loop throung all the values
          for(int i = 0; i < rowCount; i++) {
                    // Convert the String value to Int
                    int prozent = atoi(values[i].Points);

                    // Print Date & Time of Dataset creation
                    printf("%s %s ", values[i].Date, values[i].Time);
                    
                    // Loop throug integer representation of percent scored / 10 => 100% = 10 * #
                    for(int index = 1; index <= (int)(prozent / 10); index++) {
                              // Print #
                              printf("#");
                    }

                    // Print Score in Percent
                    printf("[%d%%]", prozent);
                    
                    // Print new Line
                    printf("\n");

                    // Sleep for 1 second
                    sleep(1);
          }   
}