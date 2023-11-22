/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return -x;
    pow(x, 11);
}

double a(double x, double m)
{
    return f(x) / m;
}

int main()
{
    double h, p, m, x0, v0;
    int n, i;

    printf("Ingresa el valor del salto h: \n");
    scanf("%lf", &h);
    printf("Ingresa el valor de la masa: \n");
    scanf("%lf", &m);
    printf("Ingresa el valor inicial de la posición: \n");
    scanf("%lf", &x0);
    printf("Ingresa el valor inicial de la velocidad: \n");
    scanf("%lf", &v0);

    //    printf("Ingresa el valor del periodo: \n");
    //    scanf("%lf", &h);

    p = 3.142857;
    n = round(2 * p / h);

    double x[n];
    double v[n];

    x[0] = x0;
    v[0] = v0;

    for (i = 1; i < n; i++)
    {
        x[i] = x[i - 1] + h * v[i - 1] + h * h * a(x[i - 1], m) / 2;
        v[i] = v[i - 1] + h * (a(x[i - 1], m) + a(x[i], m)) / 2;
    }

    printf("No. de Iteracion \t Valor de x \t Valor de v \t Valor de a \n\n");

    for (i = 0; i < n; i++)
    {
        printf("\t %d \t\t %lf \t %lf \t %lf \n", i, x[i], v[i], a(x[i], m));
    }

    return 0;
}
