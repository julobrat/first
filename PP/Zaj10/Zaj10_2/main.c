#include <stdio.h>
#include <stdlib.h>

//*******************************************
struct WiadomoscDoWyborcowX{
    char wiadom[100];
    float liczba;
} X = { "Przyblizanie jest dla lamusow, dowod musi byc przeprowadzony dokladnie.\n", 3.14159};

struct WiadomoscDoWyborcowY{
    char wiadom[100];
    float liczba;
} Y = { "Nie lam sie, to nie Twoja wina, ze nie da sie dokladnie okreslic polozenia czastki. Glupi Heisenberg...\n", 3.14};

struct WiadomoscDoWyborcowZ{
    char wiadom[100];
    float liczba;
} Z = { "Ten kod wyglada tragicznie, trzeba go przepisac, bo slabo sie robi...\n", 32};
//*******************************************

enum WiadomosciDoWyborcow {WIADOMOSC_DO_WYBORCOW_X, WIADOMOSC_DO_WYBORCOW_Y, WIADOMOSC_DO_WYBORCOW_Z};
int xxx, *hhh;
union wiadomosci{
    struct WiadomoscDoWyborcowX xx;
    struct WiadomoscDoWyborcowY yy;
    struct WiadomoscDoWyborcowZ zz;
} wiadomki = {&Z.wiadom, Z.liczba}; // wpisanie wiadomosci i liczby do unii

struct WiadomoscDoWyborcow{
    enum WiadomosciDoWyborcow typek;
    union wiadomosci *wiadomoscii;
} wiadomka = {WIADOMOSC_DO_WYBORCOW_Z, &wiadomki};// ustalenie do kogo ma byc wiadomosc w tym programie
//*******************************************
void przekazWiadomoscWyborcomX()
{
    printf("\n  WIADOMOSC DO WYBORCOW X!\n");
    if(wiadomka.typek == WIADOMOSC_DO_WYBORCOW_X)
    {
        printf("%s", wiadomka.wiadomoscii->tekst);
    }
    else
    {
        printf("wiedzcie, ze uzywanie %f jako 10*pi to herezja", (wiadomka.wiadomoscii)->liczbaa);
    }
}

void przekazWiadomoscWyborcomY()
{
    printf("\n  WIADOMOSC DO WYBORCOW Y!\n");
    if(wiadomka.typek == WIADOMOSC_DO_WYBORCOW_Y)
    {
        printf("%s", wiadomka.wiadomoscii->tekst);
    }
    else
    {
        printf("podstawiajcie %f pod 10*pi i  bedzie gitarka", (wiadomka.wiadomoscii)->liczbaa);
    }
}

void przekazWiadomoscWyborcomZ()
{
    printf("\n  WIADOMOSC DO WYBORCOW Z!\n");
    if(wiadomka.typek == WIADOMOSC_DO_WYBORCOW_Z)
    {
        printf("%s", wiadomka.wiadomoscii->tekst);
    }
    else
    {
        printf("10*pi zaokraglone to %f", (wiadomka.wiadomoscii)->liczbaa);
    }
}

//*******************************************
int main()
{
    przekazWiadomoscWyborcomX();
    przekazWiadomoscWyborcomY();
    przekazWiadomoscWyborcomZ();

    printf("\n\nNasze liczby to %f i %f i %f", X.liczba, wiadomka.wiadomoscii->liczbaa, Z.liczba);
    return 0;
}
/*- Zdefiniowa� struktury zawieraj�ce wiadomo�� dla odbiorc�w (tablica char o pewnej d�ugo�ci, oraz co� jeszcze np. liczba) WiadomoscDoWyborcowX, ...Y, ...Z
    - Prosz� o zdefiniowanie enum WiadomosciDoWyborcow o nast�puj�cych wpisach: WIADOMOSC_DO_WYBORCOW_X, WIADOMOSC_DO_WYBORCOW_Y, WIADOMOSC_DO_WYBORCOW_Z
    - nast�pnie prosz� utworzy� struktur� WiadomoscDoWyborcow, kt�ra b�dzie mia�a pole enum z typem wiadomo�ci i uni� zawieraj�c� wszystkie dost�pne wiadomo�ci

    - prosz� utworzy� r�wnie� analogiczne funkcje: przekazWiadomoscWyborcomX, ...Y, ...Z, kt�re to funkcje wy�wietl� wiadomo�� dla wyborc�w,
    ale tylko je�li jest ona od popierwnej partii, je�li nie jest funkcja powinna zignorowa� tre�� i wy�wietli� stereotypowy tekst na
    temat nadawcy np. "kosmopolici", "volksdeutsche", itp. - oczywi�cie wyb�r tekstu zale�y od wybranych partii*/
