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
void rungeKutta(double t0, double y20, double h, int num_steps)
{
    double y1; // Inicializar y1 con la posición inicial

    FILE *arch = fopen("periodo_data2.txt", "w");
    for (int j = 1; j <= 115; j++)
    {
        double y10 = 0.05 * j;
        double y1 = y10;
        double t = t0;
        double y2 = y20; // Inicializar y2 con la velocidad inicial
        double k11, k12, k21, k22, k31, k32, k41, k42;

        for (int i = 1; i <= 10 * num_steps; i++)
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

            if (i > 10 && (y1 >= y10 - 1E-3 && y1 <= y10 + 1E-3))
            {
                fprintf(arch, "%lf, %lf, %lf\n", y1, t, y2);
                break;
            }
        }
    }
}

int main()
{
    double t0 = 0.0;                     // Tiempo inicial
    double y20 = 0.0;                    // Velocidad inicial
    double h = 0.1;                      // Tamaño del paso
    int num_steps = (int)(M_PI / h) + 1; // Número de pasos

    rungeKutta(t0, y20, h, num_steps);

    return 0;
}
