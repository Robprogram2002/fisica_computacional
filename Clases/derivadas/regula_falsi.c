
#include <stdio.h> 
#include <math.h>

// double f(double x) {
//    return (cos(x) - x);
//}

//double fDerivada(double x) {
//    return (-sin(x) - 1);
//}

double f (double x) {
    return (cos(x) - x);
}


int main()
{
    double a,b,tol, x1;
    int counter, maxIterac;
    
    printf("Dame el valor del principio del intervalo: \n");
    scanf("%lf", &a);
    
    printf("Dame el valor final del intervalo: \n");
    scanf("%lf", &b);
    
    printf("Dame el nivel de tolerancia: \n");
    scanf("%lf", &tol);
    
    maxIterac = 50;
    
    do {
        x1 = (f(b)*a - f(a)*b ) / (f(b) - f(a) );
        
        if(f(a)*f(x1) < 0) {
            b = x1;
        }else{
            a = x1;
        }
        counter++; 
    }while(fabs(f(x1)) > tol && counter < maxIterac  ); 
    
    
    double errorRel = ( fabs(f(x1)) / (fabs(x1) + tol ) )* 100.0 ;
    
    printf("El valor es %e en %d iteraciones con error relativo %e",x1,counter,errorRel);
}
