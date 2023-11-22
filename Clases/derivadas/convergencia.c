/*
 Integrantes:
 Córdoba Mendoza Rodrigo
 García Luna Bobadilla Uriel
 García Rosete Eduardo
 Manjarrez Chávez Raymundo
 Martínez Rivera Roberto

*/

#include <stdio.h>
#include <math.h>

double fDerivada(double x)
{
  return -sin(x) - 1;
}

double f(double x)
{
  return cos(x) - x;
}

void imprimeDatos(int iteraciones, double resultado)
{
  printf("La raíz es %e en %d pasos \n", resultado, iteraciones);
}

void newtonRaphson(double *x0, double *x1)
{
  *x1 = *x0 - (f(*x0) / fDerivada(*x0));
  *x0 = *x1;
}

double biseccion(double *a, double *b)
{
  double aux;
  aux = (*a + *b) / 2;
  if (f(*a) * f(aux) < 0)
  {
    *b = aux;
  }
  else
  {
    *a = aux;
  }
  return aux;
}

int main()
{
  double tolerancia = 1e-8;
  double a = 0.0;
  double b = 24.0;
  int i = 0;
  double x0, x1;
  x0 = 0;
  printf("Dame el valor incial de x \n");
  scanf("%lf", &x0);
  while (fabs(f(x0)) > tolerancia)
  {
    printf("Estamos en la iteración %2d, el valor de x0 es:%10.5lf, el valor de la función: %10.51f, el valor de la derivada: %10.5lf \n", i, x0, f(x0), fDerivada(x0));
    i++;
    newtonRaphson(&x0, &x1);
    if (x0 < a || x0 > b)
    {
      printf("Se ejecutó bisección\n");
      x0 = biseccion(&a, &b);
    }
  }
  imprimeDatos(i, x0);
}
