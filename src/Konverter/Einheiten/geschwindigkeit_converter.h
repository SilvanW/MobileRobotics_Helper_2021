/*geschwindigkeit_converter.h

Autor: Corsin Monn
Firma: FHGR Mobile Robotics
Date: 2021/12/13
Version: 0.1
Changelog:

*/

#ifndef _GESCHWINDIGKEIT_CONVERTER_H_
#define _GESCHWINDIGKEIT_CONVERTER_H_

extern void mps_to_kmph(float v);// Meter pro Sekunde zu Kilometer pro Stunde
extern void mps_to_fps(float v);// Meter pro Sekunde zu Fuss pro Sekunde
extern void mps_to_mph(float v);// Meter pro Sekunde zu Meilen pro Stunde
extern void mps_to_knot(float v);// Meter pro Sekunde zu Knoten

extern void kmph_to_mps(float v);// Kilometer pro Stunde zu Meter pro Sekunde
extern void kmph_to_mph(float v);// Kilometer pro Stunde zu Meilen pro Stunde
extern void kmph_to_knot(float v);// Kilometer pro Stunde zu Knoten
extern void kmph_to_fps(float v);// Kilometer pro Stunde zu Fuss pro Sekunde

extern void mph_to_fps(float v);// Meilen pro Stunde zu Fuss pro Sekunde
extern void mph_to_mps(float v);// Meilen pro Stunde zu Meter pro Sekunde
extern void mph_to_kmph(float v);// Meilen pro Stunde zu Kilometer pro Stunde
extern void mph_to_knot(float v);// Meilen pro Stunde zu Knoten

extern void knot_to_mph(float v);// Knoten zu Meilen pro Stunde
extern void knot_to_fps(float v);// Knoten zu Fuss pro Sekunde
extern void knot_to_mps(float v);// Knoten zu Meter pro Sekunde
extern void knot_to_kmph(float v);// Knoten zu Kilometer pro Stunde

extern void fps_to_mph(float v);// Fuss pro Sekunde zu Meilen pro Stunde
extern void fps_to_mps(float v);// Fuss pro Sekunde zu Meter pro Sekunde
extern void fps_to_kmph(float v);// Fuss pro Sekunde zu Kilometer pro Stunde
extern void fps_to_knot(float v);// Fuss pro Sekunde zu Knoten*/

#endif