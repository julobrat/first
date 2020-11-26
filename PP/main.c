#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define KANDYDACI 3

typedef struct struktura_wynikow
{
    char nazwisko[50];
    long glosy;
    bool czy_demokrata;
} wyniki;

void wiarolomnySystemDemokratyczny(wyniki *tab[]);


wyniki pierwszy = {"kowalski", 1000, true};
wyniki drugi = {"nowak", 2000, true};
wyniki trzeci = {"malinowski", 3000, false};
wyniki *lista[KANDYDACI] = {&pierwszy, &drugi, &trzeci};

int main()
{
    const int a = 1;
    int *wsk;
    wsk = (int*)&a;
    (*wsk) = 5;

    //wiarolomnySystemDemokratyczny(lista);
    return 0;
}

void wiarolomnySystemDemokratyczny(wyniki *tab[])
{
    for(int i=0; i < KANDYDACI; ++i)
    {
        if(tab[i]->czy_demokrata == false)
        {
            printf("\nKandydat %s zdobyl %ld glosow", tab[i]->nazwisko, tab[i]->glosy/2);
        } else
        {
            printf("\nKandydat %s zdobyl %ld glosow", tab[i]->nazwisko, tab[i]->glosy);
        }
    }
}
