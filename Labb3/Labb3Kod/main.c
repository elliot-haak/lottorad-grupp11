#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>//strcat

#define MAX_NUM 35
#define MAX_ANTAL 7

//filhanterings variabler
int startInput;
int andraVal;

//metoder
void drawLotto(int row[]);
int enterRows();
void textUI(void);
void saveToCSV(int arr[], int n);
void readFromCSV(void);


int main(void){
    system("chcp 1252"); // svenska

    srand(time(NULL));
    textUI();   // starta huvudmenyn
    //saveToCSV(row, arrLen); ligger i enterRows istället
     //readFromCSV();
    return 0;
}
//metod för att generara lotter
void drawLotto(int row[]){

  for(int x = 0; x < MAX_ANTAL; x++){

    int randomNum;
    bool unique = false;

    while(!unique){

      randomNum = rand() % MAX_NUM + 1;
      unique = true;

      for(int y = 0; y < x; y++){
        if(row[y] == randomNum){
          unique = false;
        }
      }
      row[x] = randomNum;

    }
  }

}
//Metoder för att ange lotter
int enterRows(void){

  int num;

  srand(time(NULL));

  printf("Ange antal lottorader: ");

  if(scanf("%d", &num) != 1){
    printf("ange ett heltal\n");
    return 1;
  }
 int row[MAX_ANTAL];
  for(int x = 0; x < num; x++){

    drawLotto(row);

    for(int y = 0; y < MAX_ANTAL; y++){
      printf("%d ", row[y]);
    }
    printf("\n");
  }


    //spara eller inte spara
    int sparaVal;


    printf("\n Vill du spara? 1=ja 0=nej. Ditt svar: ");

    while(scanf("%d", &sparaVal) != 1) {
    printf("\n Nu gjorde du fel, Vill du spara? 1=ja 0=nej. Ditt svar: ");
    int c;
            while ((c = getchar()) != '\n' && c != EOF) {

            }
    }
            // tömmer alltid resten av raden tex vid decimaltal
        int d;
        while ((d = getchar()) != '\n' && d != EOF) {

        }

    if(sparaVal == 0){
       printf("Detta sparas inte vidare till meny");
    }
    else if(sparaVal == 1){

         printf("Ja vi sparar din lottorad eller dina lottorader");

             printf("\n");
             saveToCSV(row, MAX_ANTAL);

            }

       else{
           printf("Du måste ange 0 eller 1\n");
       }

         return 1;
  }




void textUI(){
  int val;
  //inre och yttre while loop för att få menyn att loopa även vid sparning
  while(1){
      while(1){

          printf("Menu för lottrader\n");
          printf("1. Generera nya lottorader\n");
          printf("2. läs fil\n");
          printf("3. Avsluta\n");

          printf("ditt val: ");
          // inte nummer eller över 3
          if (scanf("%d", &val) != 1|| val>3) {
              printf("\n Du måste ange en siffra mellan 1-3, försök igen: \n");

              // Töm inmatningsbufferten (släng allt fram till radslut)
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                    // gör inget, bara läser bort tecknen
                }

                printf("\n");

             continue; // gå tillbaka till menyn
          }
          break;

  }

      switch(val){
        case 1:
          printf("\n");
          enterRows();
          printf("\n");
          break;

        case 2:
        printf("\n");
        readFromCSV();
        printf("\n");

          break;

        case 3:
          printf("Avslutar...");
          exit(0);

        default:
          break;
      }
    }
}
// FILhANTERING
void saveToCSV(int arr[], int n) { //spara till fil
    FILE *stream = fopen("lotto.csv", "a");
    for(int i = 0; i < n; i++) {

                fprintf(stream, "%d ", arr[i]);
    }
    fprintf(stream, "\n");
    fclose(stream);
}

void readFromCSV() { //Läsa fil
    FILE *stream = fopen("lotto.csv", "r");
    char buffer[100];
    char all[500] = "";
    while (fgets(buffer, sizeof(buffer), stream)) { //skapa lagring och loopa alla rader styckvis
        printf("%s", buffer); // print ut varje enskild rad

        strcat(all, buffer); //lägga ihopp allting från varje buffer,
        //Detta behövs endast om man vill slå ihopp allt till en String
    }
     printf("\n");
    //printf("%s", all);
}

