#include <stdio.h>
#include <stdlib.h>
//srand behöver ett frö
#include <time.h>
//inkludera model.h för att använda metoderna
#include "Model.h"
#include "View.h"


int main(){

        srand(time(NULL));
        //metod för att hämta antal rader
        int antalRader =  askAntalrader();  //kan testas med ett eget heltal istället
        int rader[antalRader][ANTAL_TAL];

        // fyller vektorn med slumpade rader
        skapaRader(rader,antal);
        //skriv ut alla rader utifrån antal
        skrivUtAllaRader(rader,antal);

    return 0;
}
