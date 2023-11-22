#include <stdio.h>
#include <math.h>

int main () {
double a[3]={2,0},e[3]={1,0}, c[3]={0,1}, b[3]={1,1};
double x[3], y[3], u[3], w[3];
int i,n=2;

w[0]=a[0];
for(i=0; i<=n-2; i++){
u[i]=e[i]/w[i];
w[i+1]=a[i+1]-c[i+1]*u[i];
}

y[0]=b[0]/w[0];
for(i=1; i<=n-1; i++){
y[i]=(b[i]-c[i]*y[i-1])/w[i];
}

x[n-1]=y[n-1];
for(i=n-2; i>=0; i--){
x[i]=y[i]-u[i]*x[i+1];
}

for(i=0; i<=n-1; i++){
printf("%lf \n",x[i]);
}


}

