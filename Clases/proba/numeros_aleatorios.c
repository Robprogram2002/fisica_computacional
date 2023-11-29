#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int sums[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i <= 10000; i++)
    {
        int random = (rand() % 6) + 1;
        sums[random - 1] += 1;
        printf("Lanzamiento %d : \t resultado : %d \n", i, random);
    }

    for (int i = 0; i < 6; i++)
    {
        printf("El número de veces que salio el valor %d fue: %d. Su probabilidad es %lf \n", i + 1, sums[i], sums[i] / 10000.00);
    }

    return 1;
}