#ifndef ZAHLENKONVERTER_H
#define ZAHLENKONVERTER_H

// Benötigte Libraries includen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum
{
	EXIT,
	DECIMAL,
	BINARY,
	HEXADECIMAL,
}
ConverterTypes;

// Funktionsprototyp
void NumberConverter(void);

#endif
