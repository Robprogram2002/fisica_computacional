
// Solucion a la ecuacion de calor u_t=u_xx
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nmax 500

void LU(int n, double a[], double e[], double c[], double b[], double x[])
{
    double u[nmax], w[nmax], y[nmax];
    int i;
    w[0] = a[0];
    for (i = 0; i <= n - 2; i++)
    {
        u[i] = e[i] / w[i];
        w[i + 1] = a[i + 1] - c[i + 1] * u[i];
    }
    y[0] = b[0] / w[0];
    for (i = 1; i <= n - 1; i++)
    {
        y[i] = (b[i] - c[i] * y[i - 1]) / w[i];
    }
    x[n - 1] = y[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        x[i] = y[i] - u[i] * x[i + 1];
    }
}

double f(double x) { return 1.0; } // CONDICION INICIAL

double g1(double t) { return 0.45 + (8 / (10 * M_PI)) * (-2 * sin(20 * M_PI * t) - (2 / 3) * sin(60 * M_PI * t) - (2 / 5) * sin(100 * M_PI * t)); } // CONDICIONES DE FRONTERA EN EL EXTREMO IZQUIERDO
double g2(double t) { return 0.45 + (8 / (10 * M_PI)) * (-2 * sin(20 * M_PI * t) - (2 / 3) * sin(60 * M_PI * t) - (2 / 5) * sin(100 * M_PI * t)); } // CONDICIONES DE FRONTERA EN EL EXTREMO DERECHO

// double g1(double t) { return (0.9 / 2.0 + (1.8 / M_PI) * (cos(20 * M_PI * t) - cos(60 * M_PI * t) / 3 + cos(100 * M_PI * t) / 5)); } // CONDICIONES DE FRONTERA EN EL EXTREMO IZQUIERDO
// double g2(double t) { return (0.9 / 2.0 + (1.8 / M_PI) * (cos(20 * M_PI * t) - cos(60 * M_PI * t) / 3 + cos(100 * M_PI * t) / 5)); } // CONDICIONES DE FRONTERA EN EL EXTREMO DERECHO

int main()
{

    int n, m, i, j;
    double u0[nmax], u[nmax], a[nmax], e[nmax], c[nmax], b[nmax];
    double h = 0.05, k;
    double C = 1.0;
    double gamma = 0.1;
    double tfinal = 1.0;
    double alfa, beta;
    k = gamma * h * h / C;
    n = 1.0 / h;
    m = tfinal / k;
    j = 0;

    // Condicion inicial
    alfa = g1(0);
    beta = g2(0);
    printf("%lf %lf %lf\n", 0.0, 0.0, alfa);
    for (i = 0; i < n - 1; i++)
    {
        u0[i] = f((i + 1) * h);
        printf("%lf %lf %lf\n", (i + 1) * h, 0.0, u0[i]);
    }
    printf("%lf %lf %lf\n", 1.0, 0.0, beta);
    printf("\n");
    for (i = 0; i < n - 1; i++)
    {
        a[i] = (2 + 2 * gamma);
        e[i] = -gamma;
        c[i] = -gamma;
    }
    for (j = 1; j <= m; j++)
    {
        // Condiciones de frontera

        b[0] = (2 - 2 * gamma) * u0[0] + gamma * (u0[1] + alfa) + gamma * g1(k * j);
        b[n - 2] = (2 - 2 * gamma) * u0[n - 2] + gamma * (u0[n - 3] + beta) + gamma * g2(k * j);
        for (i = 1; i < n - 2; i++)
        {
            b[i] = (2 - 2 * gamma) * u0[i] + gamma * (u0[i + 1] + u0[i - 1]);
        }
        LU(n - 1, a, e, c, b, u);
        alfa = g1(k * j);
        beta = g2(k * j);
        if (j % 1 == 0)
        {
            printf("%lf %lf %lf\n", 0.0, j * k, alfa);

            for (i = 0; i < n - 1; i++)
            {
                printf("%lf %lf %lf\n", (i + 1) * h, j * k, u[i]);
            }
            printf("%lf %lf %lf\n", 1.0, j * k, beta);
            printf("\n");
        }
        for (i = 0; i <= n; i++)
        {
            u0[i] = u[i];
        }
    }
    return 0;
}
