#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tab[4][20];
    for(int i = 0; i < 4; ++i)
    {
        scanf("%s", &tab[i]);
    }

    for(int i = 0; i < 4; ++i)
    {
        printf("%s, ", tab[i]);
    }
    return 0;
}
