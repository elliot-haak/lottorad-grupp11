#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "header.h"

//satt konstaner för lottoradernas storlek och längd
#define MAX_NUM 35
#define MAX_ANTAL 7


int main() {
    int choice;
    //variable för antal rader
    int antal = 0;                       
    //en två dimensionll array som vi använde oss av i java application också. 
    //vi valde att göra den 100 rader stor för att sätta en viss begränsning
    int rows[100][MAX_ANTAL];             
    int c;

    srand(time(NULL));

    while (1) {
        printf("\n--- Lotto ---\n");
        printf("1. Generera nya rader\n");
        printf("2. Spara genererade rader till fil\n");
        printf("3. Läs fil\n");
        printf("4. Avsluta\n");
        printf("Val: ");


        //denna bit är tagen från chatgpt och återanvänder den några rader ner.
        //prompt: Hur tömmer jag bufferten i c?
        /*svar: int x;
            if (scanf("%d", &x) != 1) {
                // felaktig input – töm bufferten
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
            }*/

        if(scanf("%d", &choice) != 1) {
          printf("Error: Ange en siffra 1-4");
          while((c = getchar()) != '\n' && c != EOF);
          continue;

    }

        //vid inmatning med 0.+(1-9) så ligger den kvar till switch satsen och vi hamnade i default i switch satsen 
        while((c = getchar()) != '\n' && c != EOF);

        //meny med en switch med cases som representerar menyvalen som lagras i variabeln choice
        switch(choice) {

            case 1: {

                 printf("Hur många rader vill du generera? ");
                //Här är nästa kod snutt som är tagen från chatgpt och har återanvänt samma prompt
                if(scanf("%d", &antal) != 1) {
                  printf("\nError: Ange en siffra 1-4");
                  while((c = getchar()) != '\n' && c != EOF);
                  antal = 0;
                  break;
                }

            // töm resten av raden även vid lyckad inläsning såsom 0.någonting
               //while ((c = getchar()) != '\n' && c != EOF){}

                //kontrollerar så användaren anger rätt mängd rader, där vi ha begränsat till 100 rader
                //vid fel så skriver vi ett fel meddelande och användaren får återgå till menyvalen
                //nollställer variablen antal så inga rader genereras och kan ej spara tomma rader
                if (antal < 1 || antal > 100) {
                    printf("Ogiltigt antal!\n");
                    antal = 0;
                    break;
                }

                //utskrit för de genererade lottorader 
                //anropar drawLotto funktionen och skickar med arrayen där i representerar antal rader
                //en till loop som skriver ut den 2 dimensionella arrayen med rader + antal nummer per rad
                printf("Genererade rader:\n");
                for (int i = 0; i < antal; i++) {
                    drawLotto(rows[i]);

                    for (int j = 0; j < MAX_ANTAL; j++)
                        printf("%d ", rows[i][j]);
                    printf("\n");
                }
                break;
            }

            case 2:
                //kontrollerar så att det finns rader att spara
                //finns det inga rader så skrivs det ut felmeddelande
                //finns det rader så sparas dem till filen lotto.csv via funktionen saveToCSV
                if (antal == 0) {
                    printf("Inga rader att spara! Generera först.\n");
                } else {
                    saveToCSV(rows, antal);
                    printf("Raderna sparades till lotto.csv!\n");
                }
                break;

            case 3:
                //anropar funktionen som läser alla rader i filen och även skriver ut dem
                readFromCSV();
                break;

            case 4:
                printf("Avslutar...\n");
                return 0;

            default:
                printf("Fel val: Ange ett tal 1-4\n");
                break;
        }
    }
}

//funktion som drar lottot med ranomiserade nummer
void drawLotto(int row[]){

  for(int x = 0; x < MAX_ANTAL; x++){

    int randomNum;
    //hämtat bool från biblioteket stdbool.h
    //använder boolean som kontroller för att starta och avsluta while loop
    bool unique = false;

    while(!unique){

      //genererar ett slump nummer mellan 1 och 35
      randomNum = rand() % MAX_NUM + 1;
      unique = true;

      //dyker det upp en nummer som är lika med varandra så körs loopen om och genererar ett nytt nummer
      for(int y = 0; y < x; y++){
        if(row[y] == randomNum){
          unique = false;
        }
      }

      //lägger till det slumpmässiga numret till arrayen rows
      row[x] = randomNum;

    }
  }

}

//funktion som sparar lottorader
void saveToCSV(int rows[][MAX_ANTAL], int antal) {
  //skapar filpekaren som öppnar lotto.csv 
  //använder option a+ som öppnar fil om den finns, finns den inte så skapas den 
  //a för append så att nya rader inte överskriver existerande lottorader
    FILE *f = fopen("lotto.csv", "a+");
  //kontroll så f finns annars skriver vi ut att filen inte kunde öppnas
    if (!f) {
        printf("Kunde inte öppna lotto.csv!\n");
        return;
    }

  //skriver till filen 
  //skriver den 2 dimensionalla arrayen till filen med radbrytning
    for (int i = 0; i < antal; i++) {
        for (int j = 0; j < MAX_ANTAL; j++)
            fprintf(f, "%d ", rows[i][j]);
        fprintf(f, "\n");
    }

  //stänger filen efter vi har skrivit
    fclose(f);
}

//funktion som läser filen
void readFromCSV() {
  //öppnar filen i read option
    FILE *f = fopen("lotto.csv", "r");
  //kontrollerar så f finns, skriver ut felmeddelande 
    if (!f) {
        printf("Ingen fil hittad.\n");
        return;
    }

  //loopar igenom hela filens innehåll och skriver ut det
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), f))
        printf("%s", buffer);

  //stänger fil 
    fclose(f);
}

/*Motivation av val med textbaserad fil:  För att detta är en enkel samling med heltal. Tex en tvådimensionell array är
tillräcklig. Men om man skulle göra denna ännu mer komplex så skulle det nog vara enklare att använda sig av en
structbaserad fil med flera typer av fält som kan användas då skulle det kunna finnas mer fördelar.*/
