
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

double f(double x) { return sin(M_PI * x) + 2.0 - 1.5 * x; } // conidición inicial
double g1(double t) { return 2.0; }                          // condición de frontera extremo izquierdo
double g2(double t) { return 0.5; }                          // condición de frontera extremo derecho

// resolver la ecuación de calor   u_dt = 1.44 u_dx^2
// con condiciones de frontera u(0,t) = 2.0, u(1,t) = 0.5
// con condiciones iniciales u(x, 0) = sen(\pi x) + 2.0 - 1.5 x (Notese que esta función satisface las condiciones de frontera)

int main()
{

  int n, m, i, j;
  double u0[nmax], u[nmax], a[nmax], e[nmax], c[nmax], b[nmax];
  double h = 0.01, k;
  double C = sqrt(1.44); // c² = 1.44
  double gamma = 2.0;
  double tfinal = 0.8;
  double alfa, beta;
  k = gamma * h * h / (C * C);
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
