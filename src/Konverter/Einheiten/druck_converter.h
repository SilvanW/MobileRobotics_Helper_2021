/*druck_converter.h

Autor: Corsin Monn
Firma: FHGR Mobile Robotics
Date: 2021/12/13
Version: 0.1
Changelog:

*/
#ifndef _DRUCK_CONVERTER_
#define _DRUCK_CONVERTER_


extern void bar_to_pascal(float p);

extern void pascal_to_bar(float p);

extern void atm_to_bar(float p);

extern void atm_to_pascal(float p);

extern void bar_to_atm(float p);

extern void pascal_to_atm(float p);

extern void psi_to_atm(float p);

extern void psi_to_bar(float p);

extern void psi_to_pascal(float p);

extern void atm_to_psi(float p);

extern void bar_to_psi(float p);

extern void pascal_to_psi(float p);

#endif