#include <stdio.h>
#include <stdlib.h>

int main()
{
    char poczatkowy[] = "Jakis poczatkowy tekst.";

    int koniec = 0;
    for(int i = 0; i<sizeof(poczatkowy); ++i)
    {
        if(poczatkowy[i] == '\0') koniec = i-1;
    }

    char koncowy[koniec+1];
    for(int i = koniec, j = 0; i != -1; --i, ++j)
    {
        koncowy[j] = poczatkowy[i];
    }
    koncowy[koniec+1] = '\0';
    printf("%s", koncowy);

    return 0;
}
