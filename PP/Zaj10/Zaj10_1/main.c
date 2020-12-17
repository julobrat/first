#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int cukierki;
    int dostalo;
} TorbaCukierkow;

int main()
{
    srand(time(0));
    TorbaCukierkow torba;
    torba.dostalo = 0;
    char tab[100];
    tab = "WIIITAAAAMM";
    printf("%s", tab);

    int ilu_uczniow = 10 + rand()%20;
    int wszystkich = ilu_uczniow;
    torba.cukierki = rand() % 40;
    if(torba.cukierki%10 != 0) //zaokraglamy
    {
        torba.cukierki = torba.cukierki - torba.cukierki%10 + 10;
    }
    printf("Mamy %d uczniow i %d cukierkow\n", ilu_uczniow, torba.cukierki);
    while(torba.cukierki > 0 && ilu_uczniow > 0)
    {
        printf("\nWszystkiego najlepszego");
        torba.cukierki -= 1;
        torba.dostalo += 1;
        //printf("\n####Mam jeszcze %d cukierkow", torba.cukierki);
        ilu_uczniow -=1;

        int zapytanie = rand()%5;
        if(zapytanie == 0)
        {
            printf("\nWszystkiego najlepszego, a moge dwa?");
            if(torba.cukierki > 0)
            {
                torba.cukierki -= 1;
                printf("\nA prosze bardzo");
                //printf("####Mam jeszcze %d cukierkow", torba.cukierki);
            }
            else
            {
                printf("\nPrzykro mi, nie mam ju� cukierkow");
                return 0;
            }
        }
    }
    if(ilu_uczniow == 0)
    {
        printf("\nWszyscy uczniowie dostali cukierki, tych uczniow bylo %d, zostalo mi jeszcze %d cukierkow", wszystkich, torba.cukierki);
    }
    else if(torba.cukierki == 0)
    {
        printf("\nZabraklo mi cukierkow, tylko %d uczniow je dostalo", torba.dostalo);
    }
    return 0;
}
/*Urodziny w klasie - solenizant przynosi cukierki do klasy,
prosz� wylosowa� ilo�� uczni�w) w okre�lonej ilo�ci (tyle ile ma klasa zaokr�glaj�c w g�r� do pe�nych dziesi�tek),
ka�dy ucze� bierze po cukierku, ale jest 20% szans, �e powie "Wszystkiego najlepszego, a mog� dwa" - wtedy g�upio mu odm�wi�.
Prosz� o wykonanie pocz�stunku z informacj�, ile os�b dosta�o cukierki, a ile nie. Prosz� aby utworzy� struktur� TorbaCukierk�w,
kt�ra b�dzie mia�a licznik, z kt�rego b�dzie si� odejmowa�.*/
