#ifndef MODEL_H_INCLUDED
//definiera MODEL_H_INCLUDED nu om det inte redan är inkluderat
#define MODEL_H_INCLUDED
//Till Model.C filen
#define ANTAL_TAL 7
#define MAX_TAL 35

    // i C filen skapas funktionerna men här i header deklareras dem så att andra filer kan använda dem
    void skapaRad(int rad[]);

    void skapaRader(int rader[][ANTAL_TAL], int antalRader);


#endif // MODEL_H_INCLUDED
