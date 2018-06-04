#include <stdio.h>

#define   IS_UPPER_CASE(x)  ( ((x) >= 'A') && (x) <= 'Z' )

int main (void)
{
  char c;

  printf("Give me a character, please. I'll tell you if it is uppercase.\n");
  scanf("%c", &c);

  if (IS_UPPER_CASE(c)) {
    printf("\nYeah, that's definitely uppercase.\n");
  } else {
    printf("\nNG\n");
  }

  return 0;
}
