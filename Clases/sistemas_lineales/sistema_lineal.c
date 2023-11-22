
#include <stdio.h>
#include <math.h>

void LU_solver(int n, double a[], double e[], double c[], double b[], double x[])
{
    // valores a calcular
    double y[n];

    // valores de las matrices L y U
    double w[n], u[n];

    // Construimos los valores de la matriz L y U
    w[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        u[i - 1] = e[i - i] / w[i - 1];
        w[i] = a[i] - c[i] * u[i - 1];
    }

    // Obtenemos los valores intermedios y
    y[0] = b[0] / w[0];

    for (int j = 1; j < n; j++)
    {
        y[j] = (b[j] - c[j] * y[j - 1]) / w[j];
    }

    // obtenemos los valores de x (la solución)
    x[n - 1] = y[n - 1];

    for (int k = n - 2; k >= 0; k--)
    {
        x[k] = y[k] - u[k] * x[k + 1];
    }
}

int main()
{
    int n = 2;
    double a[2] = {2, 0};
    double e[2] = {1, 0};
    double c[2] = {0, 1};
    double b[2] = {1, 1};
    double x[2];

    LU_solver(n, a, e, c, b, x);

    for (int i = 0; i < n; i++)
    {
        printf("x%d = %lf \n", i + 1, x[i]);
    }
}
