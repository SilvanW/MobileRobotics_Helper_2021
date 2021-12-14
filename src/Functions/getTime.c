#include <stdio.h>
#include <time.h>

int main() {
          time_t now;
	now = time(0);

          printf("Time %s \n", ctime(&now));
}