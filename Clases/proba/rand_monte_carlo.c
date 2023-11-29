#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int numeros = 10000;
  double puntosDentro = 0.0;
  for(int i = 0; i< numeros; i++)
  {

    double x = (double)rand()/RAND_MAX;
    double y = (double)rand()/RAND_MAX;
    double resultado = sqrt(pow(x,2)+pow(y,2));

    if(resultado<=1)
    {
      puntosDentro += 1;
      printf("%lf %lf \n",x, y);
    }

  }
  double resultado = 4*(puntosDentro/numeros);
  //printf("Puntos dentor: %lf\n",puntosDentro);
  //printf("EL valor de pi es:%lf \n",resultado);
}
