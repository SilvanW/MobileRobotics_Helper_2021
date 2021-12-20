#ifndef ZAHLENKONVERTER_H
#define ZAHLENKONVERTER_H

///////////////
// Libraries //
///////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>


//////////////////
// Enumerations //
//////////////////

typedef enum
{
	CONV_EXIT,
	CONV_DECIMAL,
	CONV_BINARY,
	CONV_HEXADECIMAL,
	CONV_OTHER,
	CONV__COUNT,
}
ConverterTypes;


////////////////////////////////
// Public Function Prototypes //
////////////////////////////////

void NumberConverter(void);


#endif
