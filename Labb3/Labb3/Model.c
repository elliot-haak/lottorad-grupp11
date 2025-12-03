#include <stdlib.h>
//bool
#include <stdbool.h>
// hämtar header fil
#include "Model.h" // med #define ANTAL_TAL 7 så att vi kan byta ut det till vad som senare om vi vill samma med MAX_TAL

void skapaRad(int rad[]){
    for(int i =0; i<ANTAL_TAL; i++){ // ANTAL_TAL
        int tal;
        bool unik =false;

        while(!unik){
            tal = rand()%MAX_TAL+1;
            unik = true;

        //kolla med tidigare tal
        for(int j =0;j<i;j++ ){
            if (rad[j] ==tal){
                unik = false;
                break;
          }
        }
      }
      //Om allt går bra sparas det unika talet
      rad[i] = tal;
    }
}
    //genererar hur många rader och rader blir en pekare till en vektor av antal tal ints
    // När ANTAL_TAL är 7 så kunde det varit rader[][7] men med antal tal kan vi ändra det i define vid behov
    void skapaRader(int rader[][ANTAL_TAL], int antalRader){

        for(int i = 0; i<antalRader;i++){
            //ropar på funktionen rader
            skapaRad(rader[i]);
        }

    }
