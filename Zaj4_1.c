#include <stdio.h>
#include <stdlib.h>


int main()
{
    char alfabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','w','x','y','z'};
    char tekst[] = "To";
    int licznik = 0;
    for(int i = 0; i < sizeof(tekst); ++i){
        for(int j = 0; j < sizeof(alfabet); ++j){
            if(tekst[i] == alfabet[j]) ++licznik;
        }
    }
    printf("Mamy %i malych liter w tekscie %s", licznik, tekst);
    return 0;
}
