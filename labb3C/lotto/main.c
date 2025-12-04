#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Header.h"
#include <stdio.h>
#include <string.h>

#define MAX_NUM 35
#define MAX_ANTAL 7


int main(){

  int val;
    
  printf("****Menu för lottrader****\n");
  printf("1. Generera nya lottorader\n");
  printf("2. läs fil\n");
  printf("3. Avsluta\n");

  printf("ditt val: ");

  scanf("%d", &val);

  switch(val){
    case 1:
      enterRows();
      textUI(val);
    break;

    case 2:
     readFromCSV();
    break;

    default:
         
      break;
  }


}

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

int raderCount = 0; //Håller koll på rader
int rader[100][MAX_ANTAL]; //2d-array som ska kunna lagra flera lottorader tills de sparas till fil.

int enterRows(){

  int num;

  srand((int)time(NULL));
  

  printf("Ange antal lottorader: ");

  if(scanf("%d", &num) != 1){
    printf("ej ett heltal! Avslutar\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 1;
  }
    
  for(int x = 0; x < num; x++){
    int row[MAX_ANTAL];
    drawLotto(row);

    for(int y = 0; y < MAX_ANTAL; y++){
      printf("%d ", row[y]);
        rader[raderCount][y] = row[y]; //Lagrar talet i arrayen
    }
      raderCount++;
     
    printf("\n");
  }

  return 0;
    
}


void textUI(int val){

  printf("****Menu för lottrader****\n");
  printf("1. Generera ny rad/rader | ");
  printf("2. Spara rader till fil | ");
  printf("3. Rensa rader och gå till startsida | ");
  printf("4. Avsluta\n");
  printf("ditt val: ");
  scanf("%d", &val);
  switch(val){
    case 1:
      enterRows();
      textUI(val);
    break;

    case 2:
          //Känns överflödig??
          if(raderCount == 0){
              printf("Finns inga lottorader att spara\n Generera en lottorad för at kunna spara");
          }else{
              saveToCSV();
          }
    break;

    case 3:
      raderCount = 0;
      main();
    break;


    default:
          
    break;
    
  }
}
//int exArr[7] = {3, 6, 3, 6, 7, 6, 9}; //Exempel array
//int arrLen = sizeof(exArr) / sizeof(exArr[0]); // längden av array för looping


// FILhANTERING
void saveToCSV(int arr[], int n) { //spara till fil
    FILE *stream = fopen("lotto.csv", "a+");
       
    for(int i = 0; i < raderCount; i++){ //Loopar igenom alla lagrade rader
        for(int j = 0; j < MAX_ANTAL; j++){ //Loopar igneom varje tal
            fprintf(stream, "%d ", rader[i][j]);    // or "%d " for same-line
        }
        fprintf(stream, "\n");
    }
    
    fclose(stream);
   
    printf("blev sparad till lotto.csv! \n");
    raderCount = 0; //Rensar bufferten (genererade raderna) efter sparning
    main(); //Ropar på main för att komma tillbaka till "startsidan"
}

void readFromCSV() { //Läsa fil
    FILE *stream = fopen("lotto.csv", "r");
    char buffer[100];
    char all[500] = "";
    while (fgets(buffer, sizeof(buffer), stream)) { //skapa lagring och loopa alla rader styckvis
        printf("Lottorad: %s", buffer); // print ut varje enskild rad

        strcat(all, buffer); //lägga ihopp allting från varje buffer,
        //Detta behövs endast om man vill slå ihopp allt till en String
       
       
    }
    
    //printf("%s", all);
    main(); //Ropar på main för att komma tillbaka till startsidan
}



//När man sparar till textfil avslutas programmet. --> Ropa på main
//samma i läs fil --> ropa på main

//Gjorde en 2d array som ska kunna lagra lottorader innan de sparas

/*Buggar:
Läste fil och fick:  Varför är det mitt fel? Hur det det ut i den faktiska textfilen
 Lottorad:
 Lottorad:
 Lottorad: 8 28 24 22 15 2 9
 Lottorad: 14 1 32 6 10 31 29
 Lottorad: 23 17 33 25 3 15 26

 2.
 Om man inte vill spara och bara går till "startsida" så sparas lottoraderna ändå. Behövs att rensa 
 // Vi måte rensa rader innan vi går till startsida i switch - case 3
 
*/

