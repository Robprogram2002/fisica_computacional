#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define pasos 200
#define paso 0.05
#define particulas 49
#define L 8.0
#define m 1.0

double calc_r(double x1, double x2, double y1, double y2)
{
    double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (distance < 1)
    {
        return 1.0;
    }
    else
    {
        return distance;
    }
}

double LJ_derivada(double r)
{
    return 4 * (12 * (1 / pow(r, 13)) - 6 * (1 / pow(r, 7)));
}

double LJ_potencial(double r)
{
    return 4 * (pow(1 / r, 12) - pow(1 / r, 6));
}

int main()
{
    srand(time(NULL));

    double r[particulas][2];
    double r0[particulas][2];
    double v[particulas][2];
    double Ek = 0.0;
    double Ep = 0.0;
    double T = 0.0;
    double F = 0.0;
    double F0 = 0.0;

    for (int i = 0; i < particulas; i++)
    {
        r[i][0] = ((double)rand() / RAND_MAX) * 8 - 4;
        r[i][1] = ((double)rand() / RAND_MAX) * 8 - 4;
        r0[i][0] = r[i][0];
        r0[i][1] = r[i][1];
        v[i][0] = ((double)rand() / RAND_MAX) * 2 - 1;
        v[i][1] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    for (int i = 0; i < particulas; i++)
    {
        Ek += (0.5) * m * (v[i][0] * v[i][0] + v[i][1] * v[i][1]);
        printf("%lf  %lf  %lf  %lf  ", r[i][0], r[i][1], v[i][0], v[i][1]);
    }

    T = (2.0 / 3.0) * (Ek / (particulas));
    printf("%lf  %lf  %d\n", T, Ek, 1);

    for (int i = 1; i < pasos; i++)
    {
        Ep = 0.0;
        for (int j = 0; j < particulas; j++)
        {
            Ek = 0.0;
            F = 0.0;
            F0 = 0.0;

            for (int l = 0; l < particulas; l++)
            {
                if (j != l)
                {
                    F += LJ_derivada(calc_r(r[j][0], r[l][0], r[j][1], r[l][1]));
                    F0 += LJ_derivada(calc_r(r0[j][0], r0[l][0], r0[j][1], r0[l][1]));
                }
            }

            r[j][0] = r[j][0] + v[j][0] * paso + (0.5) * (F)*paso * paso;
            r[j][1] = r[j][1] + v[j][1] * paso + (0.5) * (F)*paso * paso;
            v[j][0] = v[j][0] + (0.5) * (F0 + F0) * paso;
            v[j][1] = v[j][1] + (0.5) * (F0 + F0) * paso;

            if (r[j][0] > L / 2.0)
            {
                r[j][0] = L - r[j][0];
                v[j][0] = -v[j][0];
            }
            else if (r[j][0] < -L / 2.0)
            {
                r[j][0] = -L - r[j][0];
                v[j][0] = -v[j][0];
            }

            if (r[j][1] > L / 2.0)
            {
                r[j][1] = L - r[j][1];
                v[j][1] = -v[j][1];
            }
            else if (r[j][1] < -L / 2.0)
            {
                r[j][1] = -L - r[j][1];
                v[j][1] = -v[j][1];
            }

            r0[j][0] = r[j][0];
            r0[j][1] = r[j][1];

            Ek += (0.5) * m * (v[j][0] * v[j][0] + v[j][1] * v[j][1]);

            for (int l = j + 1; l < particulas; l++)
            {
                Ep += LJ_potencial(calc_r(r[j][0], r[l][0], r[j][1], r[l][1]));
            }

            printf("%lf  %lf  %lf  %lf  ", r[j][0], r[j][1], v[j][0], v[j][1]);
        }
        T = (2.0) * (Ek / (particulas));
        printf("%lf  %lf  %d %lf %lf\n", T, Ek, i + 1, Ep, Ep + Ek);
    }
}