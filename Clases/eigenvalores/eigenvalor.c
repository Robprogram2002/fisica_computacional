#include <stdio.h>
#include <math.h>
#define nmax 1000

void productoMV(double vector [], double matriz [][nmax], double vectorAux[], int dimension)
{
  for(int i = 0 ; i < dimension ; i++)
  {
    vectorAux[i] = 0.0;
    for (int j = 0 ; j < dimension ; j++ )
    {
      vectorAux[i] += matriz[i][j] * vector[j];
    }
  }
}

double norma(double vector[], int dimension)
{
  double suma = 0.0;
  int i;
  double norma;
  for(i = 0; i < dimension; i++)
  {
    suma += vector[i] * vector[i];
  }
  norma =  sqrt(suma);
  for (i = 0; i < dimension; i++)
  {
    vector[i] = vector[i]/norma;
  }
  return norma;
}

int main()
{
  int dimension = 2;
  double matriz [nmax][nmax]  = {{2.0,1.0},{1.0,0.0}};
  double vector [nmax] = {1.0,1.0};
  double vectorAux [nmax];
  double q0 = 0.0;
  double q1 = 0.0;
  double tol = 1e-6;
  int iter = 0;
  do
  {
    q0 = q1;
    productoMV(vector,matriz,vectorAux,dimension);
    q1 = norma(vectorAux, dimension);
    for(int i = 0 ; i < dimension ; i++)
    {
      vector[i] = vectorAux[i];
    }
    iter++;
  }
  while (fabs(q1-q0)>tol);
  printf("El # de iteraciones fueron : %d \n",iter);
  printf("El eigen vector dominante es : \n");
  for (int i = 0; i < dimension ; i++)
  {
    printf("x(%d): %0.6lf \n",i, vector[i]);
  }
  printf("Y el eigen valor es: %lf \n",q1);
}
