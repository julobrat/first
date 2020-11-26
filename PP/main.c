#include <stdio.h>
#include <stdlib.h>

int ** zaalokuj(int i, int j);

int main()
{
    printf("Podaj wymiary tablicy: ");
    scanf("%d %d", &i, &j);

    int ** wsk = zaalokuj(i,j);
    for(int a = 0; a < i; ++a)
    {
        for(int b = 0; b < j; ++b)
        {
            static int licznik = 0;
            wsk[a][b] = licznik;
            ++licznik;
            printf("\n%d", wsk[a][b]);

        }
    }
    free(wsk);

    return 0;
}

int ** zaalokuj(int i, int j)
{
    int **tablica = malloc(i * sizeof(int*));
    for(int a = 0; a < j; ++a)
    {
        tablica[a] = malloc(j * sizeof(int));
    }
    return tablica;
}
