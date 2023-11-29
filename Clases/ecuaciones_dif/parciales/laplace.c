// Solucion a la ec. de Laplace por relajacion
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nmax 500

int main()
{
  double sup, error, tol, phi0, h;
  int i, j, n;
  tol = 1.0E-4;
  h = 0.01;
  n = 1 / h;
  double phi[nmax][nmax];
  // Condiciones de FRONTERA
  for (i = 0; i <= n; i++)
  {
    phi[0][i] = 0.0;
    phi[n][i] = 100.0;
    phi[i][0] = 100.0;
    phi[i][n] = 0.0;
  }

  // Initial guess

  for (i = 1; i < n; i++)
  {
    for (j = 1; j < n; j++)
    {
      phi[i][j] = 50.0;
    }
  }

  do
  {

    sup = 0.0;
    for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {
        phi0 = phi[i][j];
        phi[i][j] = (phi[i + 1][j] + phi[i - 1][j] + phi[i][j + 1] + phi[i][j - 1]) / 4;
        error = fabs(phi[i][j] - phi0);
        if (error > sup)
        {
          sup = error;
        }
      }
    }
  } while (sup > tol);

  for (i = 0; i <= n; i++)
  {
    for (j = 0; j <= n; j++)
    {
      printf(" %lf %lf %lf \n", i * h, j * h, phi[i][j]);
    }
    printf("\n");
  }
}
