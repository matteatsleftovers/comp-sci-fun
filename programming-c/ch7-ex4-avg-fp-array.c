// Function to calculate the average of an array of 10 floating point numbers

#include <stdio.h>

float average (float values[10])
{
  float averageValue, sum;
  int i;

  sum = values[0];

  for ( i = 1; i < 10; ++i )
    sum += values[i];

  averageValue = sum / 10;

  return averageValue;
}

int main (void)
{
  float values[10], averageValue;
  int i;
  float average (float values[10]);

  printf("Enter 10 floating point values\n");

  for ( i = 0; i < 10; ++i )
    scanf("%f", &values[i]);

  averageValue = average (values);
  printf("\nAverage value is %f\n", averageValue);

  return 0;
}
