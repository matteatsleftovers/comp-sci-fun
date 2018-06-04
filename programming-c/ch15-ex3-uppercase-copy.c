#include <stdio.h>

#define   IS_LOWER_CASE(x)  ( ((x) >= 'a') && ((x) <= 'z') )

int main (void)
{
  char inName[64], outName[64];
  FILE *in, *out;
  int c;

  printf("Enter the name of the file to be copied: ");
  scanf("%63s", inName);
  printf("Enter the name of the output file: ");
  scanf("%63s", outName);

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
