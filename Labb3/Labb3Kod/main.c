#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUM 35
#define MAX_ANTAL 7

void drawLotto(int row[]);
int enterRows();
void textUI(void);

int main(void){
    srand(time(NULL));
    textUI();   // starta huvudmenyn
    return 0;
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

int enterRows(void){

  int num;

  srand(time(NULL));

  printf("Ange antal lottorader: ");

  if(scanf("%d", &num) != 1){
    printf("ange ett heltal\n");
    return 1;
  }

  for(int x = 0; x < num; x++){
    int row[MAX_ANTAL];
    drawLotto(row);

    for(int y = 0; y < MAX_ANTAL; y++){
      printf("%d ", row[y]);
    }

    printf("\n");
  }

  return 1;
}

void textUI(){
  int val;

  while(1){

      printf("Menu för lottrader\n");
      printf("1. Generera nya lottorader\n");
      printf("2. läs fil\n");
      printf("3. Avsluta\n");

      printf("ditt val: ");
      // inte nummer eller över 3
      if (scanf("%d", &val) != 1|| val>3) {
          printf("\nFel inmatning, går tillbaka till startsidan.\n");

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
      enterRows();
      break;

    case 2:
      break;

    case 3:
      printf("Avslutar...");
      exit(0);

    default:
      break;
  }
}
