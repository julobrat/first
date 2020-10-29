#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sortowanie(float *tablica, int rozmiar, float *wzor)
{
    for(int i = 0; i < rozmiar; ++i)
    {
        *(tablica + i) = *(wzor + i);
    }
    int ile = 0;
    while(ile < rozmiar)
    {
        for(int i = 0; i < (rozmiar) - 1; ++i)
        {

            if(*(tablica+i+1) < *(tablica+i))
            {
                float schowek = *(tablica+i);
                *(tablica+i) = *(tablica+i+1);
                *(tablica+i+1) = schowek;
            }
        }
        ++ile;
    }
}

void mediana(float *tablica, int rozmiar)
{
    if(rozmiar%2 == 0)
    {
        float mediana = (tablica[rozmiar/2] + tablica[rozmiar/2 - 1])/2;
        printf("Mediana to %f", mediana);
    }
    else
    {
        float mediana = tablica[(rozmiar-1)/2];
        printf("Mediana to %f", mediana);
    }
}

int main()
{
    float wzor[] = {12, 104, 45, 63};
    int rozmiar = sizeof(wzor)/sizeof(wzor[0]);
    float tablica [rozmiar];

    sortowanie(tablica, rozmiar, wzor);
    mediana(tablica, rozmiar);

    return 0;
}


