/*
 * Function: Export to CSV function. External function to export the Test Data to the according CSV file.
 * 
 * Author: Silvan Wiedmer
 * Created: 08.12.2021
 * 
 * 08.12.2021 - First Version of the Program
 */

// Include the Required Libraries
#include <stdio.h>

// Define Export To CSV Function
int exportToCSV(char Filename[50], char Date[50], char Time[50], char Theme[50], int Points) {

          // Define File
          FILE *fpt;

          // Open File in write mode
          fpt = fopen(Filename, "w");

          // Append Data to File
          fprintf(fpt,"%s, %s, %s, %d\n", Date, Time, Theme, Points);

          // Close File
          fclose(fpt);

          return 0;
}