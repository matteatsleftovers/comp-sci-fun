#include <stdio.h>

#define   IS_LOWER_CASE(x)  ( ((x) >= 'a') && ((x) <= 'z') )

int main (void)
{
  char inName[64] = "ch15-ex3-input.txt";
  char outName[64] = "ch15-ex3-output.txt";
  FILE *in, *out;
  int c;

  if ( (in = fopen(inName, "r")) == NULL ) {
    printf("Can't open %s for reading.\n", inName);
  }

  if ( (out = fopen(outName, "w")) == NULL ) {
    printf("Can't open %s for writing.\n", outName);
  }

  while ( (c = getc(in)) != EOF ) {
    if (IS_LOWER_CASE(c)) {
      c -= 32;
      putc(c, out);
    } else {
      putc(c, out);
    }
  }

  fclose(in);
  fclose(out);

  printf("File has been copied and changed to lowercase.\n");

  return 0;
}
