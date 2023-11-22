#include <stdio.h>
#include <math.h>

void imprimeVector(double *u, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%lf]", u[i]);
        }
        else
        {
            printf("%lf, ", u[i]);
        }
    }
}

void LU(double *a, double *e, double *c, double *b, double *x, int n)
{
    double w[n];
    double u[n];
    w[0] = a[0];
    u[0] = e[0] / w[0];
    for (int i = 1; i < n; i++)
    {
        w[i] = a[i] - c[i] * u[i - 1];
        u[i] = e[i] / w[i];
    }

    double y[n];

    y[0] = b[0] / w[0];
    for (int i = 0; i < n; i++)
    {
        y[i] = (b[i] - c[i] * y[i - 1]) / w[i];
    }

    x[n - 1] = y[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = y[i] - u[i] * x[i + 1];
    }
}

double f(double x)
{
    return 7 * x;
}

int main()
{
    int n = 20;
    double h = 1.0 / n;
    printf("El número de pasos es:%d \n", n);
    double a[n];
    double e[n];
    double c[n];
    double b[n];
    double x[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = (-2 + 5 * pow(h, 2)) / pow(h, 2);
        e[i] = (2 + 3 * h) / (2 * pow(h, 2));
        c[i] = (2 - 3 * h) / (2 * pow(h, 2));
        b[i] = f((i + 1) * h);
    }
    //  condiciones de frontera de Dirichlet
    double alpha = 20.0;
    double beta = 100.0;
    b[0] = b[0] - alpha / pow(h, 2);
    b[n - 1] = b[n - 1] - beta / pow(h, 2);
    LU(a, e, c, b, x, n);
    for (int i = 0; i < n; i++)
    {
        printf("%lf %lf \n", (i + 1) * h, x[i]);
    }
    printf("\n");
}