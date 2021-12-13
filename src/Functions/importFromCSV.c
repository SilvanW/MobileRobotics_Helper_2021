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
#include <string.h>

// Define Dataset Structure
typedef struct {
          char Date[50];
          char Time[50];
          char Theme[50];
          char Points;
} Dataset;

// Define Array of Dataset => DataArray
Dataset DataArray[50];

char char1[50];
char char2[50];
char char3[50];
int percent;

// Define File Pointer
FILE *fpt;

char num[50];

// Call Main Routine
int main() {
          fpt = fopen("test.csv", "r");
          
          while(fscanf(fpt, "%c, %c, %c, %d", char1, char2, char3, &percent) == 2) {
                    printf("%s, %s, %s, %d", char1, char2, char3, percent);
          }
          

          fclose(fpt);
}