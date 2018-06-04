#include <stdio.h>

#define   IS_UPPER_CASE(x)  ( ((x) >= 'A') && ((x) <= 'Z') )
#define   IS_LOWER_CASE(x)  ( ((x) >= 'a') && ((x) <= 'z') )
#define   IS_ALPHABETIC(x)  ( IS_UPPER_CASE(x) || IS_LOWER_CASE(x) )
#define   IS_DIGIT(x)       ( ((x) >= '0') && ((x) <= '9') )
#define   IS_SPECIAL(x)     ( !IS_ALPHABETIC(x) && !IS_DIGIT(x) )

int main (void)
{
  char c;

  printf("Give me a character, please. I'll tell you if it is special.\n");
  scanf("%c", &c);

  if (IS_SPECIAL(c)) {
    printf("\nYeah, that's definitely special, being non-alphabetic and non-digit.\n");
  } else if (IS_ALPHABETIC(c)) {
    printf("\nThat is not a special character. It's alphabetic.\n");
  } else {
    printf("\nThat is not a special character. It's a digit.\n");
  }

  return 0;
}
