#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));

  double prevRand = 1.0;
  double prevrand = 1.0;

  for (double i = -1.0; i<= 1.0;  i += 0.05) {
    double random1 = (double)rand() / (double)RAND_MAX;
    double random2 = (double)rand() / (double)RAND_MAX;
    random1 = random1 * 2 -1;
    random1 += prevRand;
    prevRand = random1;
    random2 = random2 * 2 -1;
    random2 += prevrand;
    prevrand = random2;
    printf("%lf %lf %lf\n",i,random1,random2);
  }
  //double y = (double)rand()/RAND_MAX;

}
