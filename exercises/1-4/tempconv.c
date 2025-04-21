#include <stdio.h>

int main() {
  float celsius, fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("Celsius Fahrenheit\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius * (9.0/5.0) + 32;
    printf("%7.0f %10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
