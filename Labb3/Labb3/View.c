#include <stdio.h>
#include <stdlib.h>
#include "View.h"

    int askAntalrader(){
        int antal =0;

        printf("Antal rader att skriva ut: ");
        scanf("%d",&antal);

    //Vi kollar att de inte skriver noll eller ett ord
    //Om de skriver 0 eller eller använder ord så kommer det bli det gamla värdet
        while(antal <= 0){
            printf("Du måste ange ett heltal: ");
            scanf("%d",&antal);
        }
        return antal;
    }
   //Skriver ut en rad med antal tal
    void skrivaUtRad(int rad[]){

        for(int i =0; i<ANTAL_TAL; i++){
            printf("%d ",rad[i]);
        }
      printf("\n");
    }
    //skriver ut alla raderna med rätt antal tal
    void skrivUtAllaRader(int rader[][ANTAL_TAL],int antalRader){

        for(int i =0; i< antalRader; i++){
            skrivaUtRad(rader[i]);
        }
    }
