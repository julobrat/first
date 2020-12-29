#include "headers.h"

bool ruch_pionka(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany, char plansza[rozmiar_planszy][rozmiar_planszy], char kolor)
{
    plansza[poz_gracza_y][poz_gracza_x] = kolor;
    plansza[aktualny->pozycja_y][aktualny->pozycja_x] = 'o';
    *czy_wybrany = false;
    wpisz_do_pionka(aktualny, '\0', 0, 0, 0);  // wyzeruj aktualnego pionka
    return true;
}

void bicie_pionka(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany)
{
    //jesli za bitym pionkiem jest pusto
    if(poz_gracza_x > aktualny->pozycja_x && plansza[poz_gracza_y][poz_gracza_x] == 'o' ||
      (poz_gracza_x < aktualny->pozycja_x && plansza[poz_gracza_y][poz_gracza_x] == 'o') )
    {
        int yyy = 0;
        plansza[poz_gracza_y][poz_gracza_x] = 'b';
        plansza[aktualny->pozycja_y][aktualny->pozycja_x] = 'o';
        // bicie do przodu, a else do tylu
        if(poz_gracza_y < aktualny->pozycja_y) yyy = aktualny->pozycja_y - 1;
        else yyy = aktualny->pozycja_y + 1;
        // bicie w prawo, a else w lewo
        if(poz_gracza_x > aktualny->pozycja_x)
            plansza[yyy][aktualny->pozycja_x + 1] = 'o';
        else
            plansza[yyy][aktualny->pozycja_x - 1] = 'o';
        *czy_wybrany = false;
        wpisz_do_pionka(aktualny, '\0', 0, 0, 0);  // wyzeruj aktualnego pionka
        //return true;
    }
    //return false;
}

bool ruch_damki(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany)
{
    plansza[poz_gracza_y][poz_gracza_x] = 'd';
    plansza[aktualny->pozycja_y][aktualny->pozycja_x] = 'o';
    *czy_wybrany = false;
    wpisz_do_pionka(aktualny, '\0', 0, 0, 0);  // wyzeruj aktualnego pionka
    return true;
}

bool bicie_damki(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany)
{
    if(damka_ile_figur_pomiedzy(poz_gracza_x, poz_gracza_y, aktualny) == 1)
    {
        int roznica_x = poz_gracza_x - aktualny->pozycja_x;
        int roznica_y = poz_gracza_y - aktualny->pozycja_y;
        int odleglosc = roznica_x;
        if(odleglosc < 0) odleglosc = -odleglosc;
        // +1 albo -1, krok przy sprawdzaniu
        int wspx = roznica_x / odleglosc;
        int wspy = roznica_y / odleglosc;
        int ofiarax = 0;
        int ofiaray = 0;
        for(int i = 1; i < odleglosc; ++i)
        {
            if( plansza[aktualny->pozycja_y + i*wspy][aktualny->pozycja_x + i*wspx] == 'a' ||
                plansza[aktualny->pozycja_y + i*wspy][aktualny->pozycja_x + i*wspx] == 'c' )
            {
                ofiarax = aktualny->pozycja_x + i*wspx;
                ofiaray = aktualny->pozycja_y + i*wspy;
            }
        }
        plansza[poz_gracza_y][poz_gracza_x] = 'd';
        plansza[ofiaray][ofiarax] = 'o';
        plansza[aktualny->pozycja_y][aktualny->pozycja_x] = 'o';
        *czy_wybrany = false;
        wpisz_do_pionka(aktualny, '\0', 0, 0, 0);  // wyzeruj aktualnego pionka
        return true;
    }
    return false;
}

int damka_ile_figur_pomiedzy(int poz_gracza_x, int poz_gracza_y, pionek *aktualny)
{
    int roznica_x = poz_gracza_x - aktualny->pozycja_x;
    int roznica_y = poz_gracza_y - aktualny->pozycja_y;
    // jesli ruch nie jest po przekatnej
    if(roznica_x != roznica_y && roznica_x !=  -roznica_y)
        return 999;  // ma wywalic funkcje
    int odleglosc = roznica_x;
    if(odleglosc < 0) odleglosc = -odleglosc;
    // +1 albo -1, krok przy sprawdzaniu
    int wspx = roznica_x / odleglosc;
    int wspy = roznica_y / odleglosc;
    int ile_figur = 0;

    for(int i = 1; i < odleglosc; ++i)
    {
        if( plansza[aktualny->pozycja_y + i*wspy][aktualny->pozycja_x + i*wspx] != 'o' )
            ++ile_figur;
        if( plansza[aktualny->pozycja_y + i*wspy][aktualny->pozycja_x + i*wspx] == 'b' ||
            plansza[aktualny->pozycja_y + i*wspy][aktualny->pozycja_x + i*wspx] == 'd' )
            ile_figur += 999;
    }
    return ile_figur;
}