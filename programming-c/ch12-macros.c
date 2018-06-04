#include <stdio.h>

#define   IS_UPPER_CASE(x)  ( ((x) >= 'A') && (x) <= 'Z' )
#define   IS_LOWER_CASE(x)  ( ((x) >= 'a') && (x) <= 'z' )
#define   IS_ALPHABETIC(x)  ( IS_UPPER_CASE(x) || IS_LOWER_CASE(x) )

int main (void)
{
  char c;

  printf("Give me a character, please. I'll tell you if it is alphabetic.\n");
  scanf("%c", &c);

  if (IS_ALPHABETIC(c)) {
    printf("\nYeah, that's definitely alphabetic.\n");
  } else {
    printf("\nNG\n");
  }

  return 0;
}
