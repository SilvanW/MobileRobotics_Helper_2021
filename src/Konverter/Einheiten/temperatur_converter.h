/* 
temperatur_converter.h

Converts various temperature units

Author: Michael Albisser
Company: FHGR
Version: 0.1
Date: 13.12.2021
Changelog:
0.1 13.12.2021 the program file created
*/

#ifndef TEMPERATUR_CONVERTER_H
#define TEMPERATUR_CONVERTER_H

extern void celsius_to_kelvin(float t);
extern void celsius_to_farenheit(float t);
extern void kelvin_to_celsius(float t);
extern void kelvin_to_farenheit(float t);
extern void farenheit_to_celsius(float t);
extern void farenheit_to_kelvin(float t);

#endif