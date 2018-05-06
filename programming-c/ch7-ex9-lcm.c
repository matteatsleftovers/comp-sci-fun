#include <stdio.h>

/* Function to find the greatest common divisor of two
nonnegative integer values and to return the result */

int gcd (int u, int v)
{
  int remainder;

  while ( v != 0 ) {
    remainder = u % v;
    u = v;
    v = remainder;
  }

  return u;
}

/* Function to find the least common multiple of to nonnegative integer values
and return the result */

int lcm (int u, int v)
{
  return u * v / gcd(u, v);
}

int main (void)
{
  int u, v, result, extraResult;

  printf("Enter 2 integers\n");

  scanf("%i", &u);
  scanf("%i", &v);

  result = lcm (u, v);
  printf ("\nThe LCM is %i\n", result);
  extraResult = gcd (u, v);
  printf ("\n\n...Oh, and by the way, if you were curious, the GCD is %i\n", extraResult);

  return 0;
}
