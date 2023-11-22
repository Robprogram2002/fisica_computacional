#include <stdio.h>
#include <math.h>

// global variables
double eps = 1.77;          // kj/mol
double sigma = 0.41;        // nanometros
double tolerancia = 1.0e-8; // orden de la tolerancia
double int_inicio = 0.2;    // inicio del intervalo (a)
double int_fin = 3.0;       // fin del intervalo (b)

double V(double r)
{
    // para atomos de Xenón
    return 4 * eps * (pow((sigma / r), 12) - pow((sigma / r), 6));
}

double VDerivada(double r)
{
    return 4 * eps * (6 * pow((sigma / r), 6) - 12 * pow((sigma / r), 12)) * (1 / r);
}

double VDerivada2(double r)
{
    return 4 * eps * ((1 / r * r) * (144 * pow((sigma / r), 12) - 36 * pow((sigma / r), 6)) - (1 / (r * r)) * (6 * pow((sigma / r), 6) - 12 * pow((sigma / r), 12)));
}

void imprimeDatos(int iteraciones, double resultado)
{
    printf("La raíz es %e en %d pasos \n", resultado, iteraciones);
}

double metodo_NR(double (*f)(double), double (*fDerivada)(double), double a, double b)
{
    int i = 0, maxIter = 500;
    double x0 = 0.0, x1;
    printf("Dame el valor incial de x \n");
    scanf("%lf", &x0);
    while (fabs(f(x0)) > tolerancia && i < maxIter)
    {
        printf("Estamos en la iteración %2d, el valor de x0 es:%10.5lf, el valor de la función: %10.51f,"
               "el valor de la derivada: %10.5lf \n",
               i, x0, f(x0), fDerivada(x0));

        // update the counter
        i++;
        // First, try N-R
        x1 = x0 - (f(x0) / fDerivada(x0));
        // check if the suggested point fall within the initial interval where we know the root is
        if (x1 < a || x1 > b)
        {
            // Newton-Rapson is not working change to bisection method
            x1 = (a + b) / 2;
        }
        // update the interval
        if (f(a) * f(x1) < 0)
        {
            b = x1;
        }
        else
        {
            a = x1;
        }

        x0 = x1;
    }
    imprimeDatos(i, x0);
}

double metodo_pegasus(double (*f)(double), double a, double b)
{

    double fa, fb, x, fx;
    int counter, maxIterac;

    maxIterac = 500;

    fa = f(a);
    fb = f(b);
    counter = 0;

    do
    {
        x = (fb * a - fa * b) / (fb - fa);
        fx = f(x);
        if (fb * fx < 0)
        {
            a = b;
            fa = fb;
        }
        else
        {
            fa = fa * fb / (fx + fb);
        }
        b = x;
        fb = fx;
        counter++;
        printf("%d %lf  \n", counter, x);
    } while ((fabs(f(x)) > tolerancia && counter < maxIterac));

    imprimeDatos(counter, x);
}

int main()
{
    // a) encontrar el valor de r para el cual V(r) =0
    metodo_NR(V, VDerivada, int_inicio, int_fin);
    metodo_pegasus(V, int_inicio, int_fin);

    printf("\n\n\n");

    // b) encontrar el valor de r para el cual V'(r) = 0
    metodo_NR(VDerivada, VDerivada2, int_inicio, int_fin);
    metodo_pegasus(VDerivada, int_inicio, int_fin);

    // Valor de V en el minimo
    printf("\nEl valor de V(r) para r tal que F(r) = 0 es %lf", V(0.4602094));
}
