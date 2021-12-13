/*
 * Function: Import Data from CSV File
 * 
 * Author: Silvan Wiedmer
 * Created: 13.12.2021
 * 
 * 13.12.2021 - First Version of the Program
 */

// Include the Required Libraries => Required for FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
          fpt = fopen("test.csv", "r");

          if (!fpt) {
                    printf("Error Reading file");
                    return 0;
          }          

          int i = 0;
          while (fgets(buff, 1024, fpt)) {
                    char *field = strtok(buff, ", ");
                    valIndex = 0;
                    while(field != NULL) {
                              switch (valIndex) {
                              case 0:
                                        strcpy(values[rowCount].Date, field);
                                        break;
                              
                              case 1:
                                        strcpy(values[rowCount].Time, field);
                                        break;

                              case 2:
                                        strcpy(values[rowCount].Theme, field);
                                        break;

                              case 3:
                                        strcpy(values[rowCount].Points, field);
                                        break;

                              default:
                                        break;
                              }
                              field = strtok(NULL, ", ");
                              valIndex++;
                    }

                    rowCount++;
          }

          fclose(fpt);

          for(int i = 0; i < rowCount; i++) {
                    printf("Daten: %s, %s, %s, %s", values[i].Date, values[i].Time, values[i].Theme, values[i].Points);
                    printf("\n");
          }   
}