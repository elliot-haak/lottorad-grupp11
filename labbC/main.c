#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int startInput;
int andraVal;


// ##### DETTA ANVÄNDS INTE JUST NU!!!
// void textUI(int val) {
    
//     switch (val)
//     {
//     case 1:
//         printf("här kommer ny lottorad\n");
//         //draLotto();
//         //textUI("postLotto");
//         break;
//     case 2:
//         printf("gamla lotter kommer här \n");
//         //Hämtagammla();
//         //textUI("");
//         break;
//     case 3:
//         printf("shutting down... \n");
//         break;
//     default:
//         printf("Ange giltigt nummer! \n");
//         //main();
//         break;
//     }
// } #######

int exArr[7] = {3, 6, 3, 6, 7, 6, 9}; //Exempel array
int arrLen = sizeof(exArr) / sizeof(exArr[0]); // längden av array för looping

// FILhANTERING
void saveToCSV(int arr[], int n) { //spara till fil
    FILE *stream = fopen("lotto.csv", "a+");
    for(int i = 0; i < n; i++) {
        fprintf(stream, "%d ", exArr[i]);    // or "%d " for same-line
    }
    fprintf(stream, "\n");
    fclose(stream);
    for (int i = 0; i < n; i++) {
        printf("%d ", exArr[i]);
    }
    printf("blev sparad till lotto.csv! \n");    
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
}

int main() {
    float input; // Ta emot en float från användaren
    int convertedInput; //Float som är konverterad till int
    printf("Välj val - \n1 - Spara rad\n2 - Läsa lottofil");
    scanf("%f", &input);
    convertedInput = (int)input; // Type casata floaten till en int
    printf("%i, %2f \n",convertedInput ,input);

    //Om inputen är x: (Skulle också kunna använda switch case här)
    if(convertedInput == 1) {
      saveToCSV(exArr, arrLen); 
      return 1; 
    }
    if(convertedInput == 2) {
       readFromCSV(); 
       return 1;
    }
    //Om inget stämmer gör:
    printf("Ogiltig input, avslutar...");
}
