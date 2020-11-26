#include <stdio.h>
#include <stdlib.h>

extern struct matrix;
float ** zaalokuj(int i, int j);
void wpisz_do_macierzy(struct matrix *obiekt);
void dealloc(struct matrix *obiekt);
struct matrix * dodawanie(struct matrix *obiekt1, struct matrix *obiekt2, struct matrix *third);
int sprawdzacz(struct matrix *obiekt1, struct matrix *obiekt2);
void wypisz(struct matrix *wynik);

typedef struct matrix
{
    int height;
    int width;
    float **mat;
} matrix;


int main()
{
    struct matrix first, second, third;
    wpisz_do_macierzy(&first);
    wpisz_do_macierzy(&second);

    if(!sprawdzacz(&first, &second)) printf("\nWszystko jest ok, wynik dodawania tych macierzy to:\n");
    else
    {
        printf("\nMacierze nie maja takich samych wymiarow, nie mozna ich dodac!");
        return 0;
    }
    wypisz(dodawanie(&first, &second, &third));
    dealloc(&first);
    dealloc(&second);
    dealloc(&third);
    return 0;
}

void wpisz_do_macierzy(struct matrix *obiekt)
{
    printf("\nPodaj wymiary macierzy: ");
    int wys, szer;
    scanf("%d %d", &wys, &szer);
    //printf("Wymiary macierzy to %d i %d", obiekt->height, obiekt->width);

    obiekt->mat = zaalokuj(wys, szer);
    obiekt->height = wys;
    obiekt->width = szer;

    printf("\nA teraz podaj zawartosc macierzy: \n");
    for(int a = 0; a < obiekt->height; ++a)
    {
        for(int b = 0; b < obiekt->width; ++b)
        {
            scanf("%f", &obiekt->mat[a][b]);
        }
    }
}

float ** zaalokuj(int i, int j)
{
    float ** tabliczka = malloc(i * sizeof(float*));

    for(int a = 0; a < i; ++a)
    {
        tabliczka[a] = malloc(j * sizeof(float));
    }
    return tabliczka;
}

void dealloc(struct matrix *obiekt)
{
    for(int a = 0; a < obiekt->height; ++a)
    {
        free(obiekt->mat[a]);
    }
    free(obiekt->mat);
}
struct matrix * dodawanie(struct matrix *obiekt1, struct matrix *obiekt2, struct matrix *third)
{
    third->mat = zaalokuj(obiekt1->height, obiekt1->width);
    third->height = obiekt1->height;
    third->width = obiekt1->width;
    for(int a = 0; a < obiekt1->height; ++a)
    {
        for(int b = 0; b < obiekt1->width; ++b)
        {
            third->mat[a][b] = obiekt1->mat[a][b] + obiekt2->mat[a][b];
        }
    }

    return third;
}

int sprawdzacz(struct matrix *obiekt1, struct matrix *obiekt2)
{
   if(obiekt1->height != obiekt2->height) return 1;
   if(obiekt1->width != obiekt2->width) return 1;
   return 0;
}

void wypisz(struct matrix *wynik)
{
    for(int a = 0; a < wynik->height; ++a)
    {
        printf("\n");
        for(int b = 0; b < wynik->width; ++b)
        {
            printf(" %f", wynik->mat[a][b]);
        }
    }
}
