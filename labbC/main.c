#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int startInput;
int andraVal;

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
// }
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
    while (fgets(buffer, sizeof(buffer), stream)) { //skapa lagring
        printf("Lottorad: %s", buffer);
        strcat(all, buffer); //lägga ihopp allting från varje buffer
    }
    
    //printf("%s", all);
}

int main() {
    // printf("Välj alternativ \n");
    //     printf(
    //         "1 - Dra lottorad \n2 - Gamla lottorader \n3 - Stäng av\n"
    //     );
    //     scanf("%d", &startInput);
    //     textUI(startInput);
    saveToCSV(exArr, arrLen);
    readFromCSV();
}
