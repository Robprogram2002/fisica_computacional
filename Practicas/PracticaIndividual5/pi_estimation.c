#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int numeros = 1000;
    double puntosDentro = 0.0;
    for (int i = 0; i < numeros; i++)
    {

        double x = ((double)rand() / RAND_MAX) * 2 - 1;
        double y = ((double)rand() / RAND_MAX) * 2 - 1;
        double z = ((double)rand() / RAND_MAX) * 2 - 1;
        double r = sqrt(x * x + y * y + z * z);

        if (r <= 1)
        {
            puntosDentro += 1;
            printf("%lf %lf %lf \n", x, y, z);
        }
    }
    double resultado = 6 * (puntosDentro / numeros);
    // printf("Puntos dentro: %lf\n", puntosDentro);
    // printf("EL valor de pi es:%lf \n", resultado);

    return 0;
}
