#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUM 35
#define MAX_ANTAL 7

void drawLotto(int row[]);
int enterRows();
void textUI(int val);

int main(){

  int val;

  printf("Menu för lottrader\n");
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

int enterRows(){

  int num;

  srand(time(NULL));

  printf("Ange antal lottorader: ");

  if(scanf("%d", &num) != 1){
    printf("ange ett tal! avslutar\n");
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


void textUI(int val){

  printf("1. Generera ny rad/rader | ");
  printf("2. spara rader till fil | ");
  printf("3. Startsida | ");
  printf("4. Avsluta\n");
  printf("ditt val: ");
  scanf("%d", &val);
  switch(val){
    case 1:
      enterRows();
      textUI(val);
    break;

    case 2:
      //funktion sparafiler här
    break;

    case 3:
      main();
    break;

    default:
      //funktion sparafiler här
    break;

  }
}
