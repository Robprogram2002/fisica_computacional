#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nmax 500

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


double f(double x) {return -(M_PI)*(M_PI)*sin(M_PI*x);}




int main() {

    int n,i;
    double a[nmax], e[nmax], c[nmax], b[nmax], u[nmax];
    double h ;
    n = 100;
    h = 1.0/n;
    for (i = 0 ; i < n ; i++){
      a[i]=-2/(h*h);
      e[i]=1/(h*h);
      c[i]=1/(h*h);
      b[i]=f((i)*h);
    }
    a[0] = -1/(h*h);
    //  condiciones de frontera de Dirichlet
    double delta = M_PI; // u'(0) = delta
    double beta = 0; // u(1) = beta
    b[0]= delta/h + f(0)/2 ;
    b[n-1] = b[n-1]-beta/(h*h) ;
    LU(n,a,e,c,b,u);
    //printf("%lf %lf\n",0.0, delta);
    for (i=0; i<n; i++) {
        printf("%lf %lf\n",(i)*h, u[i]);
    }
    printf("%lf %lf\n",1.0, beta);
    return 0;
}
