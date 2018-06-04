#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  char firstFileName[64] = "ch15-ex4-input1.txt";
  char secondFileName[64] = "ch15-ex4-input2.txt";
  FILE *in1, *in2;
  char buffer1[63];
  char buffer2[63];

  if ( (in1 = fopen(firstFileName, "r")) == NULL ) {
    printf("Can't open %s for reading.\n", firstFileName);
  }

  if ( (in2 = fopen(secondFileName, "r")) == NULL ) {
    printf("Can't open %s for reading.\n", secondFileName);
  }

  while ( !(feof(in1) && feof(in2)) ) {
    fgets(buffer1, 63, in1);
    if ( !feof(in1) ) {
      fprintf(stdout, "%s", buffer1);
    }
    fgets(buffer2, 63, in2);
    if ( !feof(in2) ) {
      fprintf(stdout, "%s", buffer2);
    }
  }

  fclose(in1);
  fclose(in2);

  return 0;
}
