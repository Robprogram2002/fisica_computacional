/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Is a header file library that lets us work with input and output functions,
// such as printf() (used in line 4). Header files add functionality to C programs.

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return (cos(x) - x);
}
double fDerivada(double x)
{
    return (-sin(x) - 1);
}

// double f(double x)
//{
//     return x * x * x - 2 * x + 1;
// }

// double fDerivada(double x) {
//     return 3*x*x - 2;
// }

int main()
{
    double a, b, x0, tol, x1;
    int counter, maxIterac;

    printf("Dame el valor del principio del intervalo: \n");
    scanf("%lf", &a);
    printf("Dame el valor final del intervalo: \n");
    scanf("%lf", &b);
    printf("Dame un valor inicial: \n");
    scanf("%lf", &x0);
    printf("Dame el nivel de tolerancia: \n");
    scanf("%lf", &tol);

    maxIterac = 50;
    counter = 0;
    do
    {
        // First, try N-R
        x1 = x0 - (f(x0) / fDerivada(x0));

        // check if the suggest pint fall within the initial interval where we know the root is
        if (x1 < a || x1 > b)
        {
            // Newton-Rapson is not working change to bisection method
            x1 = (a + b) / 2;
        }

        // update the interval
        if (f(a) * f(x1) < 0)
        {
            b = x1;
        }
        else
        {
            a = x1;
        }

        x0 = x1;

        // in whatever case increase the counter
        counter++;

    } while (fabs(f(x1)) > tol && counter < maxIterac);

    double errorRel = (fabs(f(x1)) / (fabs(x1) + tol)) * 100.0;

    printf("El valor es %e en %d iteraciones con error relativo %e", x1, counter, errorRel);
}
