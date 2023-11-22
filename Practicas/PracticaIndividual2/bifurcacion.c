#include <stdio.h>
#include <math.h>

double c1 = 0.1;
double c2 = 1.0;
double c3 = -1.0;
// double c4 = 0.38;
double c5 = 1.4;

// Definir la ecuación diferencial para el oscilador armónico
double q1(double y1, double y2, double t)
{
    return y2;
}

double q2(double y1, double y2, double t, double f0)
{

    return (-c1 * y2 + c2 * y1 + c3 * pow(y1, 3) + f0 * cos(c5 * t));
}

// Implementación del método RK4
void rungeKutta(double t0, double y10, double y20, int num_steps)
{
    double t = t0;
    int k;
    double y1; // Inicializar y1 con la posición inicial
    double y2; // Inicializar y2 con la velocidad inicial
    double k11, k12, k21, k22, k31, k32, k41, k42;
    double f0;
    double h = 2 * M_PI / (c5 * num_steps); // Tamaño del paso

    FILE *arch = fopen("bifurca2.txt", "w");

    for (f0 = 0.331; f0 <= 0.340; f0 += 0.000045)
    {

        y1 = y10;
        y2 = y20;

        for (int i = 1; i <= 1000 * num_steps; i++)
        {
            // Paso 1
            k11 = h * q1(y1, y2, t);
            k12 = h * q2(y1, y2, t, f0);

            // Paso 2
            k21 = h * q1(y1 + k11 / 2.0, y2 + k12 / 2.0, t + h / 2);
            k22 = h * q2(y1 + k11 / 2.0, y2 + k12 / 2.0, t + h / 2, f0);

            // Paso 3
            k31 = h * q1(y1 + k21 / 2.0, y2 + k22 / 2.0, t + h / 2);
            k32 = h * q2(y1 + k21 / 2.0, y2 + k22 / 2.0, t + h / 2, f0);

            // Paso 4
            k41 = h * q1(y1 + k31, y2 + k32, t + h);
            k42 = h * q2(y1 + k31, y2 + k32, t + h, f0);

            // Actualizar y1 y y2 utilizando la suma ponderada de los pasos
            y1 = y1 + (k11 + 2.0 * k21 + 2.0 * k31 + k41) / 6.0;
            y2 = y2 + (k12 + 2.0 * k22 + 2.0 * k32 + k42) / 6.0;
            t = t + h;

            // Mapeo que restringe a theta en el intervalo [-pi,pi]
            if (fabs(y1) > M_PI)
            {

                y1 = y1 - 2 * M_PI * (fabs(y1)) / y1;
            }

            //     printf("%d\t%.2f\t%.6f\t%.6f\n", i, t, y1, y2);

            if (i >= 500 * num_steps && i % num_steps == 0)
            {

                fprintf(arch, "%lf, %lf \n", f0, y2);
            }
        }
    }
}

int main()
{
    double t0 = 0.0;  // Tiempo inicial
    double y10 = 0.0; // Posición inicial
    double y20 = 0.0; // Velocidad inicial

    int num_steps = 1000; // Número de pasos por periodo de la fuerza externa

    rungeKutta(t0, y10, y20, num_steps);

    return 0;
}
