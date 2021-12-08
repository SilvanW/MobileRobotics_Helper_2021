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

// Functions
int exportToCSV(char[50], char[50], char[50],char[50],int);

// Call Main Routine
int main() {
          exportToCSV("test.csv","08.12.21","21:52","Mathematik_1",55);
}

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