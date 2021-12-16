#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define variables
char day[10];
char mon[10];
char year[10];
char dateNew[40];

char hour[10];
char min[10];
char timeNew[30];

char *getDate() {
          // Define Time variable
          time_t s;

          // Define Time struct
          struct tm* current_time;
          
          // Set Time variable to NULL
          s = time(NULL);
          
          // Set Current_Time to localtime from Time variable
          current_time = localtime(&s);

          // Convert Day / Month / Year values to strings
          sprintf(day, "%d." ,current_time->tm_mday);
          sprintf(mon, "%d.",(current_time->tm_mon + 1));
          sprintf(year, "%d",(current_time->tm_year - 100));
          
          // Create date Char
          strcat(dateNew,day);
          strcat(dateNew,mon);
          strcat(dateNew,year);

          // return date
          return dateNew;
}

char *getTime() {
          // Define Time variable
          time_t s;

          // Define Time struct
          struct tm* current_time;
          
          // Set Time variable to NULL
          s = time(NULL);
          
          // Set Current_Time to localtime from Time variable
          current_time = localtime(&s);

          // Convert Hour / Minute values to strings
          sprintf(hour, "%d." ,current_time->tm_hour);
          sprintf(min, "%d",current_time->tm_min);

          // Check if Hour has one digit
          if (current_time->tm_hour < 10) {
                    // Add 0 before value
                    sprintf(hour, "0%d.", current_time->tm_hour);
          }

          // Check if Minute has one digit
          if (current_time->tm_min < 10) {
                    // Add 0 before value
                    sprintf(min, "0%d", current_time->tm_min);
          }

          // Create timeNew Char
          strcat(timeNew,hour);
          strcat(timeNew,min);

          // return date
          return timeNew;
}