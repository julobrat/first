#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *nieposortowany = fopen("nieposortowany.bin", "ab+");
    fputc('6', nieposortowany);
    fputc('5', nieposortowany);
    fputc('0', nieposortowany);
    fputc('2', nieposortowany);
    fputc('8', nieposortowany);
    fputc('3', nieposortowany);
    fputc('1', nieposortowany);
    fputc('9', nieposortowany);
    fputc('4', nieposortowany);
    fputc('7', nieposortowany);

    fclose(nieposortowany);
    nieposortowany = fopen("nieposortowany.bin", "rb+");
    int dlugosc = 0;
    fseek(nieposortowany, 0, 0);
    while(fgetc(nieposortowany) != EOF) ++dlugosc;

    for(int i = 0; i < dlugosc; ++i)
    {
        fseek(nieposortowany, 0, 0);
        for(int j = 0; j < dlugosc - 1; ++j)
        {
            char pierwszy = (char)fgetc(nieposortowany);
            char drugi = (char)fgetc(nieposortowany);
            if(pierwszy > drugi)
            {
                fseek(nieposortowany, -2, 1);
                fputc(drugi, nieposortowany);
                fputc(pierwszy, nieposortowany);
                fseek(nieposortowany, -1, 1);
            } else
            {
                fseek(nieposortowany, -1, 1);
            }
        }
    }

    fseek(nieposortowany, 0, 0);
    printf("\nNasz wynik to:\n");

    for(int i = 0; i < dlugosc; ++i);
    {
        char tablica[100] = {'0'};
        fgets(tablica, 100, nieposortowany);
        printf("%s", tablica);
    }
    fclose(nieposortowany);
}
