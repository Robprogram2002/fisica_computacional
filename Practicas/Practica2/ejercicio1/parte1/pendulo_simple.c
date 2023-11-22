#include <stdio.h>
#include <math.h>

// Definir la ecuación diferencial para el oscilador armónico
double q1(double y1, double y2, double t)
{
    return y2;
}

double q2(double y1, double y2, double t)
{
    return -(sin(y1));
}

// Implementación del método RK4
void rungeKutta(double t0, double y10, double y20, double h, int num_steps)
{
    double t = t0;
    double y1 = y10; // Inicializar y1 con la posición inicial
    double y2 = y20; // Inicializar y2 con la velocidad inicial
    double k11, k12, k21, k22, k31, k32, k41, k42;

    printf("Paso\tTiempo\tPosición\tVelocidad\n");
    printf("0\t%.2f\t%.6f\t%.6f\n", t, y1, y2);
    FILE *arch = fopen("pendulo2.txt", "w");
    for (int i = 1; i <= num_steps; i++)
    {
        // Paso 1
        k11 = h * q1(y1, y2, t);
        k12 = h * q2(y1, y2, t);

        // Paso 2
        k21 = h * q1(y1 + k11 / 2.0, y2 + k12 / 2.0, t + h / 2);
        k22 = h * q2(y1 + k11 / 2.0, y2 + k12 / 2.0, t + h / 2);

        // Paso 3
        k31 = h * q1(y1 + k21 / 2.0, y2 + k22 / 2.0, t + h / 2);
        k32 = h * q2(y1 + k21 / 2.0, y2 + k22 / 2.0, t + h / 2);

        // Paso 4
        k41 = h * q1(y1 + k31, y2 + k32, t + h);
        k42 = h * q2(y1 + k31, y2 + k32, t + h);

        // Actualizar y1 y y2 utilizando la suma ponderada de los pasos
        y1 = y1 + (k11 + 2.0 * k21 + 2.0 * k31 + k41) / 6.0;
        y2 = y2 + (k12 + 2.0 * k22 + 2.0 * k32 + k42) / 6.0;
        t = t + h;

        printf("%d\t%.2f\t%.6f\t%.6f\n", i, t, y1, y2);
        fprintf(arch, "%lf, %lf, %lf\n", t, y1, y2);
    }
}

int main()
{
    double t0 = 0.0;                           // Tiempo inicial
    double y10 = 0.2;                          // Posición inicial
    double y20 = 0.0;                          // Velocidad inicial
    double h = 0.1;                            // Tamaño del paso
    int num_steps = (int)(M_PI * 5.5 / h) + 1; // Número de pasos

    rungeKutta(t0, y10, y20, h, num_steps);

    return 0;
}
