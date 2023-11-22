#include <stdio.h>
#include <math.h>

int diceRandom()
{
    int random = rand() % 6 + 1;
    return random;
}

int main()
{
    for (int i = 0; i <= 10000; i++)
    {
        printf("Número %d : \t valor : %d \n", i, diceRandom());
    }

    return 1;
}