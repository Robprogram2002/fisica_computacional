#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    for (int i = 0; i <= 10000; i++)
    {
        int x = (rand() % 6) + 1;
        int y = (rand() % 6) + 1;
        double r = sqrt(x * x + y * y);
        printf("Lanzamiento %d : \t resultado : %d \n", i, x);
    }

    for (int i = 0; i < 6; i++)
    {
        printf("El número de veces que salio el valor %d fue: %d. Su probabilidad es %lf \n", i + 1, sums[i], sums[i] / 10000.00);
    }

    return 1;
}