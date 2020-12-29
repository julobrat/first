#include "headers.h"

void namaluj_plansze(char plansza[rozmiar_planszy][rozmiar_planszy], int gracz_x, int gracz_y, bool czy_wybrany, pionek *aktualny)
{
    char tlo_biale[] = ";47";   // biale i czarne pola
    char tlo_czarne[] = ";40";
    char tlo_niewcisniete[] = ";45";
    char tlo_wcisniete[] = ";101";
    char *tlo_wsk = NULL;
    for(int y = 0; y < rozmiar_planszy; printf("\n"), ++y)
    {
        for(int x = 0; x < rozmiar_planszy; ++x)
        {
            if( (x + y) % 2 ) tlo_wsk = tlo_biale;
            else tlo_wsk = tlo_czarne;
            if( x == gracz_x && y == gracz_y )
            {
                if(czy_wybrany) tlo_wsk = tlo_wcisniete;
                else tlo_wsk = tlo_niewcisniete;
            }
            if(x == aktualny->pozycja_x && y == aktualny->pozycja_y && aktualny->typ != 0)
                tlo_wsk = tlo_wcisniete;
            if(plansza[y][x] == 'a')
            {
                printf("\033[31%sm %s \033[0m", tlo_wsk, "\xE2\x99\x99"); // \xE2\x9B\x81
            }
            else if(plansza[y][x] == 'b')
            {
                printf("\033[37%sm %s \033[0m", tlo_wsk, "\xE2\x99\x99");
            }
            else if(plansza[y][x] == 'c')
            {
                printf("\033[31%sm %s \033[0m", tlo_wsk, "\xE2\x99\x95");
            }
            else if(plansza[y][x] == 'd')
            {
                printf("\033[37%sm %s \033[0m", tlo_wsk, "\xE2\x99\x95");
            }
            else if(plansza[y][x] == 'o')
            {
                printf("\033[0%sm   \033[0m", tlo_wsk);
            }

        }
    }
}

void ruch_gracza(char znak, int *wsk_gracz_x, int *wsk_gracz_y, char plansza[rozmiar_planszy][rozmiar_planszy], bool *czy_wybrany, pionek *aktualny)
{
    if(znak == 'w' && (*wsk_gracz_y-1) >= 0 ) --(*wsk_gracz_y);
    if(znak == 's' && (*wsk_gracz_y+1) <= rozmiar_planszy-1) ++(*wsk_gracz_y);
    if(znak == 'a' && (*wsk_gracz_x-1) >= 0) --(*wsk_gracz_x);
    if(znak == 'd' && (*wsk_gracz_x+1) <= rozmiar_planszy-1) ++(*wsk_gracz_x);
    if(znak == 'k')
    {
        // anulowanie wybrania pionka
        if(*czy_wybrany == true && *wsk_gracz_x == aktualny->pozycja_x && *wsk_gracz_y == aktualny->pozycja_y)
        {
            *czy_wybrany = false;
            wpisz_do_pionka(aktualny, '\0', 0, 0, 0);  // wyzeruj aktualnego pionka
        }
        // wybranie pionka
        else if(*czy_wybrany == false && (plansza[*wsk_gracz_y][*wsk_gracz_x] == 'b' || plansza[*wsk_gracz_y][*wsk_gracz_x] == 'd'))
        {
            if(plansza[*wsk_gracz_y][*wsk_gracz_x] == 'b')
                wpisz_do_pionka(aktualny, 'b', 1, *wsk_gracz_x, *wsk_gracz_y);
            if(plansza[*wsk_gracz_y][*wsk_gracz_x] == 'd')
                wpisz_do_pionka(aktualny, 'd', 2, *wsk_gracz_x, *wsk_gracz_y);
            *czy_wybrany = true;
        }
        // wykonanie ruchu
        else if(*czy_wybrany == true)
            wykonaj_ruch(*wsk_gracz_x, *wsk_gracz_y, aktualny, czy_wybrany);

    }
    if(znak == 'q') // TESTY
    {
        for(int i = 0; i < rozmiar_planszy; ++i, printf("\n"))
            for (int j = 0; j < rozmiar_planszy; ++j)
            {
                printf("%c ", plansza[i][j]);
            }
        
    }
}

void wykonaj_ruch(int poz_gracza_x, int poz_gracza_y, pionek *aktualny, bool *czy_wybrany)
{
    if(aktualny->typ == 1)   // jest to zwykly pionek
    {
        // jesli idziemy po ukosie w lewo lub prawo i nic tam nie ma
        if( ( (poz_gracza_x - aktualny->pozycja_x == -1 && poz_gracza_y - aktualny->pozycja_y == -1) ||
              (poz_gracza_x - aktualny->pozycja_x == 1 && poz_gracza_y - aktualny->pozycja_y == -1) ) &&
               plansza[poz_gracza_y][poz_gracza_x] == 'o' )
            ruch_pionka(poz_gracza_x, poz_gracza_y, aktualny, czy_wybrany, plansza, 'b');
        
        // bijemy po ukosie w prawo lub w lewo 
        else if( (poz_gracza_x - aktualny->pozycja_x == -2 && poz_gracza_y - aktualny->pozycja_y == -2)&&(plansza[aktualny->pozycja_y - 1][aktualny->pozycja_x - 1] == 'a' || plansza[aktualny->pozycja_y - 1][aktualny->pozycja_x - 1] == 'c') ||
                 (poz_gracza_x - aktualny->pozycja_x == 2 && poz_gracza_y - aktualny->pozycja_y == -2)&&(plansza[aktualny->pozycja_y - 1][aktualny->pozycja_x + 1] == 'a' || plansza[aktualny->pozycja_y - 1][aktualny->pozycja_x + 1] == 'c')  ||
                 (poz_gracza_x - aktualny->pozycja_x == -2 && poz_gracza_y - aktualny->pozycja_y == 2)&&(plansza[aktualny->pozycja_y + 1][aktualny->pozycja_x - 1] == 'a' || plansza[aktualny->pozycja_y + 1][aktualny->pozycja_x - 1] == 'c') ||
                 (poz_gracza_x - aktualny->pozycja_x == 2 && poz_gracza_y - aktualny->pozycja_y == 2)&&(plansza[aktualny->pozycja_y + 1][aktualny->pozycja_x + 1] == 'a' || plansza[aktualny->pozycja_y + 1][aktualny->pozycja_x + 1] == 'c')  )
            bicie_pionka(poz_gracza_x, poz_gracza_y, aktualny, czy_wybrany);
    }
    else if(aktualny->typ == 2) // jest to damka
    {
        // idziemy po ukosie w lewo lub prawo i nic tam nie ma
        if( damka_ile_figur_pomiedzy(poz_gracza_x, poz_gracza_y, aktualny) == 0 && plansza[poz_gracza_y][poz_gracza_x] == 'o' )
            ruch_damki(poz_gracza_x, poz_gracza_y, aktualny, czy_wybrany);
        // bicie po ukosie w lewo lub prawo
        if(plansza[poz_gracza_y][poz_gracza_x] == 'o')
            bicie_damki(poz_gracza_x, poz_gracza_y, aktualny, czy_wybrany);
    }

}
/*
void ruch_komputera()
{
    for(int y = 0; y < rozmiar_planszy; ++y)
    {
        for(int x = 0; x < rozmiar_planszy; ++x)
        {
            int typ = 0;
            if(plansza[y][x] == 'a') typ = 1;
            if(plansza[y][x] == 'c') typ = 2;
            if(typ == 1 || typ == 2)
            {
            pionek obecny = {'\0', 0, 0, 0};
            wpisz_do_pionka(&obecny, plansza[y][x], typ, x, y);
            char kopia_aktualnej[rozmiar_planszy][rozmiar_planszy];
            przepisz_do_tablicy(kopia_aktualnej, plansza);
            int licznik_punktow = 0;
            sprawdz_wartosc_ruchu(&obecny, kopia_aktualnej);
            }
        }
        
    }
}
// to ma byc funkcja rekurencyjna
int sprawdz_wartosc_ruchu(pionek *aktualny, char kopia[rozmiar_planszy][rozmiar_planszy])
{
    // jakis smiec zeby funkcja dzialala, za czy_wybrany
    bool placeholder;
    // poruszamy "wskaznikiem gracza"
    //na wszystkie odpowiednie dla pionka pozycje czyli o 1 w kazda strone
    if(aktualny->typ == 1)
    {
        // tu sprawdzamy ruch
        for(int poz_gracza_y = -1; poz_gracza_y <= 1; ++poz_gracza_y )
        {
            for(int poz_gracza_x = -1; poz_gracza_x <= 1; ++poz_gracza_x)
            {
                if( ( (poz_gracza_x - aktualny->pozycja_x == -1 && poz_gracza_y - aktualny->pozycja_y == 1) ||
                (poz_gracza_x - aktualny->pozycja_x == 1 && poz_gracza_y - aktualny->pozycja_y == 1) ) &&
                plansza[poz_gracza_y][poz_gracza_x] == 'o' )
                {
                    *licznik++;
                }
             }
        }
    }
    // poruszamy "wskaznikiem gracza"
    //na wszystkie odpowiednie dla damki pozycje czyli po calej planszy
    if(aktualny->typ == 2)
    {
        // kod sprawdzajacy dla damki
    }       
}
*/


// FUNKCJE POMOCNICZE

char pobierz_znak()
{
    char schowek = '\0';
    schowek = getch();
    if(schowek == ' ') return 'k';
    if(schowek == '\033')
    {
        schowek = getch();
        schowek = getch();
        if(schowek == 'A') return 'w';
        if(schowek == 'B') return 's';
        if(schowek == 'C') return 'd';
        if(schowek == 'D') return 'a';
    }
    else return schowek;
}

void wpisz_do_pionka(pionek *wsk, char kolor, int typ, int x, int y)
{
    wsk->kolor = kolor; wsk->typ = typ; wsk->pozycja_x = x; wsk->pozycja_y = y;
}

void przepisz_do_tablicy(char cel[rozmiar_planszy][rozmiar_planszy], char zrodlo[rozmiar_planszy][rozmiar_planszy])
{
    for(int i = 0; i < rozmiar_planszy; ++i)
    {
        for(int j = 0; j < rozmiar_planszy; ++j) cel[i][j] == zrodlo[i][j];
    }
}



int getch(void) // funkcja do pobierania 1 znaku z klawiatury bez wciskania entera
{
       struct termios oldattr, newattr;
       int ch;
       tcgetattr( STDIN_FILENO, &oldattr );
       newattr = oldattr;
       newattr.c_lflag &= ~( ICANON | ECHO );
       tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
       ch = getchar();
       tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
       return ch;
}