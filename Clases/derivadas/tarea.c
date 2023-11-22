#include <stdio.h>
#include <math.h>

double f1(double x) {
    return x*x*x -1;
}

double f2(double x) {
    return 11*pow(x, 11) - 1;
}

double f3(double x) {
    return pow(x, 3) + 1;
}

double f4(double x) {
    return pow(x,3) - 2*x - 5;
}

double f5(double x) {
    return 2*x*exp(-5) + 1 - 2*exp(-5*x) ;
}

double f6(double x) {
    return 2*x*exp(-10) + 1 - 2*exp(-10*x) ;
}

double f7(double x) {
    return 2*x*exp(-20) + 1 - 2*exp(-20*x) ;
}

double f8(double x) {
    return x*x - pow(1-x, 5);
}

double f9(double x) {
    return x*x - pow(1-x, 10);
}

double f10(double x) {
    return x*x - pow(1-x, 20);
}

double phi_1(double fa, double fb, double fx) {
    return fa*fb/(fx + fb);
}

double phi_3(double fa, double fb, double fx) {
    return (fa - fx)/(2 + (fx/fb));
}

double phi_12(double fa, double fb, double fx) {
    double m;
    m = 1 - (fx/fb);
    
    if (m < 0){
        return 0.5;
    }
    return m*fa;
}

double intervals[10][2] = {{0.5,1.5}, {0.1,1.0}, {-1.8, 0.0}, {2.0,3.0}, {0.0,1.0}, {0.0,1.0}, {0.0,1.0}, {0.0,1.0}, {0.0,1.0}, {0.0,1.0}};  

double method(double (*phi)(double, double, double), double (*f)(double), double a, double b ) {
    
    double fa,fb,x0,x, fx, tol = 1.e-15;
    int counter, maxIterac;

    maxIterac = 500;

    fa = f(a);
    fb = f(b);
    counter = 0;
    
    do {
        x0 = x;
        x = (fb*a - fa*b ) / (fb - fa );
        fx = f(x);
        if(fb*fx < 0) {
             a = b;
             fa = fb;
        }else{
            fa = phi(fa,fb,fx);
        }
        b=x;
        fb=fx;
        counter++;
        printf("%d %lf %lf  \n", counter, x0, x);
    }while(counter < 2 || (fabs(x - x0) > tol && counter < maxIterac));


    double errorRel = ( fabs(x - x0) / (fabs(x - x0) + tol ) )* 100.0 ;

    printf("El valor es %e en %d iteraciones con error relativo %e \n",x,counter,errorRel);
}


int main()
{

    double (*functions[10])(double) = {f1, f2, f3, f4, f5, f6, f7, f8, f9, f10};
    
    double (*phis[3])(double, double, double) = {phi_1, phi_3, phi_12};
    
    int i, j;
    
    for (i=0; i<11; i++) {
        for (j =0; j <3; j++) {
            method(phis[j], functions[i], intervals[i][0], intervals[i][1]);
            printf(" ");
        }
    }

    return 0;
}