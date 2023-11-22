#include <stdio.h>
#include <math.h>
#define nmax 1000

void LU(int n, double a[], double e[], double c[], double b[], double x[]) {
    double u[nmax], w[nmax], y[nmax];
    int i;
    w[0] = a[0];
    for (i=0; i<=n-2; i++) {

        u[i]=e[i]/w[i];
        w[i+1]=a[i+1]-c[i+1]*u[i];
    }
    y[0]=b[0]/w[0];
    for (i=1; i<=n-1; i++) {
        y[i] = (b[i]-c[i]*y[i-1])/w[i];
    }
    x[n-1]=y[n-1];
    for (i=n-2; i>=0; i--) {
        x[i]=y[i]-u[i]*x[i + 1];
    }
}

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
{//Solucion de la cuerda sujeta a sus extremos (0,1)

  double h = 0.01;
  int dimension = 1.0/h-1;
//  double matriz [nmax][nmax]  = {{2.0,1.0},{1.0,0.0}};
  double vector [nmax];
  double a[nmax],e[nmax],c[nmax];
  double vectorAux [nmax];
  int i;
  double omegat = 6.1, lt;//eigenvalor aproximado
  lt = omegat*omegat;
for(i = 0; i< dimension; i++)
{
  vector[i]=1.0/sqrt((float)(dimension));
  a[i]= 2.0/(h*h)-lt;
  e[i]=-1.0/(h*h);
  c[i]=-1.0/(h*h);
}

  double q0 = 0.0;
  double q1 = 0.0;
  double tol = 1e-6;
  int iter = 0;
  do
  {
    q0 = q1;
    LU(dimension,a,e,c,vector,vectorAux);
    q1 = norma(vectorAux, dimension);
    for(i = 0 ; i < dimension ; i++)
    {
      vector[i] = vectorAux[i];
    }
    iter++;
  }
  while (fabs(1/q1-1/q0)>tol);
  
   for(i=0; i<dimension; i++){
    a[i]+=lt;
  }
  double x0[nmax];
  x0[0]=a[0]*vector[0]+e[0]*vector[1];
 for(i=1; i<dimension-1; i++){
  x0[i]=c[i]*vector[i-1]+a[i]*vector[i]+e[i]*vector[i+1];
}
x0[dimension-1]=c[dimension-1]*vector[dimension-2]+a[dimension-1]*vector[dimension-1];
  printf("El # de iteraciones fueron : %d \n",iter);
  
  double lf = 0.0;
  for(i=0; i<dimension; i++){
    lf+= vector[i]*x0[i];
  }
    printf("Y el eigen valor es: %lf \n",sqrt(lf));
  for (int i = 0; i < dimension ; i++)
  {
    printf("%lf %lf \n",(i+1)*h, vector[i]);
  }

}
