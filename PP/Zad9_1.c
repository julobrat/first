#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *odczyt = fopen("plik9_1_1.txt", "r");
    FILE *zapis = fopen("plik19_1_2.txt", "a");
    char znak = '1';
    while( (znak = fgetc(odczyt))!= EOF )
    {
      fputc(znak, zapis);
    }
    fclose(odczyt);
    fclose(zapis);
    return 0;
}
