// Solucion a la ec. de Poisson por relajacion. Carga puntual
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nmax 201

int main()
{
  double sup, error, tol, phi0, h;
  int i, j, n, iter = 0, k;
  double p = 1.95; // parametro SOR
  tol = 1.0E-4;
  h = 0.005;
  n = 1.0 / h;
  double phi[nmax][nmax];
  double rho[nmax][nmax]; // densidad de carga
  // Condiciones de FRONTERA a tierra
  for (i = 0; i <= n; i++)
  {
    phi[0][i] = 0.0;
    phi[n][i] = 0.0;
    phi[i][0] = 0.0;
    phi[i][n] = 0.0;
  }
  // Distribucion de Carga

  for (i = 1; i < n; i++)
  {
    for (j = 1; j < n; j++)
    {
      rho[i][j] = 0.0;
    }
  }
  k = 100;
  rho[k - 20][k] = 1.0E6;
  rho[k + 20][k] = -1.0E6;

  // Initial guess

  for (i = 1; i < n; i++)
  {
    for (j = 1; j < n; j++)
    {
      phi[i][j] = 0.0;
    }
  }

  do
  {
    iter++;
    sup = 0.0;
    for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {
        phi0 = phi[i][j];
        phi[i][j] = (phi[i + 1][j] + phi[i - 1][j] + phi[i][j + 1] + phi[i][j - 1]) / 4 + rho[i][j] * (h * h) / 4;
        error = phi[i][j] - phi0;
        phi[i][j] = phi0 + p * error; // Formula SOR
        if (fabs(error) > sup)
        {
          sup = error;
        }
      }
    }
  } while (sup > tol);
  // printf("iter = %d \n",iter);
  for (i = 0; i <= n; i++)
  {
    for (j = 0; j <= n; j++)
    {
      printf(" %lf %lf %lf \n", i * h, j * h, phi[i][j]);
    }
    printf("\n");
  }
}
