#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double t)
{
    return 0.45 + (8 / (10 * M_PI)) * (-2 * sin(20 * M_PI * t) - (2 / 3) * sin(60 * M_PI * t) - (2 / 5) * sin(100 * M_PI * t));
}

int main()
{
    for (double i = -1; i < 1; i += 0.001)
    {
        printf("%lf %lf\n", i, f(i));
    }
}