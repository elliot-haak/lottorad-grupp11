#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
//ANTAL_TAL från model.h filen
#include "Model.h"

//För att ta reda på användarens önskemål för antal rader
 int askAntalrader();

//För att skriva ut en rad
 void skrivaUtRad(int rad[]);

//För att skriva ut alla rader
 void skrivUtAllaRader(int rader[][ANTAL_TAL],int antalRader);

#endif // VIEW_H_INCLUDED
