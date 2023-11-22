#include<stdio.h>
#include<math.h>
#define nmax 2000
#define V(x) ((x)*(x)/2.0)
void flu();
int main(){
 double a[nmax],e[nmax],c[nmax],x0[nmax],x1[nmax];
 double q0=1.0,q1=0.1,tol = 1E-12, ener=0.4, lambda, h=0.01,A = 6.2,Ep;
  int i,n,iter=0;
  lambda=2*ener;
  FILE *arch=fopen("pozo.txt","w");

n=(2*A/h)-1; //dimension del sistema
 //printf("%d",n);
  for(i=0; i<n; i++){
    a[i]=2.0/(h*h)+2*V(-A+(i+1)*h)-lambda;
    e[i]=-1.0/(h*h);
    c[i]=-1.0/(h*h);
  }
  for(i=0; i<n; i++){
    x0[i]=1.0/sqrt(n);
  }

  while (fabs(1/q1-1/q0)>tol){
    iter++;
    q0=q1;
  flu(a,c,e,x0,x1,n);
//normalizamos x1
    q1=0.0;
  for(i=0; i<n; i++){
    q1+=x1[i]*x1[i];
  }
    q1=sqrt(q1);
  for(i=0; i<n; i++){
  x1[i]=x1[i]/q1;
}
for(i=0; i<n; i++){
   x0[i]=x1[i];
}

}
 for(i=0; i<n; i++){
    a[i]+=lambda;
  }

 x0[0]=a[0]*x1[0]+e[0]*x1[1];
 for(i=1; i<n-1; i++){
  x0[i]=c[i]*x1[i-1]+a[i]*x1[i]+e[i]*x1[i+1];
}
x0[n-1]=c[n-1]*x1[n-2]+a[n-1]*x1[n-1];

   Ep = 0.0;
  for(i=0; i<n; i++){
    Ep+= x1[i]*x0[i];
  }

  printf("el eigenvalor cercano a lambda es: %lf, %d \n", Ep/2,iter);

  fprintf(arch,"%lf, %lf \n",-A, 0.0);

  for(i=0;i<n;i++){
     fprintf(arch,"%lf, %lf \n",-A+(i+1)*h,x1[i]);
   }
   fprintf(arch,"%lf, %lf \n",A, 0.0);
   fclose(arch);
}
void flu(double a[],double c[],double e[],double b[],double x[],int n){
  double y[nmax],u[nmax],w[nmax];
  int i;
  w[0]=a[0];
  for(i=0;i<n-1;i++){
    u[i]=e[i]/w[i];
    w[i+1]=a[i+1]-c[i+1]*u[i];
  }
  y[0]=b[0]/w[0];
  for(i=0;i<n-1;i++){
    y[i+1]=(b[i+1]-c[i+1]*y[i])/w[i+1];
  }
  x[n-1]=y[n-1];
  for(i=n-1;i>0;i--){
    x[i-1]=y[i-1]-u[i-1]*x[i];
 }

}
