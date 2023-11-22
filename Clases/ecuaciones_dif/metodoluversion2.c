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

int main() {

    int n = 3;
    double a[nmax]={1,4,7}, e[nmax]={-2,-5,0}, c[nmax]={0,-3,-6}, b[nmax]={-26,110,-124}, x[nmax];

    LU(n,a,e,c,b,x);
    int i;
    for (i=0; i<n; i++) {
        printf("%lf\n", x[i]);
    }

    return 0;
}
