#ifndef HEADERS
#define HEADERS

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

#define rozmiar_planszy 8

char plansza[rozmiar_planszy][rozmiar_planszy] = 
{
    {'a', 'o', 'a', 'o', 'a', 'o', 'a', 'o'},
    {'o', 'a', 'o', 'a', 'o', 'a', 'o', 'a'},
    {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
    {'o', 'o', 'o', 'o', 'o', 'c', 'o', 'o'},
    {'o', 'o', 'o', 'o', 'a', 'o', 'o', 'o'},
    {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
    {'b', 'o', 'd', 'o', 'b', 'o', 'b', 'o'},
    {'o', 'b', 'o', 'b', 'o', 'b', 'o', 'b'}
};

typedef struct p
{
    char kolor;     //gracz = 'b', komputer = 'a'
    int typ;    //zwykly = 1, damka = 2
    int pozycja_x;
    int pozycja_y;
} pionek;

void ruch_gracza(char znak, int *wsk_gracz_x, int *wsk_gracz_y, char plansza[rozmiar_planszy][rozmiar_planszy], bool *czy_wybrany, pionek *aktualny);
void wykonaj_ruch(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany);
void namaluj_plansze(char plansza[rozmiar_planszy][rozmiar_planszy], int gracz_x, int gracz_y, bool czy_wybrany, pionek *aktualny);

bool ruch_pionka(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany, char plansza[rozmiar_planszy][rozmiar_planszy], char kolor);
void bicie_pionka(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany);

bool ruch_damki(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany);
bool bicie_damki(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany);

int damka_ile_figur_pomiedzy(int poz_gracza_x, int poz_gracza_y, pionek *aktualny);

char pobierz_znak(void);
void wpisz_do_pionka(pionek *wsk, char kolor, int typ, int x, int y);
void przepisz_do_tablicy(char cel[rozmiar_planszy][rozmiar_planszy], char zrodlo[rozmiar_planszy][rozmiar_planszy]);
int getch(void);

#endif //HEADERS