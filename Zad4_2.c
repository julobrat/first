#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Podaj 2 liczby zespolone, ich skladowe takze oddziel spacja: ");
    float pierwsza_rz, pierwsza_ur, druga_rz, druga_ur, wynik_rz, wynik_ur;
    scanf("%f %f %f %f", &pierwsza_rz, &pierwsza_ur, &druga_rz, &druga_ur);

    wynik_rz = pierwsza_rz + druga_rz;
    wynik_ur = pierwsza_ur + druga_ur;
    printf("\nIch suma to (%f, %fi)", wynik_rz, wynik_ur);

    return 0;
}
