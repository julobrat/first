#include "headers.h"
#include "functions.c"
#include "functions_movement.c"


int main()
{
    bool gra = true;
    char ruch_char = '\0';
    
    int gracz_x = 4;
    int gracz_y = 6;
    bool czy_wybrany = false;
    
    while(gra)
    {
        static pionek aktualny = {'\0', 0, 0, 0};
        // poczatek ruchu gracza
        namaluj_plansze(plansza, gracz_x, gracz_y, czy_wybrany, &aktualny);
        ruch_char = pobierz_znak();
        printf("\x1b[H\x1b[J"); // wyczysc ekran
        ruch_gracza(ruch_char, &gracz_x, &gracz_y, plansza, &czy_wybrany, &aktualny);
        // koniec ruchu gracza
        // poczatek ruchu komputera
        //ruch_komputera();
    }
    return 0;
}