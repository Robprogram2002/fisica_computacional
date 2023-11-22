#include <stdio.h>
#include <math.h>

// double f (double x) {
//    return (x*x*x - 1);
//}

double f(double x)
{
    return 11 * pow(x, 11) - 1;
}

int main()
{
    double a, b, fa, fb, tol, x0, x, fx;
    int counter, maxIterac;

    printf("Dame el valor del principio del intervalo: \n");
    scanf("%lf", &a);

    printf("Dame el valor final del intervalo: \n");
    scanf("%lf", &b);

    printf("Dame el nivel de tolerancia: \n");
    scanf("%lf", &tol);

    maxIterac = 500;
    fa = f(a);
    fb = f(b);
    counter = 0;
    do
    {
        x0 = x;
        x = (fb * a - fa * b) / (fb - fa);
        fx = f(x);
        if (fb * fx < 0)
        {
            a = b;
            fa = fb;
        }
        else
        {
            fa = fa / 2; // fa*fb/(fx + fb)
        }
        b = x;
        fb = fx;
        counter++;
        printf("%d %lf %lf  \n", counter, x0, x);
    } while (counter < 2 || (fabs(x - x0) > tol && counter < maxIterac));

    double errorRel = (fabs(x - x0) / (fabs(x - x0) + tol)) * 100.0;

    printf("El valor es %e en %d iteraciones con error relativo %e \n", x, counter, errorRel);
}