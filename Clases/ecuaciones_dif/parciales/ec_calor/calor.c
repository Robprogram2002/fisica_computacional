
//Solucion a la ecuacion de calor u_t=u_xx
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nmax 500


double f(double x) {return sin(M_PI*x);}


int main() {

    int n,m,i,j;
    double u0[nmax], u[nmax];
    double h = 0.01, k ;
    double gamma = 0.2;
    double tfinal = 0.3;
    k = gamma*h*h;
    n = 1.0/h;
    m = tfinal/k;
//Condicion inicial

    for (i = 0 ; i <= n ; i++){
      u0[i]= f(i*h);
    }

  for (j = 0 ; j <= m ; j++){
  //Condiciones de frontera
    u[0]= 0;
    u[n]= 0;

    for (i = 1 ; i < n ; i++){
      u[i]= (1-2*gamma)*u0[i] + gamma*(u0[i-1]+u[i+1]);
    }
if(j%100==0){
    for (i=0; i<=n; i++) {
        printf("%lf %lf %lf\n",i*h,j*k, u[i]);
    }
  }
    for (i = 0 ; i <= n ; i++){
      u0[i]= u[i];
    }

  }
    return 0;
}
